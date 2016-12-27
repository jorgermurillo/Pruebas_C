#include <stdio.h>

static void SwapInteger(int *p1, int *p2){

	int tmp;
	tmp = *p1;
	*p1 = *p2;	
	*p2 = tmp;

}

int main(){
	char* str = "Hola";

	int x = 32;
	int y = 54;
	
	int buffer[3];
	int *p;

	printf("X: %d",x);
	printf("Y: %d",y);
	
	SwapInteger(&x,&y);
	printf("X: %d",x);
	printf("Y: %d",y);
	
	buffer[0] = 10;
	buffer[1] = 11;
	buffer[2] = 12;

	p = &buffer[0];
	p=p++;
	
	int z = *p;
	printf("\n");
	printf("%d \n" , z);
	printf("%d \n" , *p);

	int *puntero = &buffer[2];
	p=puntero;
	printf("%d \n" , *p);
	printf("%s \n", str);
}

