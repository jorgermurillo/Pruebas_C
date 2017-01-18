int calc_distance(T timestamp, Tree t){

	int d = 0;
	
	for(;;){

		if(timestamp > t->key){
			t=t->right;			
		}else if(timestamp < t->key){
		
			d++;
			Tree *tmp = t->right;
			if(tmp != NULL){
				d = d + tmp->size;		
			};
			t=t->left;

		}else{
			Tree *tmp = t->right;
			if(tmp != NULL){
				d = d + tmp->size;		
			};
			return d;
		}		

	}

}
