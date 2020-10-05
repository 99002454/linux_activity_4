#include<stdio.h>
  #include <stdio.h>
  #include <semaphore.h>
  #include <stdlib.h>
  #include <pthread.h>
pthread_mutex_t produce_mutex;
pthread_mutex_t consume_mutex;
# define MAX 8
int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item);
 void deletion();
void* pd(void* pp)
{ int item;
 pthread_mutex_lock(&produce_mutex);
   //printf("Enter the item to produce\n");
   scanf("%d",&item);
   insert(item);
   printf("\n");
   pthread_mutex_unlock(&consume_mutex);
}
void* cd(void* pp)
{
 pthread_mutex_lock(&consume_mutex);
  deletion();
   pthread_mutex_unlock(&produce_mutex);
}

void insert(int item)
{
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
printf("Queue Overflow n");
return;
}
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
printf("Element Produced : %d\n",item);
}

void deletion()
{
if(front == -1)
{
printf("Queue Underflown");
return ;
}
printf("Element Consumed : %d\n",cqueue_arr[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
}


int main()
{
  int item;
pthread_mutex_init(&produce_mutex,NULL);
pthread_mutex_lock(&consume_mutex);
    pthread_t pro[8],con[8];
   printf("Enter the items to be produced and consumed of buffer 8\n ");
   //pthread_mutex_lock(&produce_mutex);
   //pthread_mutex_lock(&consume_mutex);
   for(int i = 0; i < 8; i++) {
    pthread_create(&pro[i], NULL, (void *)pd, NULL);
    }

     for(int i = 0; i < 8; i++) {
        pthread_create(&con[i], NULL, (void *)cd,NULL);
    }

     for(int i = 0; i < 8; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 8; i++) {
        pthread_join(con[i], NULL);
    }
       
return 0;
}
