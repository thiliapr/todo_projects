#include "thcomp.h"

#define DEBUG true
#ifdef DEBUG
#include <stdio.h>
#include <time.h>
#define debug(code) code
#else
#define debug(code) ;
#endif

thmckey_t th_mccompress(uint8_t data_size, BYTE *data)
{
	//
	debug(
		uint64_t debug_use = time(NULL);
		uint8_t max_size = 0;
		)
	//
	for (uint32_t denominator = 3; denominator > 0; denominator += 2)
	{
		for (uint32_t numerator = 1; numerator < denominator; ++numerator)
		{
			//
			debug(
				if ((time(NULL) - debug_use) >= 2)
				{
					printf("a = %u, b = %u, ms = %u  \r", numerator, denominator, max_size);
					debug_use = time(NULL);
				}
				)
			//
			//define and init vars
			_Bool not_right_flag = 0;
			uint8_t cur_size = 0;
			uint64_t cur_numerator = numerator;
			//start to calc
			while (cur_size < data_size)
			{
				if ((cur_numerator *= 256) / denominator != data[cur_size])
				{
					not_right_flag = 1;
					break;
				}
				cur_numerator %= denominator;
				++cur_size;
			}
			//
			debug(
				max_size = max_size > cur_size ? max_size : cur_size;
				)
			//
			//if it is bigger than data
			if ((cur_numerator / denominator) > data[cur_size])
			{
				break;
			}
			//if it is not right
			if (not_right_flag)
			{
				continue;
			}
			//if it is right
			thmckey_t ret_val = {numerator, denominator};
			return ret_val;
		}
	}
	thmckey_t ret_val = {0, 0};
	return ret_val;
}