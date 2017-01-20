
unsigned int calc_reuse_dist( char *object, unsigned int num_obj, GHashTable *time_table, Tree *tree){
	unsigned int timestamp=0;
	unsigned int reuse_dist=0;
	char* num_obj_str = (char*) malloc(15*sizeof(char)); 
	snprintf(num_obj_str, 15*sizeof(char), "%u", num_obj);
	
	char *time_table_value = g_hash_table_lookup(time_table, object);
	
	if(time_table_value==NULL){
				
				g_hash_table_insert(time_table, object,  num_obj_str);
				tree = insert(strtol(num_obj_str,NULL,10) ,tree);
				//En la tabla de distancioas de reuso, la clave de 0 equivaler a la clave 'infinito'
				reuse_dist = 0;
			
			
	}else{
				//Calculate reuse distance
				timestamp = strtol(time_table_value,NULL,10);
				reuse_dist = calc_distance(timestamp,tree);
				//Busquemos la distancia de reuso en la hashtable distance_table
				snprintf(reuse_dist_str, 15*sizeof(char), "%u", reuse_dist);
			
			
			

				printf("%u \n", reuse_dist);
				//delete old timestamp from tree
				tree = delete(strtol(time_table_value,NULL,10) ,tree);
					
				//Insert new timestamp from tree
				tree = insert(strtol(num_obj_str,NULL,10) ,tree);
				g_hash_table_replace(time_table, object, num_obj_str);	


			
	}
	
	return reuse_dist;


}
