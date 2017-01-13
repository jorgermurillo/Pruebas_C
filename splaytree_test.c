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
	
	Tree *tree;
	Tree *tree2 = malloc(sizeof(struct Tree));
	tree2->right=NULL;
	tree2->left=NULL;
	tree2->size = malloc(sizeof(int));			
	tree2->key = malloc(sizeof(int));

	tree = insert(2, tree);
	tree = insert(8, tree);		
	tree = insert(4, tree);
	tree = insert(1, tree);
	tree = insert(5, tree);	

	printtree(tree,0);
	printf("\n\n\n");
	
	tree2 = splay(1,tree);

	//printtree(tree2,5);

	/*	
	tree=find_rank(rank,tree);
	printtree(tree,10);
	*/	

}
