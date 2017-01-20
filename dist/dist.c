#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "splay.h"



int main(int argc, char *argv[]){
   	
	
	Tree *tree =NULL;
	GHashTable *time_table = g_hash_table_new(g_str_hash, g_str_equal);
	GHashTable *distance_table = g_hash_table_new(g_str_hash, g_str_equal);
	
	int obj_length = (int) strtol(argv[1], NULL, 10);
	//timestamp es el valor q se lee de la hashtable	
	unsigned int timestamp;
	unsigned int tmp=0;
	unsigned int reuse_dist=0;
	unsigned int num_obj=1;
	char *num_obj_str=(char*) malloc(15*sizeof(char)); 
	
	char *object= malloc((obj_length)*sizeof(char));

	char *time_table_value = (char*) malloc(15*sizeof(char));
	char *dist_table_value = (char*) malloc(15*sizeof(char));	
	char *reuse_dist_str = (char*) malloc(15*sizeof(char));
	char *tmp_str = (char*) malloc(15*sizeof(char));
	FILE *file;
	file = fopen(argv[2], "r");

	while(fgets(object, obj_length+2, file)!=NULL){
		object[11]='\0';	
		
		
		printf("Objeto #%7u: %12s \n", num_obj, object);
		snprintf(num_obj_str, 15*sizeof(char), "%u", num_obj);
		//DESDE AQUI SERIA LA FUNCION: unsigned int reuse-dist(obj,hashtable,tree, num_obj)
		time_table_value = g_hash_table_lookup(time_table, object);

		if(time_table_value==NULL){
				
			g_hash_table_insert(time_table, object,  num_obj_str);
			tree = insert(strtol(num_obj_str,NULL,10) ,tree);
			//En la tabla de distancioas de reuso, la clave de 0 equivaler a la clave 'infinito'
			
			dist_table_value = g_hash_table_lookup(distance_table, "0");
			if(dist_table_value==NULL){
				g_hash_table_insert(distance_table, "0",  "1");	
			}else{	
				reuse_dist = strtol(dist_table_value,NULL,10)	;
				reuse_dist++;	
				g_hash_table_insert(distance_table, "0",  num_obj_str);
			}
		}else{
			//Calculate reuse distance
			timestamp = strtol(time_table_value,NULL,10);
			reuse_dist = calc_distance(timestamp,tree);
			//Busquemos la distancia de reuso en la hashtable distance_table
			snprintf(reuse_dist_str, 15*sizeof(char), "%u", reuse_dist);
			dist_table_value = g_hash_table_lookup(distance_table, reuse_dist_str);
			
			if(dist_table_value==NULL){
				g_hash_table_insert(distance_table, reuse_dist_str, "1");
			}else{
				tmp = strtol(dist_table_value,NULL,10);
				tmp++;
				
				snprintf(tmp_str, 15*sizeof(char), "%u", tmp);
				g_hash_table_replace(distance_table, reuse_dist_str, tmp_str);
			}

			printf("%u \n", reuse_dist);
			//delete old timestamp from tree
			tree = delete(strtol(time_table_value,NULL,10) ,tree);
					
			//Insert new timestamp from tree
			tree = insert(strtol(num_obj_str,NULL,10) ,tree);
			g_hash_table_replace(time_table, object, num_obj_str);	


			
		}
		//HASTA AQUI DEBE DE SER LA FUNCION
		tmp_str = (char*) malloc(15*sizeof(char));
		num_obj_str=(char*) malloc(15*sizeof(char));
		object= (char*) malloc((obj_length)*sizeof(char));
		// num_obj++ solo debe pasar si se cumple la condicion hash(Li)% P <= T !!!!!!! 
		num_obj++;	
	}
	printf("\n\n");	
	printtree(tree, 2);

	printf("\n\n");	
	GHashTableIter iter;
	void *key, *value;
	
	g_hash_table_iter_init (&iter, time_table);
	while (g_hash_table_iter_next (&iter, &key, &value))
 	{
    		printf("Objeto: %7s; Valor: %5s \n", (char*)key, (char*)value);
  	}	

	printf("\n\n");
	
	GHashTableIter iter2;
	void *key2, *value2;
	
	g_hash_table_iter_init (&iter2, distance_table);
	while (g_hash_table_iter_next (&iter2, &key2, &value2))
 	{
    		printf("Distancia: %7s; Valor: %5s \n", (char*)key2, (char*)value2);
  	}
	
	return 1;
}

