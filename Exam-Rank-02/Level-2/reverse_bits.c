/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

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

unsigned char	reverse_bits(unsigned char octet)
{
	return
	(
		((octet >> 7) & 1) |
		((octet >> 5) & (1 << 1)) |
		((octet >> 3) & (1 << 2)) |
		((octet >> 1) & (1 << 3)) |
		((octet << 1) & (1 << 4)) |
		((octet << 3) & (1 << 5)) |
		((octet << 5) & (1 << 6)) |
		((octet << 7) & (1 << 7))
	);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", reverse_bits(5));
// }