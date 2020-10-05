#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// Size of array 
#define max 25

  

int a[max] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,15,16,17,18,19,20,21,22,23,25 }; 
int maxx;
int min;
void* minimum(void* arg) 
{ 
    int mins=a[0];
    int i;
    for (i = 0; i < max; i++) { 
        if (a[i] < mins) 
            mins = a[i];
    } 
    min=mins;
} 

 

void* maximum(void* arg) 
{ 
    int maxs=a[0];
    int i;
    for (i = 0; i < max; i++) { 
        if (a[i] > maxs) 
            maxs = a[i];
    } 
    maxx=maxs;  
} 
 


int main() 
{ 
    pthread_t thread1;
    pthread_t thread2;  
    pthread_create(&thread1, NULL, maximum, (void*)NULL); 
    pthread_create(&thread2, NULL, minimum, (void*)NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    printf("Maximum Element is : %d\n", maxx); 
    printf("Minimum Element is : %d\n", min); 
    return 0; 
} 
