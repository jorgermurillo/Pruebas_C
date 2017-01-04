//#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "murmurhash3.h"

int main(){

	int length_str=11;
	FILE *file;
	printf("SE CREO EL ARCHIVO!!! \n");
	

	//file = fopen( "YouTube-Trace.dat", "r" );
	file = fopen( "prueba2.txt", "r" );
	printf("SE ABRIO EL ARCHIVO!!! \n");
		
	char *str =  malloc((length_str+1)*sizeof(char));

	
	int c;
	int cnt=0;


	uint64_t  buffer[2];
	bool one;
	while((c = fgetc(file))!=EOF){
		
		
		
		
		if(c=='\n'){
			str[cnt]='\0';
			//Este print funciona por q todos los string tienen el mismo tamaño
			one = qhashmurmur3_128(str , length_str*sizeof(char) ,buffer);
			printf("Objeto: %s \n",str);
			printf("Valores hash: \n");
			printf("%6" PRIu64 " \n",buffer[0]);
			printf("%6" PRIu64 " \n",buffer[1]);
			printf("\n");
			str[0]='\0';
			//str = (char*) malloc(length_str*sizeof(char));
			cnt =0;	
		}else{
			str[cnt]=c;
			cnt++;
		}	
		

	
		
	}

	



}
