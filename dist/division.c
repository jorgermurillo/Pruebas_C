#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(){
	
	uint64_t x = 1000;
	uint64_t y = 1000000;

	double z =x/(double)y;

	printf("%f \n", z);	

}
