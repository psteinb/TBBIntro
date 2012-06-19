CURRPATH	= $(abspath .)
CXXFLAGS       += -ggdb
SRCFILES	= $(wildcard *.cc)
TESTFILES	= $(wildcard *.tcc)
TESTEXECUTABLES	= $(patsubst %.tcc,%.texe,$(TESTFILES))
SOFILES		= $(patsubst %.cc,%.so,$(SRCFILES))
RFILES		= $(addprefix Rivet,$(SOFILES))
CXX		= g++


ifdef TBB_INC
	INCLUDES += -I$(TBB_INC)
	INCLUDES += -L$(TBB_LIB) -ltbb	
endif


ifdef BOOST_INC
	INCLUDES += -I$(BOOST_INC)
	INCLUDES += -L$(BOOST_LIB) -lboost_program_options -lboost_thread
endif


ifdef ROOTSYS
	INCLUDES += `root-config --cflags`
	INCLUDES += `root-config --glibs`
endif


%.exe : %.cc configured
	$(CXX) -x c++ $(CXXFLAGS) $(INCLUDES) $< -o $(CURRPATH)/$@

clean : 
	@echo -e "Cleaning directory"
	rm -f $(CURRPATH)/*.so $(CURRPATH)/*.exe $(CURRPATH)/*.texe 

configured :
	@if [ -z $(ROOTSYS) ] ; then echo -e "\n   !!!! ERROR: ROOT not set up properly!\n"; exit 1; fi
	@if [ -z $(TBB_INC) ] ; then echo -e "\n   !!!! ERROR: TBB not set up properly!\n"; exit 1; fi
	@if [ -z $(BOOST_INC) ] ; then echo -e "\n   !!!! ERROR: BOOST not set up properly!\n"; exit 1; fi

