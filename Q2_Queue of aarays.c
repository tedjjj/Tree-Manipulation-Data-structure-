/*Creating a queue where each element has a variable number of integers */
#include<stdio.h>
#include<stdlib.h>

#include"Operation_Queues_Q2.h"

void main()
{
	time_t t; // will be used to generate random numbers
	srand((unsigned) time(&t)); 
	Pointer_Q F;	// head and tail of the queue
	Typeelem_Q T,M,N;
	int size;
	
	Create_Queue(&F); 
	
	size= rand()%(15-1) + 1;
	
	T=malloc(sizeof(int)*(size));
	Read_1D(T,size);
	
	Enqueue(F,T,size);
	
	srand((unsigned) time(&t));
	
	size= rand()%(10-1) + 1;
	M=malloc(sizeof(int)*(size));
	Read_1D(M,size);
	
	Enqueue(F,M,size);
	
	Display_Queue(F);

	printf("DEQUEUE AN ARRAYA \n");
	Dequeue(F,&N,&size);
	printf("DISPLAYING THE DEQUEUED ARRAY \n");
	Write_1D(N,size);
	printf("DISPLAYING THE QUEUE  \n");
	Display_Queue(F);
}
