  #include <stdio.h>
  #include <semaphore.h>
  #include <stdlib.h>
  #include <pthread.h>
int MAXSIZE = 8;       
int stack[8];     
int top = -1;            
pthread_mutex_t produce_mutex;
pthread_mutex_t consume_mutex;

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
  pthread_mutex_lock(&produce_mutex);

   if(!isfull())
   {
   //printf("Enter the item to produce\n");
   scanf("%d",&item);
   produce(item);
   }
   printf("\n");
  //pthread_mutex_unlock(&produce_mutex);
   pthread_mutex_unlock(&consume_mutex);
}
void* cd(void* pp)
{
 pthread_mutex_lock(&consume_mutex);
   if(!isempty())
   {
   consume();
   }
   pthread_mutex_unlock(&produce_mutex);
}

int main() {
   // push items on to the stack 
   int item;
pthread_mutex_init(&produce_mutex,NULL);
pthread_mutex_init(&consume_mutex,NULL);
pthread_mutex_lock(&consume_mutex);
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
    pthread_mutex_destroy(&produce_mutex);
    pthread_mutex_destroy(&consume_mutex);
   return 0;
}

