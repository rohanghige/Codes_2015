// This is simple Queue implementation using Linked List in C
// 
// Note: fron and rear are global functions here

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} the_node;

the_node *front, *rear = NULL;

void show_queue(){
	the_node *temp = front;
	
	printf("The Que is:\n");
	while(temp){
		//printf("%d\n",front->data);
		printf("%x : %d\n",(unsigned int)temp, temp->data);
		temp = temp->next;
	}
}

void Enque(int x){
	printf("\nEntering in the Enque operation\n");
	the_node *temp = malloc(sizeof(temp));
	temp->data = x;
	temp->next = NULL;
	
	if(front == NULL && rear == NULL){ // Totally empty Queue
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Deque(){
	printf("\nEntering in the Deque operation\n");
	the_node *temp = front;
	if(front){
		printf("Atleast One element\n");
		if(front == rear){
			printf("Only one element\n");
			front = rear = NULL;
		}
		else{
			printf("More than one element\n");
			front = front->next;
		}
		free(temp);
	}
	else{
		printf("Sorry the queue is empty!\n");
	}
	printf("After Deque operations\n");
	show_queue();
}

int main(){
	printf("Hello World!\n");
	Enque(12);
	show_queue();
	Enque(100);
	show_queue();
	
	Deque();
	Deque();
	Deque();
	return 0;
}
