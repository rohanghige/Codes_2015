// Complex usage of pointers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void disp_arr(int *in){ // passing whole array by just reference of 
						// its base address
	int i=0;
	for(i=0;i<3;i++){
		printf("i=%d, value=%d, add=%p\n",i,in[i],&in[i]);
	}
}

void amaze(int **entry){
	int i=0;
	for(i=0;i<3;i++){
		printf("i=%d, value=%d, add=%p\n",i,*(*entry + i),(*entry + i));
	}
}

void awesome(int **dhag){
	int *uber = *dhag;
	int i=0;
	for(i=0;i<3;i++){
		printf("i=%d, value=%d, add=%p\n",i,uber[i],&uber[i]);
	}
}

int main(){
	int val[] = {15,63,79};
	
	int *prt = val; // base address of val array
	disp_arr(val); // val = base address of val array
	
	printf("++++++++\n");
	amaze(&prt);
	printf("========\n");
	awesome(&prt);
	return 0;
}
