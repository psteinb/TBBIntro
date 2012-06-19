#define _SIMPLE_CC_
#include <iostream>
#include "boost/program_options.hpp"
#include "boost/thread.hpp"
#include "tbb/tbb.h"
#include "tbb/concurrent_vector.h"
#include <boost/random/variate_generator.hpp>
#include <boost/random.hpp>

namespace po = boost::program_options;

class Sum
{
  tbb::concurrent_vector<int>* inputData;

public:
  //constructor
  Sum( tbb::concurrent_vector<int>* _data ) : 
    inputData(_data),
    result(0.)
  {}

  //copy constructor
  Sum( const Sum& _rhs ) : 
    inputData(_rhs.inputData),
    result(0.)
  {}
  
  //special Copy constructor
  Sum( const Sum& _rhs, tbb::split ) : 
    inputData(_rhs.inputData),
    result(0.)
  {}

  void join(const Sum& _other){
    result += _other.result;
  }
  
  void operator()(const tbb::blocked_range<size_t>& r)  {

    int thisSum = result;

    tbb::blocked_range<size_t>::const_iterator rangeItr = r.begin();
    tbb::blocked_range<size_t>::const_iterator rangeEnd = r.end();
    for (;rangeItr!=rangeEnd; ++rangeItr)
     {
       thisSum+=inputData->at(rangeItr);
     }
    
    result = thisSum;
  }

  int result;

};

class Random
{
  tbb::concurrent_vector<int> * const inputData;
  

public:
    //constructor
  Random( tbb::concurrent_vector<int>* _data ) : 
    inputData(_data)
  {}
  
  void operator()(const tbb::blocked_range<size_t>& r) const {

    tbb::blocked_range<size_t>::const_iterator rangeItr = r.begin();
    tbb::blocked_range<size_t>::const_iterator rangeEnd = r.end();

    boost::random::mt19937_64 rng(42);
    boost::random::uniform_int_distribution<> uni_dist(1,6);
    boost::variate_generator<boost::random::mt19937_64&, boost::random::uniform_int_distribution<> > six(rng, uni_dist);

    
    for (;rangeItr!=rangeEnd; ++rangeItr)
     {
       inputData->at(rangeItr) = six();
     }
    
  }

};

void serialRandom(tbb::concurrent_vector<int>* _container){
  
  boost::random::mt19937_64 rng(42);
  boost::random::uniform_int_distribution<> uni_dist(1,6);
  boost::variate_generator<boost::random::mt19937_64&, boost::random::uniform_int_distribution<> > six(rng, uni_dist);

  for(int index = 0;index<_container->size();index++)
    _container->at(index) = six();

}

int serialSum(tbb::concurrent_vector<int>* _container){
  tbb::concurrent_vector<int>::const_iterator contItr = _container->begin();
  tbb::concurrent_vector<int>::const_iterator contEnd = _container->end();

  int value = 0;

  for(;contItr!=contEnd;++contItr)
    value += *contItr;

  return value;
}

int main(int argc, char* argv[])
{

  //////////////////////////////////////////////////////////////////////////////
  //DEFINE PROGRAM OPTIONS
  //for more information see 
  //http://www.boost.org/doc/libs/1_49_0/doc/html/program_options.html#id2499800
  short nMaxThreads = boost::thread::hardware_concurrency();

 po::options_description optDescription("Available Options");
   optDescription.add_options()
    ("help,h", "produce help message")
    ("nthreads,n",po::value<short>()->default_value(nMaxThreads),"number of threads to use")
     ("iterations,i",po::value<unsigned int>()->default_value(0),"number of iterations")
    ;

  po::variables_map varMap;
  po::store(po::parse_command_line(argc, argv, optDescription), varMap);
  po::notify(varMap);
 
  if (varMap.count("help")) {
    std::cout << optDescription << "\n";
    return 1;
  }
  //////////////////////////////////////////////////////////////////////////////
  //PRINT USER INFO
  short nThreads = varMap["nthreads"].as<short>();
  if(nThreads<1 || nThreads > nMaxThreads)
    nThreads = nMaxThreads;

  unsigned int nIterations = varMap["iterations"].as<unsigned int>();
  if(nIterations<1)
    nIterations = nThreads;

  tbb::concurrent_vector<int>* data = new tbb::concurrent_vector<int>(nIterations,0);
  
  std::cout << "running ";
  if(nThreads==1){
    std::cout << "serial version " << std::endl;
    serialRandom(data);
    std::cout << "sum is " << serialSum(data) << std::endl;
  }
  else{
    //////////////////////////////////////////////////////////////////////////////
    //DO PARALLEL FOR
    int grainsize = (nIterations/nThreads);
    std::cout << "parallel version with " << nThreads  << " threads, grainsize "<< grainsize << std::endl;
    Random rndWorker(data);
    tbb::parallel_for(tbb::blocked_range<size_t>(0,nIterations,grainsize),rndWorker);

    //////////////////////////////////////////////////////////////////////////////
    //DO PARALLEL REDUCE
    Sum sumWorker(data);
    tbb::parallel_reduce(tbb::blocked_range<size_t>(0,nIterations,grainsize),sumWorker);
    std::cout << "sum is " << sumWorker.result << std::endl;
  }
  
  std::cout << "Done." << std::endl;
  delete data;
  
  return 0;
}
