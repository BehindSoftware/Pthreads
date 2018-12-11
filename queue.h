//#ifndef
//#define queue

#include <stdio.h>
#include <stdlib.h>

#define OK		0
#define ERR 	1

/* Struct for list nodes */
struct lst_node_s {
	int data;
	struct lst_node_s* next;
};

typedef struct lst_node_s Lst_node_s;
typedef Lst_node_s *LstNodePtr;

/* Struct for task nodes */
struct tsk_node_s {
	int task_num; //starting from 0
	int task_type; // insert:0, delete:1, search:2
	int value;
	struct tsk_node_s* next;
};

typedef struct tsk_node_s Tsk_node_s;
typedef Tsk_node_s *TskNodePtr;

Tsk_node_s task_node;

void printList( LstNodePtr currentPtr );
void find_and_deleteDuplicates(LstNodePtr *sPtr);
int do_list_process(Tsk_node_s *node);


/* List operations */
int Insert(LstNodePtr *sPtr, int value);
int Search(LstNodePtr *sPtr, int value);
int Delete(LstNodePtr *sPtr, int value);

/* Task queue functions */
void Task_queue(int n); //generate n random tasks for the task queue
void Task_enqueue(TskNodePtr *headPtr, TskNodePtr *tailPtr, Tsk_node_s *node); //insert a new task into task queue
int Task_dequeue(TskNodePtr *headPtr, TskNodePtr *tailPtr, Tsk_node_s *node); //take a task from task queue

//#endif
