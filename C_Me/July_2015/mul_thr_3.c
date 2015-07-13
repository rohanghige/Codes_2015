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
int INI_LEN = 20;
int ARR_LEN = 15;
int CUR_LEN = 25;	

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
 // ====================================================================
typedef struct poha{
	int *p;
	int LEN_CHG;
	int rep_val;
} upwas;

void disp_upwas(upwas *team){
	printf("Change in length = %d, replace value = %d\n",team->LEN_CHG, team->rep_val);
}

void *change_array( void *input){
	printf("\n\n=======Change in length operation begins======\n");
	upwas *team = (upwas *)input;
	
	team->p = realloc(team->p , (CUR_LEN + team->LEN_CHG)*sizeof(int));
	//~ CUR_LEN = CUR_LEN + team->LEN_CHG; // Modified length of array
	printf("Modified length of array = %d\n", CUR_LEN);
	int i;
	
	//--
	//~ if(team->LEN_CHG > 0){ // Increase in length
		//~ printf("Since increase in length: rep cal = %d\n", team->rep_val);
		//~ for( i = CUR_LEN - team->LEN_CHG; i < CUR_LEN; i++){
			//~ *(team->p + i) = team->rep_val;
		//~ }
	//~ }
	//~ else{ // Decrease in length
		//~ // No need to do anything :D
	//~ }
	//--
	
	//~ for(i = 0; i < CUR_LEN; i++){
		//~ printf("%d ",*(team->p + i));
	//~ }
	printf("\n__________________________________________________________________\n");
	return NULL;
}
// ====================================================================
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
	
	// =================================================================
	printf("\n\nTesting something else\n");
	int *b = malloc(sizeof(int)*INI_LEN);
	for(i = 0; i < INI_LEN; i++){
		b[i] = 65 + i;
		printf("%d\n",b[i]);
	}
	int *kk = b;
	int NEW_LEN = INI_LEN - 40;
	b = realloc(b ,sizeof(int)*NEW_LEN);
	
	printf("\n\nSo after freeing/adding some memory\n");
	if(NEW_LEN > INI_LEN){ // initializing array if long array is created
		for(i = INI_LEN; i < NEW_LEN; i++){
			b[i] = 1000;
		}
	}
	for(i = 0; i < NEW_LEN; i++){
		printf("%d\n",b[i]);
	}
	
	// =================================================================
	printf("\n\n=======================Lets have UPWAS====================================\n");
	int atm = 10; // Attempts for this continous operation :D
	
	int *ptr = malloc(sizeof(int)*CUR_LEN);
	for(i = 0; i < CUR_LEN; i++){
		ptr[i] = 0 + i;
	}
	
	upwas *item_1 = malloc(sizeof(upwas));
	upwas *item_2 = malloc(sizeof(upwas));

	item_1->LEN_CHG = -3; // This will reduce size
	item_2->LEN_CHG = 5; // This will increase size
	
	item_1->rep_val = 123;
	item_2->rep_val = 479;
	
	item_1->p = ptr;
	item_2->p = ptr;
	
	disp_upwas(item_1);
	disp_upwas(item_2);
	
	printf("\n\nBefore thread operation, Array length = %d\n", CUR_LEN);
	for(i = 0; i < CUR_LEN; i++){
		printf("%d ",ptr[i]);
	}
	printf("\n\n");
	pthread_t day_1, day_2;
	
	//~ while(atm){
	for(i = 0; i < atm; i++){
		printf("--------------------Attempt #%d-----------------\n",10-atm);
		pthread_create(&day_1, NULL, change_array, (void *)item_1);
		pthread_create(&day_2, NULL, change_array, (void *)item_2);
		pthread_join(day_1, NULL);
		
		//~ printf("\n\nAfter thread operation, Array length = %d\n", CUR_LEN);
		//~ for(i = 0; i < CUR_LEN; i++){
			//~ printf("%d ",ptr[i]);
		//~ }
		printf("\n\n");
		//~ atm--;
	}
	
	
}
