#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

typedef int buffer_item;
#define BUFFER_SIZE 5

pthread_mutex_t mutex;
pthread_t t_prod[10],t_cons[10],t_test;
sem_t s_full,s_empty;
int count=0;
buffer_item buffer[BUFFER_SIZE];

void *producer(void *param) {
	printf("\nEnter the number to be produced : ");
	buffer_item item;
	scanf("%d",&item);
	sem_wait(&s_empty);
	pthread_mutex_lock(&mutex);
	printf("\nItem produced is %d\n",item);
	buffer[count++]=item;
	pthread_mutex_unlock(&mutex);
	sem_post(&s_full);
	pthread_exit(NULL);
}

void *consumer(void *param) {
	buffer_item item;
	sem_wait(&s_full);
	pthread_mutex_lock(&mutex);
	item=buffer[--count];
	printf("Item consumed is %d\n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&s_empty);
	pthread_exit(NULL);
}

int insert_item(buffer_item item) {
	/* insert item into buffer
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	for(int x=0; x < item; x++)
	{
		pthread_create(&t_prod[x],NULL,producer,NULL);
		sleep(3);
  	}
  	for(int x=0; x < item; x++)
  	{
  		pthread_join(t_prod[x],NULL);
  	}
}

int remove_item(buffer_item item) {
	/* remove an object from buffer
	placing it in item
	return 0 if successful, otherwise
	return -1 indicating an error condition */
	for(int x=0; x < item; x++)
  	{  
		pthread_create(&t_cons[x],NULL,consumer,NULL);
		sleep(1);
	}
	for(int x=0; x < item ;x++)
	{
		pthread_join(t_cons[x],NULL);
	}
}

int main (){
	sem_init(&s_full,0,0);
	sem_init(&s_empty,0,5);
	int i,j;
	printf("\nHow many items would you like to produce :  ");
	scanf("%d",&i);
	insert_item(i);
  	printf("\nHow many items woudld you like to consume :  ");
  	scanf("%d",&j);
	remove_item(j);
	return 0;
}
