#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){

	int *a;
	int x =3;
	a = &x;
	
	printf("Value of x is: %3d \n", x);
	printf("Value of a is: %3d \n", *a);
	
	*a = 57;
	
	printf("Value of x is: %3d \n", x);
	printf("Value of a is: %3d \n", *a);

	x = 58;
	
	printf("Value of x is: %3d \n", x);
	printf("Value of a is: %3d \n", *a);
	
}

