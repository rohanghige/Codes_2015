// This is complex Queue implementation using Linked List in C
// 


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int MAX_VALUE = 1000000;

typedef struct Node{
	int data;
	struct Node *next;
} the_node;


void show_queue(the_node* front){
	the_node *temp = front;
	
	printf("The Que is:\n");
	int i=0;
	while(temp){
		printf("%d:: ",i);
		i++;
		//printf("%d\n",front->data);
		printf("%x : %d\n",(unsigned int)temp, temp->data);
		temp = temp->next;
	}
}

void Enque(the_node ***args, int *xx){
	the_node *na = **args;
	the_node *front = (the_node *)&na[0];
	the_node *rear = (the_node *)&na[1];
	printf("front = %d\n",front);
	printf("rear = %d\n",rear);
	int x = (int)*xx;
	printf("\nEntering in the Enque operation\n");
	//~ the_node* temp = malloc(sizeof(temp));
	the_node *temp = malloc(sizeof(the_node));
	temp->data = x;
	temp->next = NULL;
	printf("Temp alloted\n");
	printf("%d\n",temp->data);
	
	if(front == NULL && rear == NULL){ // Totally empty Queue
		printf("Previously empty\n");
		front = temp;
		rear = temp;
		printf("%d\n",front->data);
		printf("%d\n",rear->data);
		printf("Now filled :D\n");
		return;
	}
	else{
		printf("Queue was not fully empty :D\n");
	}
	rear->next = temp;
	rear = temp;
}

//~ void Deque(){
	//~ printf("\nEntering in the Deque operation\n");
	//~ the_node *temp = front;
	//~ if(front){
		//~ printf("Atleast One element\n");
		//~ if(front == rear){
			//~ printf("Only one element\n");
			//~ front = rear = NULL;
		//~ }
		//~ else{
			//~ printf("More than one element\n");
			//~ front = front->next;
		//~ }
		//~ free(temp);
	//~ }
	//~ else{
		//~ printf("Sorry the queue is empty!\n");
	//~ }
	//~ printf("After Deque operations\n");
	//~ show_queue();
//~ }

void tt(the_node ***poha){
	time_t t;
	srand((unsigned int) time(&t));
	
	the_node *temp = malloc(sizeof(temp));
	printf("Hi\n");
	temp->data = rand() % MAX_VALUE;
	temp->next = NULL;
	printf("Data=%d\n", temp->data);
	
	the_node *sig = *poha[1];
	if(sig){
		printf("In TT, extracted data = %d\n", sig->data);
		sig->next = temp;
		sig = temp;
	}
	else{
		printf("The pointer is NULL pointer\n");
		sig = temp;
	}
	
}

int main(){
	
	the_node* front = NULL;
	the_node* rear = NULL;
	printf("front = %d\n",front);
	printf("rear = %d\n",rear);
	
	the_node *roh = malloc(sizeof(roh));
	roh->data = 123;
	roh->next = NULL;
	the_node **args[] = {&roh, &rear};
	
	the_node *bh = **args;
	printf("After extracting: data = %d\n", bh->data);
	
	tt(args);
	sleep(3);
	tt(args);
	
	//~ the_node **args[] = {&front, &rear};
	//~ printf("front = %d\n",front);
	//~ printf("rear = %d\n",rear);
	//~ printf("Hello World!\n");
	//~ printf("front = %d\n",**args);
	//~ printf("rear = %d\n",**(args+1));
	printf("+=+\n");
	int a=12;
	//~ Enque(args, &a);
	//~ 
	//~ printf("+++++++++++++++\n");
	//~ printf("%d\n",front->data);
	//~ 
	//~ show_queue(front);
	//~ Enque(args, &a);
	//~ Enque(100);
	//~ show_queue();
	
	//~ Deque();
	//~ Deque();
	//~ Deque();
	return 0;
}
