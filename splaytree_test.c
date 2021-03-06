#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "splay.h"

int main(int argc, char *argv[]){

	char *rank_str = argv[1];
	int rank = strtol(rank_str, NULL,10);
	
	printf("The rank is %d. \n", rank);	
	
	Tree *tree =  NULL;
	tree = insert(2,tree);
	tree = insert(3,tree);
	tree = insert(7,tree);
	tree = insert(5,tree);
	tree = insert(6, tree);
	tree = insert(9, tree);
	
	tree = splay(5, tree);
	printtree(tree,3);
	rank_str = argv[2];
	int num_distancia = strtol(rank_str, NULL,10);
	int dist = calc_distance(num_distancia, tree);

	printf("%d \n", dist);
	/*	
	tree=find_rank(rank,tree);
	printtree(tree,10);
	*/
	return 1;	

}
