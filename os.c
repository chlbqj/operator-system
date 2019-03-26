/*
  輸入格式為 "./os 90 81 78 95 79 72 85"
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double avg;
int min;
int max;

typedef struct datastruct
{
    int size;
    int *values;
}datastruct;

void *avg_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    for(i = 0; i < sz; i++)
    {
        avg += (copy->values[i]);
    }                               //If I used double for avg it would have given 82.8571 which doesn't match the example output
    avg = (int)(avg / sz);          //Used cast to match example output given on instructions.
}

void *min_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    min = (copy->values[0]);
    for(i = 1; i < sz; i++)
    {
        if(min > (copy->values[i]))
        {
            min = (copy->values[i]);
        }
    }
}

void *max_func(void *ptr)
{
    datastruct * copy;
    copy = (datastruct *) ptr;

    int sz = copy->size;
    int i;

    max = copy->values[0];

    for(i = 1; i < sz; i++)
    {
        if(max < copy->values[i])
        {
            max = copy->values[i];
        }
    }
}

int main(int argc, char *argv[])
{
  const int num = argc-1;
  int i, copy[num];
  int  t1, t2, t3;
  pthread_t thread1, thread2, thread3;

  if(argc <= 1)
  {
    printf("請輸入多個整數\n");
    return 0;
	}

  for(i = 0; i < num; i++)
  {
    copy[i] = atoi(argv[i+1]);
  }

  datastruct ds = {num, copy};
  /* Create independent threads each of which will execute appropriate function*/
  t1 = pthread_create(&thread1, NULL, (void *) avg_func, (void *) &ds);
  t2 = pthread_create(&thread2, NULL, (void *) min_func, (void *) &ds);
  t3 = pthread_create(&thread3, NULL, (void *) max_func, (void *) &ds);
  /* Wait till threads are complete before main continues. */

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);

  printf("The average:  %g\n", avg);
  printf("The minimum:  %d\n", min);
  printf("The maximum:  %d\n", max);

  return 0;
}
