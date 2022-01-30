/*
 * Part of Cosmos by OpenGenus Foundation.
 * Determine if the machine is in Little Endian or Big Endian.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isBigEndian(uint16_t input) {
	//for example : if input = 0x0001, so it's stored as big endian. in little endian it'll be stored as 0x0100

	/* pointer to the first byte of input */
	uint8_t* Byte = (uint8_t*)&input;

	/* First byte is 0x01 */
	if (*Byte) return false;
	
	/* First byte is 0x00 */
	return true;
}

int main() {
	uint16_t input = 1;
	
	if(isBigEndian(input)) printf("Big Endian\n");
	else printf("Little Endian\n");

	return 0;
}
