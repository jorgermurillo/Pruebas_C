#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(){
	uint64_t buffer[2] = {4,12145};

	uint64_t c0 = 0ULL; //buffer[0];
	uint64_t c1 = 4ULL;//buffer[1];
	printf("%6" PRIu64 " \n",c0);
	printf("%6" PRIu64 " \n",c1);
}

