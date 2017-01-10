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
	/* La lista de argumentos:
				
		argv[1] = Parametro T (Limite para aceptar una referencia del trace)
		argv[2] = longitud de los strings en el trace.
	*/

	GHashTable* tabla_tiempos = g_hash_table_new_full(g_str_hash,g_str_equal, free, free);
	char *endptr;	
	uint64_t T = (uint64_t) strtol(argv[1], NULL, 10);
	int length_str=(int) strtol(argv[2], NULL, 10);
	printf("Argumentos leidos!! \n");
	uint64_t  P = 1;
	P = P<<24;
	printf("%"PRIu64 " \n", P);

	//int length_str=11;
	//free(endptr);
		
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
	
	int tiempo_i = 1;
	uint64_t shifted_value;	

	uint64_t T_i =0;

	char *valor;
	int  valor_int;

	char *tiempo_i_str;	
	tiempo_i_str = malloc( 20*sizeof(char) );	

	while((c = fgetc(file))!=EOF){
		
		
		
		
		if(c=='\n'){
			str[cnt]='\0';
			//free(endptr);
			//Este print funciona por q todos los string tienen el mismo tamaño
			one = qhashmurmur3_128(str , length_str*sizeof(char) ,buffer);
			printf("Tiempo: %d \n",tiempo_i);			
			printf("Objeto: %s \n",str);
			printf("Valor hash: \n");
			printf("%" PRIu64 " \n",buffer[0]);
			printf("%" PRIu64 " \n",buffer[1]);
			

			//shifted_value = buffer[1] >> 56;
			//shifted_value =  (buffer[1] >> (8*n)) & 0xff;

			shifted_value =  buffer[1];
			
			printf("Shifted value: \n");
			printf("%" PRIu64 " \n",shifted_value);
			//printf("%6" PRIu64 " \n",buffer[0]);
			sprintf(tiempo_i_str,"%d",tiempo_i);
			tiempo_i++;
			//Chequeamos el modulo del hash 
			//T_i = shifted_value & (P-1);
			T_i = shifted_value % P;
			printf("Modulo: \n");
			printf("%" PRIu64 " \n",T_i);

			//Aqui se busca si el objeto leido esta en la tabla hash.
			
			if(T_i < T){	
				valor = g_hash_table_lookup(tabla_tiempos,str); 	
				if(valor==NULL){
					printf("Primera vez que esta referencia aparece \n");
					g_hash_table_insert(tabla_tiempos,str , tiempo_i_str);
					valor = g_hash_table_lookup(tabla_tiempos,str); 
					printf("%s \n", valor);
					
				}else{
					
					valor_int = (int)strtol(valor, NULL, 10);
					printf("EL valor de la hash table es: %2d \n", valor_int);
					//La sgte linea me genera un segmentation fault 					
					g_hash_table_insert(tabla_tiempos,str , tiempo_i_str);
										
				};
			}else{
				printf("Objeto no fue aceptado :( \n");
			}
			
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
