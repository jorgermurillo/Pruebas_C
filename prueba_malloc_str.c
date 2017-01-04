#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	char *str = NULL;
	str = malloc(sizeof(char)* 5);
	strcpy(str, "Hello");
	printf("%s \n", str);
	str[0]='h';
	
	printf("%s \n", str);
	free(str);
	printf("%s \n", str);
	str="123456789";
	printf("%s \n", str);

}
