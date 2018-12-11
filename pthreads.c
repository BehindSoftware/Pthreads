#include "pthreads.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define mutex
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

// Initialize conditional variable
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;

void *task(){

	pthread_cond_wait(&cond_var,&mut);	//First of all, whole threads are idle

	while(Task_dequeue(&headPtr,&tailPtr,&task_node)!=ERR){		//If queue is not empty

	pthread_mutex_lock(&mut);

	do_list_process(&task_node);

	pthread_cond_signal(&cond_var);

	pthread_mutex_unlock(&mut);

	pthread_cond_wait(&cond_var,&mut);

	}

	pthread_cond_signal(&cond_var);		//Avoid deadlock

	pthread_exit(NULL);

}

int main(int argc, char* argv[])
{
	int task_count=0, thread_count=0, i=0;
	double accum;
	struct timespec requestStart, requestEnd;

	//we take number of task from user as parameter.
	thread_count = atoi(argv[1]);
	pthread_t tid[thread_count];

	if(argv[2]!=NULL){
		task_count=atoi(argv[2]);
		printf("task_count = %d\n",task_count);
		Task_queue(task_count);
	}else{
		printf("You should enter task number as parameter.\n");
		return ERR;
	}

	for(i=0; i<thread_count; i++)
	{
		pthread_create(&tid[i], NULL, task, NULL);
	}
	pthread_cond_broadcast(&cond_var);
	clock_gettime(CLOCK_REALTIME, &requestStart);

	for(i=0; i<thread_count; i++)
	{
		pthread_join(tid[i], NULL);
	}
	clock_gettime(CLOCK_REALTIME, &requestEnd);

	accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec ) / BILLION;

	printf("Total time spent %lf, for %d threads\n", accum, thread_count);

	//Kullanıcıdan thread sayısını al ve bu kadar thread oluştur. Oluşan threadleri wait ile beklet.

	//Task queue ile verilen parametre kadar task oluştur.

	//Task_queue lar oluşup bitince artık tüm threadleri condition broadcast ile uyandır.

	//Thread uyanınca queuedan bir task çekip işler ve waite geçer.

	//en son thread sayısına göre clock vericez
	return OK;
}
