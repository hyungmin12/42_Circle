

/*
 *
 
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100

 */

unsigned char	reverse_bits(unsigned char octet)  //한 바이트를 거꾸로 바꾸라고했으니, unsigned char로 받는다.
{
	int i;
	unsigned char result;

	i = 8;
	result = 0;
	while (i > 0) // 8 비트이므로 8번
	{
		result = result * 2 + (octet % 2); 
		octet /= 2;
		i--;
	}
	return (result);
}



//test main
#include <unistd.h>

int	main(void)
{
	unsigned char c;

	c = '&';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
