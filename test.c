#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include "splay.h"


int main (){

	GHashTable *t = g_hash_table_new_full(g_direct_hash,  g_direct_equal, NULL , ( GDestroyNotify )free);
	Tree *tree = NULL;
	tree = insert(9,tree);
	printtree(tree, 1);
	printf("\n\n\n");
	int *valor = malloc(sizeof(int));
	*valor =3;	
	
	int *valor2 =malloc(sizeof(int));
	*valor2 = 3;
	
	g_hash_table_insert(t,valor, tree );
	
	Tree *tree2 =NULL;

	tree2 = (Tree*) g_hash_table_lookup(t, valor2);
	printtree(tree2, 3);

}
