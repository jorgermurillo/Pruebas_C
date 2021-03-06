#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "murmurhash3.h"
#include "splay.h"


//Aqui sacaremos el modulo del noveno byte del valor del hash (osea del primer byte del segundo
//uint64_t que regresa el hash.Esto se hara con el right shift operator.

int main(int argc, char *argv[]){
	/* La lista de argumentos:
				 
		argv[1] = Parametro T (Limite para aceptar una referencia del trace)
		argv[2] = longitud de los strings en el trace.
	*/

	Tree *tree = NULL;
	
	//GHashTable y Tree son usados para calcular la distancia de reuso
	GHashTable* tabla_tiempos = g_hash_table_new(g_str_hash,g_str_equal);
	
		
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
	file = fopen( argv[3], "r" );
	printf("SE ABRIO EL ARCHIVO!!! \n \n \n");
		
	char *str =  malloc((length_str+1)*sizeof(char));

		
	uint64_t  buffer[2];
	bool one;
	
	
	uint64_t shifted_value;	

	uint64_t T_i =0;

	char *valor=NULL;
	
	

	uint64_t tiempo_i = 1;
	uint64_t num_obj=1;
	char *num_obj_str;
	char *tiempo_i_str;	
	int distancia_reuso;	

	while( ( fgets(str , length_str+2 ,file))!=NULL ){
		
			num_obj_str = malloc( 20*sizeof(char) );
						
			snprintf(num_obj_str, 20*sizeof(char) ,"%"PRIu64"",num_obj);

			one = qhashmurmur3_128(str , length_str*sizeof(char) ,buffer);
			

			
			
			printf("Objeto %"PRIu64" : %s \n",tiempo_i, str);
			printf("Valor hash: \n");
			printf("%" PRIu64 " \n",buffer[0]);
			printf("%" PRIu64 " \n",buffer[1]);
			tiempo_i++;

			//shifted_value = buffer[1] >> 56;
			//shifted_value =  (buffer[1] >> (8*n)) & 0xff;

			shifted_value =  buffer[1];
			
			printf("Shifted value: \n");
			printf("%" PRIu64 " \n",shifted_value);
			
			
			
			//Chequeamos el modulo del hash 
			//T_i = shifted_value & (P-1)


			T_i = shifted_value % P;
			
			printf("Modulo: \n");
			printf("%" PRIu64 " \n",T_i);

			//Aqui se busca si el objeto leido esta en la tabla hash.
			
			if(T_i < T){	
				printf("Num de Obj Aceptado:: %"PRIu64 "\n",num_obj);	
				valor =(char*) g_hash_table_lookup(tabla_tiempos,str); 	
				if(valor==NULL){
					printf("Primera vez que esta referencia aparece \n");
					
					g_hash_table_insert(tabla_tiempos,str , num_obj_str);
					tree = insert(num_obj, tree);
					printf("La distancia de reuso es: 0 \n");
					printtree(tree, 2);
					

						
										
					
					
				}else{
					
					
					printf("EL valor de la hash table es: %s \n", valor);
					
					distancia_reuso  = calc_distance(strtol(valor, NULL,10),tree);
					tree = delete( strtol(valor, NULL,10), tree);
					tree = insert(num_obj, tree);
					printf("##La distancia de reuso es: %d \n", distancia_reuso);
					//Aqui se calcula la distancia de reuso
					printtree(tree,2);
					
					



					
					g_hash_table_replace(tabla_tiempos,str , num_obj_str);
					
					
										
				};
				
				
				num_obj++;
			}else{
				printf("Objeto no fue aceptado :( \n");
				
			}
			
			valor=NULL;
			num_obj_str = NULL;
			
			printf("\n");
			
			memset(str,0,(length_str+1)*sizeof(char));
			//str = (char*) malloc(length_str*sizeof(char));
				
		
		

	
		
	}

	


	return one;
}
