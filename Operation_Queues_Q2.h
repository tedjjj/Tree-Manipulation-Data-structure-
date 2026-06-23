#define True 1
#define False 0

typedef int* Typeelem_Q ;
typedef int bool;

typedef struct Queue * Pointer_Q ; // this type will be used to define the head and the tail of the queue
typedef struct Node_Q * PList_Q ; // this type will be used to define the node of the queue

#define True 1
#define False 0

struct Node_Q // We define the node 
{
Typeelem_Q Tab ; // pointer to the first cell of the dynamic array
int size ;	// the size of the array
PList_Q Next ;
};

struct Queue// We define the structure of the head and tail
{
PList_Q Head, Tail ;
};


void Create_Queue ( Pointer_Q *Fil )
{
*Fil = (struct Queue *) malloc( sizeof( struct Queue)) ;
(*Fil)->Head = NULL ;
(*Fil)->Tail = NULL ;
}


bool Empty_Queue (Pointer_Q Fil )
{ return Fil->Head == NULL ;} 


void Write_1D(Typeelem_Q Tab,int s)
{
	int i ;
	for(i=0;i<s;i++)
	printf("%d \t",Tab[i]);
	printf("\n");
}
void Read_1D(Typeelem_Q  Tab,int s)
{
	time_t t;
	srand((unsigned) time(&t));
	int i;
	
	printf("the size is %d \n", s);
	for (i=0;i<s;i++)
	{
		Tab[i]= rand()% 100; 
	}
	
}


void Enqueue ( Pointer_Q Fil , Typeelem_Q Tab ,int s)  // Insert a node at the tail of the queue
{
PList_Q Q; // A pointer to a node of queue 
Q = (struct Node_Q *) malloc( sizeof( struct Node_Q)) ; // Allocate a space for a node
Q->Tab = Tab ; 
Q->size=s;
Q->Next = NULL;
if ( ! Empty_Queue(Fil) ) 
Fil->Tail->Next = Q ; // Insert on the tail
else Fil->Head = Q; // else (first time enqueue ) attach Q to the head as well
Fil->Tail = Q; // designate Q as the new tail
}

void Dequeue (Pointer_Q Fil, Typeelem_Q *Val , int *s)
{
if (! Empty_Queue(Fil) ) // the queue must be non-empty
{
*Val = Fil->Head->Tab ;
*s= Fil->Head->size;
Fil->Head = Fil->Head->Next;
}
else printf ( "EMPTY QUEUE \n");
}

void Display_Queue(Pointer_Q Fil)
{
	PList_Q	iter;
	iter=Fil->Head;
	while(iter!=NULL)
	{
		printf("@Element= %p \t @Suiv= %p \t @Tab= %p \n",iter,iter->Next,iter->Tab);
		Write_1D(iter->Tab,iter->size);
		iter=iter->Next;
	}
}
/********************************************/



