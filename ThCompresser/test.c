#include "thcomp.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	BYTE data[] = "for test";
	uint8_t datasize = strlen(data) + 1;
	printf("start to compress, size = %u\n", datasize);
	thmckey_t k = th_mccompress(datasize, data);
	printf("\nresult: a = %u, b = %u\n", k.numerator, k.denominator);
	return 0;
}