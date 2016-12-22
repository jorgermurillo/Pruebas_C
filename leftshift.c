#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>


int main(){
	
	uint8_t x = 1;
	printf("%6" PRIu8 " \n",x);
	uint8_t y = x <<7 ;
	printf("%6" PRIu8 " \n",y);
	uint8_t z = y<<2;
	printf("%6" PRIu8 " \n",z);	
	
	
}



