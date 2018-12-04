#include "pthreads.h"



int main(int argc, char* argv[])
{
	int task_count=0;

	//we take number of task from user as parameter.

	if(argv[1]!=NULL){
		task_count=atoi(argv[1]);
		printf("task_count = %d\n",task_count);
		Task_queue(task_count);
	}else{
		printf("You should enter task number as parameter.\n");
		return ERR;
	}

	return OK;
}
