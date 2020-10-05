  #include <stdio.h>
  #include <semaphore.h>
  #include <stdlib.h>
  #include <pthread.h>
int MAXSIZE = 8;       
int stack[8];     
int top = -1;            
sem_t empty;
sem_t full;
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int consume() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   printf("The consumed item %d\n",data);
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int produce(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data; printf("The produced item %d\n",data);
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

void* pd(void* pp)
{ int item;
   sem_wait(&empty);
   if(!isfull())
   {
   //printf("Enter the item to produce\n");
   scanf("%d",&item);
   produce(item);
   }
   printf("\n");
   sem_post(&full);
}
void* cd(void* pp)
{
 sem_wait(&full);
   if(!isempty())
   {
   consume();
   }
   sem_post(&empty);
}

int main() {
   // push items on to the stack 
   int item;
   sem_init(&empty,0,MAXSIZE);
    sem_init(&full,0,0);
    pthread_t pro[8],con[8];
   printf("Enter the items to be produced and consumed of buffer 8\n ");
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
       sem_destroy(&empty);
    sem_destroy(&full);
   return 0;
}

