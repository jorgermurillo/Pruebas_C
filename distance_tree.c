#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "splay.h"

int main(int argc, char *argv[]){
		
	Tree *tree = NULL;
	
	//GHashTable y Tree son usados para calcular la distancia de reuso
	GHashTable* tabla_tiempos = g_hash_table_new(g_str_hash,g_str_equal);
	
	//Aqui se va a guardar el histograma de las distancias de reuso
	GHashTable* distancias = g_hash_table_new(g_str_hash,g_str_equal);
	
	int length_str=(int) strtol(argv[1], NULL, 10);
	
	FILE *file;
	
	uint64_t cnt_dist_reuso = 0;
	
	uint64_t distancia_reuso =0;
	char* dist_str = malloc(10*sizeof(char));
	file = fopen( argv[2], "r" );
	char *str =  malloc((length_str+1)*sizeof(char));
	char *valor=NULL;
	char *valor_dist=NULL;	
	
	//FILE *file2  = fopen( argv[3], "w" );

	uint64_t num_obj=1;
	char *num_obj_str;

	while( ( fgets(str , length_str+2 ,file))!=NULL ){
		
		printf("Objeto #%6"PRIu64": %12s", num_obj, str);
		num_obj_str = malloc( 20*sizeof(char) );
		snprintf(num_obj_str, 20*sizeof(char) ,"%"PRIu64"",num_obj);
		
		//Buscar el objeto en la hash-table 	
		valor =(char*) g_hash_table_lookup(tabla_tiempos,str); 
		

		if(valor==NULL){
				printf("Primera vez que esta referencia aparece \n");
					
				g_hash_table_insert(tabla_tiempos,str , num_obj_str);
				tree = insert(num_obj, tree);
				printf("La distancia de reuso es: 0 \n\n");
					
					

						
										
					
					
		}else{
					
					
				printf("Esta referencia ya aparecio!!\n");	
				
				distancia_reuso  = calc_distance(strtol(valor, NULL,10),tree);
				snprintf(dist_str, 20*sizeof(char) ,"%"PRIu64"",distancia_reuso);
				tree = delete( strtol(valor, NULL,10), tree);
				tree = insert(num_obj, tree);
				printf("## La distancia de reuso es: %"PRIu64 " \n\n", distancia_reuso);
				valor=NULL;
								
				valor_dist = g_hash_table_lookup(distancias, dist_str);
				// valor==NULL significa que es la primera vez que se encuentra esa distancia de reuso

				if(valor_dist==NULL){
					
					g_hash_table_insert(distancias,dist_str, "1");				
				}else{
					cnt_dist_reuso = (int) strtol(valor_dist, NULL, 10);
					cnt_dist_reuso++;
					
					
					snprintf(valor_dist, 20*sizeof(char) ,"%"PRIu64"",cnt_dist_reuso);
					g_hash_table_replace(distancias ,dist_str ,valor);
						
				}

				
				g_hash_table_replace(tabla_tiempos,str ,num_obj_str);
					
					
										
		}
		num_obj++;
	
		valor=NULL;
		num_obj_str = NULL;
		memset(str,0,(length_str+1)*sizeof(char));	
	
	}
	
	printf("\n\n\n Aqui ya termino el calculo de distancias de reuso \n\n\n");
	
	
	GHashTableIter iter;
	void *key, *value;
	
	g_hash_table_iter_init (&iter, distancias);
	while (g_hash_table_iter_next (&iter, key, value))
 	{
    		printf("Distancia: %s; Valor: %5s", key, value);
  	}
		


}
