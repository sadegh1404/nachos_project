// This switches among the various testcases...
#include <string.h>
#include <stdio.h>
#include "system.h"
#include "list.h"
#include "synch.h"
#include "testcase.h"

void ThreadTest(char *name) { 
  char *basename=strrchr(name,'/');


  if (basename!=NULL) // if there was a path to trim,
    name=basename+1;  // trim it (lose the '/' too).
  if (!strcmp(name,"nachos")) // from the name, deduce the test to run 
    ThreadTest0();            // and run it.
  else if (!strcmp(name,"FCSF"))
    ThreadTest0();
  else if (!strcmp(name,"NPP"))
    ThreadTest1();
  // else if (!strcmp(name,"test2"))
  //   ThreadTest2();
  else if (!strcmp(name,"SJF"))
    ThreadTest3();
  // else if (!strcmp(name,"test4"))
  //   ThreadTest4();
  else printf ("OOPS: I'm called %s ???\n",name);
}


//----------------------------------------------------------------------
// SimulateThreadWork
 //      Each thread has a loop whose size reflects the burst time of the
//      job
//----------------------------------------------------------------------

static void
SimulateThreadWork(int time)
{
    currentThread->Print();
    printf("Starting Burst of %d ", time);
    int counter = 0;
    stats->PrintElapsedTicks();
    while ( time-- ){ 
        interrupt->OneTick(); 
        currentThread->Print();
        printf("Still %d to go ", time);
        stats->PrintElapsedTicks();
        counter++;
    } 
    currentThread->Print();
    printf("Done with burst ");
    stats->PrintElapsedTicks();
}

//-------------------------------------------------------------------
// TestScheduler
//
//     Schedules each thread when it is time for it to arrive.
//
//------------------------------------------------------------------

void TestScheduler( int inBound )
{
    List<schedpair *> * procList = (List<schedpair *> *)inBound;
    static char name[] = "P1";
    int StartTime;
    int NextStartTime; 
 
    // fork any threads that are ready.
    while( (procList->SortedPeek(&StartTime) != NULL) && ( stats->totalTicks >= StartTime ) )
    {
       // Schedule it.
       schedpair * alpha = procList->SortedRemove(NULL);
       Thread *newOne = new Thread( name, alpha->prior );
       printf("Queuing thread %s at Time %d, priority %d\n", name, stats->totalTicks, alpha->prior );
       newOne->Fork( SimulateThreadWork, alpha->burst ); 
       delete alpha;
       name[1]++;
       // more work later so schedule yourself again.
       if( (procList->SortedPeek( &NextStartTime ) != NULL) && ( stats->totalTicks < NextStartTime) )
           interrupt->Schedule( TestScheduler, inBound, NextStartTime - stats->totalTicks, TimerInt );
    }
}
