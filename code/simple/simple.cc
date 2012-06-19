#define _SIMPLE_CC_
#include <iostream>
#include <vector>
#include "boost/program_options.hpp"
#include "boost/thread.hpp"
#include "tbb/tbb.h"


namespace po = boost::program_options;

struct NumPrinter
{
   
  void operator()(const tbb::blocked_range<size_t>& r) const {
    tbb::blocked_range<size_t>::const_iterator rangeItr = r.begin();
    tbb::blocked_range<size_t>::const_iterator rangeEnd = r.end();
    
    for (;rangeItr!=rangeEnd; ++rangeItr)
     {
       std::cout << "iteration "<< rangeItr << std::endl;
     }

  }
};

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
    ;

  po::variables_map varMap;
  po::store(po::parse_command_line(argc, argv, optDescription), varMap);
  po::notify(varMap);
 
  //////////////////////////////////////////////////////////////////////////////
  //PRINT USER INFO

  std::cout << "running executable of " << __FILE__ << std::endl;
  short nThreads = varMap["nthreads"].as<short>();
  if(nThreads<1 || nThreads > nMaxThreads)
    nThreads = nMaxThreads;

  std::cout << "with " << nThreads  << " threads" << std::endl;
  
  //////////////////////////////////////////////////////////////////////////////
  //DO PARALLEL FOR
  tbb::parallel_for(tbb::blocked_range<size_t>(0,nThreads,1),NumPrinter(nThreads));
  
  std::cout << "Done." << std::endl;

}
