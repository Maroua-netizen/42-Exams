/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	    is_power_of_2(unsigned int n)
{
	int i;

	i = 2;
	while (i < n)
		i *= 2;
	if (i == n)
		return (1);
	return (0);
}

//the function below is a solution to the same problem using bitwise operators
int	    is_power_of_2_bits(unsigned int n)
{
	int count;

	count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	if (count == 1)
		return (1);
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", is_power_of_2_bits(6));
// }