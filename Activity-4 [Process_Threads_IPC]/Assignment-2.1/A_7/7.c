/*7.Write a program to run few threads with different attributes (scheduling policy, scheduling priority, CPU affinity) */
#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <pthread.h>


void* funct(void* p){

printf("Thread 1 with RR Policy, Priority=3 affinity=0\n");

}

void* funct1(void* p){

printf("Thread 2 with FIFO Policy, Priority=1 affinity=1\n");

}
/*SCHED_FIFO*/
int main(){

struct sched_param schedparam,param;
 
schedparam.sched_priority = 3;
pthread_attr_t attr1,attr2;

pthread_t thread1,thread2;
cpu_set_t cpu,cpu1;

CPU_ZERO(&cpu);
CPU_SET(0,&cpu);
pthread_attr_init(&attr1);
pthread_attr_setschedpolicy(&attr1, SCHED_RR);
pthread_attr_setaffinity_np(&attr1, sizeof(cpu),&cpu);
pthread_attr_setschedparam(&attr1, &schedparam);
if(pthread_create(&thread1, &attr1,funct,NULL)!=0)
{
printf("Error creating a thread\n");
}




param.sched_priority = 1;
CPU_ZERO(&cpu1);
CPU_SET(1,&cpu1);
//CPU_SET(0,&cpu1); changes its turn each time you run becuase ofthe core of cpu usage.
pthread_attr_init(&attr2);
pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
pthread_attr_setaffinity_np(&attr2, sizeof(cpu1),&cpu1);
pthread_attr_setschedparam(&attr2, &schedparam);
if(pthread_create(&thread2, &attr2,funct1,NULL)!=0)
{
printf("Error creating a thread\n");
}
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_attr_destroy(&attr1);

pthread_attr_destroy(&attr2);

	return 0;
}

