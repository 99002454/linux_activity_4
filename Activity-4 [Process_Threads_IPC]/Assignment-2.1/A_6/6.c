#include <pthread.h>
#include<stdio.h>

#define MAX 25


#define MAX_THREAD 5


int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 }; 
int sum[5] = { 0 };
int part = 0;

void* sum_array(void* arg)
{


    int thread_part = part++;

    for (int i = thread_part * (MAX / 5); i < (thread_part + 1) * (MAX / 5); i++) 
        sum[thread_part] += a[i];
}


int main()
{

    pthread_t threads[MAX_THREAD];


    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);


    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);


    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];

  printf("%d\n",total_sum);

    return 0;
}
