/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */










// 11001010  >> 4

// 00001100

// 1101010 << 4 


// 10100000
// 00001100
//
// 1010 1100


unsigned char	swap_bits(unsigned char octet)
{
	return ( (octet >> 4) | (octet << 4) );
}







#include <unistd.h>

int		main(void)
{
	char c;

	c = 't';
	write(1, &c, 1);
	c = swap_bits(c);
	write(1, &c, 1);
	return (0);
}
