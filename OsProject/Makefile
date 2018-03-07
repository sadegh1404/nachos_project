
# This file modify by Sadegh Ranjbar in 2017 
# All Right Reserved 
MAKE = make

all: 
	cd threads; $(MAKE) depend
	cd threads; $(MAKE) nachos
	mv threads/nachos ./nachos
	ln nachos FCSF
	ln nachos NPP
#	ln nachos test2
	ln nachos SJF
#	ln nachos test4
# don't delete executables in "test" in case there is no cross-compiler
clean:
	/bin/sh -c "rm -f */{core,nachos,test0,test1,test2,test3,test4,DISK,*.o}"
	rm nachos FCSF NPP SJF 


