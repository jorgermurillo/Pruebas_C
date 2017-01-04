//#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

int main(){


	FILE *file;
	printf("SE CREO EL ARCHIVO!!! \n");
	//char *buff = (char*)malloc(sizeof(char));

	file = fopen( "YouTube-Trace.dat", "r" );
	printf("SE ABRIO EL ARCHIVO!!! \n");
		
	int c;
	while((c = fgetc(file))!=EOF){
		
		printf("%c",c);
	}


}
