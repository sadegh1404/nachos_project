//     SJF Algorithm
//
#include "system.h"
#include "list.h"
#include "testcase.h"

//----------------------------------------------------------------------
// ThreadTest3
//      SJF scheduling algorithm
//      Process  Burst Time(CBT)  Priority  Start Time(A.V)
//        P1         7                1	          0
//        P2         6                2	          1
//        P3         3                3 	        2
//        P4         1                4 	        2
//        P5         4                5 	        8
//----------------------------------------------------------------------

void ThreadTest3()
{

    int  numThreads = 5;
    int  startTime[] = { 0 , 1 , 2 , 2 , 8};
    int  burstTime[] = { 7 , 6 , 3 , 1 , 4 };
    int   priority[] = {  1 , 2 , 3, 4 ,5};
    schedpair * a_pair;

    List<schedpair *> * procList = new List<schedpair *>();

    for( int i = 0; i < numThreads; i++ ) {
       a_pair = new schedpair;
       a_pair->burst = burstTime[i];
       a_pair->prior = priority[i];
       procList->SortedInsert( a_pair, startTime[i] );
    }

    scheduler->SetSchedPolicy(SCHED_SJF);


    printf("##########################################\n");
    printf(" Sadegh Ranjbar has created this files\n");
    printf("##########################################\n");
    printf("Starting at ");
    stats->PrintElapsedTicks();
    printf("Queuing threads.\n");

    TestScheduler( ( int ) procList );
}

