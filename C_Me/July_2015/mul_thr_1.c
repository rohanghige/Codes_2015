// Learning about multithreading from basics :D
// ref: http://www.geeksforgeeks.org/multithreading-c-2/

// Remember the makefile for this file
// Follow these instuctions if the makefile is not present. (or search on internet for help :D)
// open terminal and cd to this folder containing this file.
// do: nano makefile
// then write it makefile: 

// mul_thr_1: mul_thr_1.c
// 		gcc -o mul_thr_1 mul_thr_1.c -pthread  

// /* The last part is important for linking the "pthread" libraries :D */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int MAX_LEN = 20;

	
typedef struct pav{
	int *a;
	int val_1;
	int val_2;
	int lim_1;
	int lim_2;
}vada;


void *someWork(void *argss){
	printf("\nMy work is being done\n");
	vada *args = (vada *)argss;
	
	//~ args->lim_1 = 10000;
	
	int i;
	for(i = 0; i< args->lim_1; i++){
		*(args->a + i) = 0;
		printf("%d \n",*(args->a + i));
	}
	return NULL;
}
// disp function for vada structure :D
void disp_vada(vada *tp){
	printf("\nShowing the vada structure\n");
	printf("val_1 = %d\n", tp->val_1);
	printf("val_2 = %d\n", tp->val_2);
	printf("lim_1 = %d\n", tp->lim_1);
	printf("lim_1 = %d\n", tp->lim_2);
	int i;
	for( i = 0; i < MAX_LEN; i++){
		printf("a[%d] = %d\n", i, *(tp->a + i));
	}
}

int main(){
	vada *chitale = malloc(sizeof(chitale));
	int i, arr[MAX_LEN];
	
	for(i = 0 ; i < MAX_LEN; i++){
		arr[i] = i + 99;
	}
	chitale->a = arr;
	chitale->val_1 = 12;
	chitale->val_1 = 5;
	chitale->lim_1 = 14;
	chitale->lim_2 = 3;
	int *p = chitale->a;
	printf("\nChecking before thread startss\n");
	for(i = 0 ; i < MAX_LEN; i++){
		printf("%d\n",*(p++));
	}
	
	// 1st Thread
	pthread_t p_1;

	disp_vada(chitale); // Before
	
	//~ pthread_create(&p_1, NULL, doSome, (void *)chitale);
	pthread_create(&p_1, NULL, someWork, (void *)chitale);
	pthread_join(p_1, NULL);
	
	disp_vada(chitale); // After

}
