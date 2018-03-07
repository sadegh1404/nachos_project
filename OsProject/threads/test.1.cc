//     Test Nonpreemptive Priority scheduling 
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest1
//      Nonpreemptive Priority scheduling  algorithm
//      Process  Burst Time(CBT)  Priority  Start Time(A.V)
//        P1         5                7           0
//        P2         19               5           0
//        P3         13               2           0
//        P4         7                8           0
//        P5         12               9           5
//----------------------------------------------------------------------


void ThreadTest1()
{
 
    int  numThreads = 5;
    int  startTime[] = {  0,  0,  0,  0,  5  };
    int  burstTime[] = {  5, 19,  13, 7, 12  };
    int   priority[] = {  7,  5,  2,  8,  9, };
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_PRIO_NP);

    
    printf("##########################################\n");
    printf(" Sadegh Ranjbar has created this files\n");
    printf("##########################################\n");
    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

