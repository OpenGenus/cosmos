/*
 * Part of Cosmos by OpenGenus Foundation.
 * Determine if the machine is in Little Endian or Big Endian.
 */

#include <stdio.h>
#include <stdint.h>

int 
main()
{
	/* i = 0x00 01 
	   In big endian, stored as : 0x00 01 
	   In little endian, stored as : 0x01 00 */
	uint16_t i = 1;
	
	/* x points to the first byte of i */
	uint8_t* x = (uint8_t*)&i;

	/* First byte is 0x01 */
	if (*x)
		printf("Little Endian\n");
	
	/* First byte is 0x00 */
	else
		printf("Big Endian\n");

	return (0);
}
