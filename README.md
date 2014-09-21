My Thread Library

My thread is a user level thread library. That is, all the threads in a process are
mapped to single kernel thread ( similar to GNU pth library). The key ingredients of 
this threading library are the functions setjmp and longjmp used to store and restore
the contexts of the specific threads. 

We mock interrupt based scheduling of the threads. ualarm system call is used to 
generate SIGALRM signal at regular time intervals playing the role of timer 
interrupt to indicate that the burst of the thread is over. The signal handler 
registered for SIGALRM carries out the task of saving the context of the running 
thread and restoring the context of one of the threads eligible to be run next according 
to the scheduling policy from the thread queue. 


Usage : 

Simply include the file mythread.h in your .c file and you are good to go. 

Manual : 

int create(void ( * f) ( void )) :  Creates a new thread with the function pointer passed
as argument. Create returns the thread id of the thread. 

void start() : This starts the scheduler of the thread library which in turn fetches 
thread from the queue and starts the execution of the threds. 

int createWithArgs( (void * ) ( * f ) ( void * ) ) : This creates a thread which takes 
a function pointer to function which takes void * as argument and returns void * . 
Just like pthreads. 



Note : 

Please do not handle the SIGALRM signal in your code as this will lead to malfunctioning 
of the library 

