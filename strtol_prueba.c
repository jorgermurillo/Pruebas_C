#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>


int main(){
	char* str = "123";
	char *endptr;
	uint64_t T = (uint64_t) strtol(str, &endptr, 10);
	printf("%6" PRIu64 " \n",T);

}
