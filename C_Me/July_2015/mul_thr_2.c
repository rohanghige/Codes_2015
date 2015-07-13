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

// This program is for 2 threads
// Both try to replace some values of a array with some values
// (Read the program for more details)

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int MAX_LEN = 30;

	
typedef struct pav{
	int *a;
	int val;
	int lim;
}vada;


void *someWork(void *argss){
	
	vada *args = (vada *)argss;
	printf("\nMy work is being done for lim = %d\n", args->lim);
	//~ args->lim = 10000;
	
	int i;
	for(i = 0; i< args->lim; i++){
		*(args->a + i) = args->val;
		printf("%d \n",*(args->a + i));
	}
	return NULL;
}
// disp function for vada structure :D
void disp_vada(vada *tp){
	printf("\nShowing the vada structure\n");
	//~ printf("val = %d\n", tp->val);
	//~ printf("lim = %d\n", tp->lim);
	int i;
	for( i = 0; i < MAX_LEN; i++){
		printf("a[%d] = %d\n", i, *(tp->a + i));
	}
}

int main(){
	vada *chitale = malloc(sizeof(chitale));
	vada *halwai = malloc(sizeof(halwai));
	int i, arr[MAX_LEN];
	
	for(i = 0 ; i < MAX_LEN; i++){
		//~ arr[i] = i;
		arr[i] = 10000;
	}
	chitale->a = arr;
	halwai->a = arr;
	chitale->val = 12;
	halwai->val = 5;
	chitale->lim = 12;
	halwai->lim = 18;
	
	//~ int *p = chitale->a;
	//~ printf("\nChecking before thread startss\n");
	//~ for(i = 0 ; i < MAX_LEN; i++){
		//~ printf("%d\n",*(p++));
	//~ }
	
	// 1st Thread
	pthread_t p_1, p_2;

	printf("\nChitale\n");
	disp_vada(chitale); // Before
	//~ printf("\nhalwai\n");
	//~ disp_vada(halwai); // Before	
	
	//~ pthread_create(&p_1, NULL, doSome, (void *)chitale);
	pthread_create(&p_1, NULL, someWork, (void *)chitale);
	pthread_create(&p_2, NULL, someWork, (void *)halwai);
	
	pthread_join(p_1, NULL);
	pthread_join(p_2, NULL);
	
	printf("\nChitale\n");
	disp_vada(chitale); // Before
	//~ printf("\nhalwai\n");
	//~ disp_vada(halwai); // Before	

}
