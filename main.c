#include "mythread.h"

#define SECOND 10000

void thread_infinite()
{
	int i=0;
	while(1){
		usleep(SECOND);
	}
}
void f()
{
	int i=0, tid;
	while(1){
		printf("id :%d,  f: %d\n",getID(), i++);

		tid = create(thread_infinite) ; 
		run(tid);

		if ( i == 100 ) 
			break; 
		usleep(SECOND);
	}
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
	for ( i =0 ; i < 0xffff; i++);

	for  ( i =0 ; i < p.no ; i++)
		*sum += p.arr[i];

	return sum;
}

void g()
{
	int i=0, count =0, previous = -1 ;
	int a[] = {1, 2, 3};
	xx p; 
	p.arr = a; 
	p.no = 3;
	while(1){
		int tid = createWithArgs(func, &p);
		create(thread_infinite);
		if ( previous != -1 ) 
			delete( previous);
		run(tid);
		previous = tid;
		int * res = ( int * ) GetThreadResult(tid);
		printf( " Result of tid : %d is %d \n",tid,  *res) ; 
		//print_stat(search_by_tid(thread_queue, tid));
		count++;
		if ( count == 250 ) 
			break;
	}
	clean();
}

main()
{


	xx p ; 
	int arr[] = {1 , 2 , 3 , 4 , 5};
	p.arr = arr; 
	p.no = 5; 
	

	//int tid0 = create(f);
	int tid1 = create(g);

	start();
}
