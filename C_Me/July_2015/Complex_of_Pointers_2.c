// More complex usage of pointers

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordinary(int ***koti){
	int *gadi = **koti;
	int i=0;
	for(i=0;i<3;i++){
		printf("i=%d, value=%d, add=%p\n",i,gadi[i],&gadi[i]);
	}
}

int main(){
	int val[] = {15,63,79};
	int *a,*b,*c;
	a = &val[0];
	b = &val[1];
	c = &val[2];
	
	int **pm[] = {&a,&b,&c}; // Array of pointers
	printf("The:%d\n",**pm[0]);
	printf("The:%d\n",**pm[1]);
	printf("The:%d\n",**pm[2]);
	printf("\npm is %p\n",pm);
	printf("pm points to %p\n",*pm);
	printf("pm points to a pointer which points to value %p\n",**pm);
	printf("value related to pm %d\n\n",***pm);
	ordinary(pm);
	return 0;
}
