#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "splay.h"

void insertar(Tree **t);

int main(){


	Tree *tree=NULL;
	
	tree = insert(3,tree);
	tree = insert(6,tree);
	printf("KQQ\n");
	insertar(&tree);
	printtree(tree, 2);
		
	return 1;

}

void insertar(Tree **t){
	printf("1\n");
	*t = insert(88,*t);
	printf("2\n");
}
