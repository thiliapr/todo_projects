#include <stdint.h>

typedef uint8_t BYTE;
typedef struct
{
	uint32_t numerator, denominator;
} thmckey_t;

thmckey_t th_mccompress(uint8_t data_size, BYTE *data);