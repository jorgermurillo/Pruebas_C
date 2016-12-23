#include <stdio.h>
#include <stdlib.h>


typedef double stackElement;

int main(){
	
	stackElement *buffer1;
	buffer1 = malloc(4*sizeof(stackElement));

	buffer1[3]=8;

	printf("%3.2f \n", *(buffer1+3));
	free(buffer1);
	
	buffer1 = malloc(5*sizeof(stackElement));
	*(buffer1+4) = 7;
	
	printf("%3.2f \n", *(buffer1+4));
		
}
