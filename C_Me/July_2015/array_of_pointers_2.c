#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
	int data;
	struct node *next;
} Node;

void disp_nodes(Node *start){
	printf("\n\nDisplaying the node details\n");
	int count = 0;
	while(start){
		printf("Node number: %d, data: %d\n", count, start->data);
		count++;
		start = start->next;
	}
}

void add_node(Node **arr){ // input: array of pointerse
	printf("Inside Adding function\n");
	Node *start = arr[0];
	Node *end = arr[1];
	printf("Before:%p:%p\n",start,end);
	
	// Preallocation of temp Node :D
	Node *temp = malloc(sizeof(temp));
	temp->data = 100;
	temp->next = NULL;
	//~ disp_nodes(temp);
	
	if(start){
		printf("Node is not empty\n");
		end->next = temp;
		end = temp;
	}
	else{
		printf("Node is empty\n");
		start = end = temp;
	}
	disp_nodes(start);
}

void change(int **mtv){
	//~ int i;
	//~ for(i=0;i<2;i++){
		//~ (*mtv[i])++;
	//~ }
	int *a = mtv[0];
	int *b = mtv[1];
	(*a)++;
	(*b)++;
}

int main(){
	int val[] = {1,2}, i;
	int *ptr[] = {&val[0],&val[1]};
	for(i=0;i<2;i++){
		printf("i=%d, val=%d\n",i,*ptr[i]);
	}
	printf("\n\n");
	change(ptr);
	for(i=0;i<2;i++){
		printf("i=%d, val=%d\n",i,*ptr[i]);
	}
	//~ 
	//~ int i;
	//~ for(i=0;i<3;i++){
		//~ printf("%d\n",val[i]);
		//~ printf("%d\n",*ptr++);
		//~ printf("%d\n",pptr[i]);
	//~ }
	
	//~ Node *front = NULL, *rear = NULL;
	//~ printf("%p:%p\n",front,rear);
	//~ Node *system[] = {front, rear}; // This becomes array of pointers :D
	//~ printf("%p:%p\n",system[0], system[1]);
	//~ 
	//~ disp_nodes(front);
	//~ add_node(system);
	//~ disp_nodes(front);
	return 0;
}
