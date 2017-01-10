#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "murmurhash3.h"

//Aqui sacaremos el modulo del noveno byte del valor del hash (osea del primer byte del segundo
//uint64_t que regresa el hash.Esto se hara con el right shift operator.

int main(int argc, char *argv[]){

	int length_str=11;
	FILE *file;
	printf("SE CREO EL ARCHIVO!!! \n");
	

	//file = fopen( "YouTube-Trace.dat", "r" );
	file = fopen( "prueba2.txt", "r" );
	printf("SE ABRIO EL ARCHIVO!!! \n");
		
	char *str =  malloc((length_str+1)*sizeof(char));

	
	int c;
	int cnt=0;

	//numero del byte (El 0 es el primero desde la izq.
	int n=7;	
		
	uint64_t  buffer[2];
	bool one;
	while((c = fgetc(file))!=EOF){
	uint64_t shifted_value;	
		
		
		
		if(c=='\n'){
			str[cnt]='\0';
			//Este print funciona por q todos los string tienen el mismo tamaño
			one = qhashmurmur3_128(str , length_str*sizeof(char) ,buffer);
			printf("Objeto: %s \n",str);
			printf("Valor hash: \n");
			
			//shifted_value = buffer[1] >> 56;
			shifted_value =  (buffer[1] >> (8*n)) & 0xff;
			//printf("%6" PRIu64 " \n",buffer[0]);
			
			printf("%" PRIu64 " \n",shifted_value);
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
