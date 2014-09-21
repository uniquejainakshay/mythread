#include "mythread.h"

#define SECOND 10000

void thread_within()
{
	int i=0;
	while(1){
		printf("id :%d,  thread_within: %d\n",getID(), i++);
		if ( i == 10)
			suspend(0);
		if ( i == 130 ) 
			resume(0);
		usleep(SECOND);
	}
}
void f()
{
	int i=0, tid;
	while(1){
		printf("id :%d,  f: %d\n",getID(), i++);

		if ( i == 250 ) 
			break; 
		usleep(SECOND);
	}
}

void g()
{
	int i=0;
	int res = *(int *)GetThreadResult(1);
	printf("Result %d \n", res); 
	while(1){
		printf("id :%d,  g: %d\n",getID(), i++);
		if ( i == 50 ) 
			break; 
		usleep(SECOND);
	}
	clean();
}
typedef struct tp {
	int * arr; 
	int no; 
}xx;
void * func ( void * arg ){
	xx p = *((xx * ) arg); 
	int * sum ; 
	sum = (int * ) malloc ( sizeof ( int )) ;
	int i ; 
	for ( i =0 ; i < 0xfffffff; i++);

	for  ( i =0 ; i < p.no ; i++)
		*sum += p.arr[i];

	return sum;
}


main()
{


	xx p ; 
	int arr[] = {1 , 2 , 3 , 4 , 5};
	p.arr = arr; 
	p.no = 5; 
	

	//int tid0 = create(f);
	int tid1 = create(g);

	int t1 = createWithArgs(func, &p);
	start();
}
