// This programs gives some basic concepts behind the array of pointers to any data type.
// This includes array of pointers to "x-data type", which itself includes pointer data type.
// Read the program for more understaning :D

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	time_t t;
	srand((unsigned) time(&t));
	int MAX_LEN = 20, i;
	int MAX_VAL = 100;
	int rohan[MAX_LEN]; 	// Array of integers
	int *ktr[MAX_LEN]; 		// Array of pointers to "integers"
	int* *mtr[MAX_LEN]; 	// Array of pointers to "pointers to intergers"
	
	for(i=0;i<MAX_LEN;i++){
		rohan[i] = rand() % MAX_VAL;
		ktr[i] = &rohan[i];
		mtr[i] = &ktr[i];
		printf("%d:%x:%d\n",i,(int)*ktr[i],(int)*ktr[i]);
		printf("%d:%x:%d\n",i,(int)**mtr[i],(int)**mtr[i]);
	}
	return 0;
}
