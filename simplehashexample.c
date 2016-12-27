#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int simplehash(int c);

int main(){
	
	int x = simplehash(203);
	printf("%3d \n",x);
		
	
	
}


int simplehash(int c){

	int hash = c %10;
	return hash;

}
