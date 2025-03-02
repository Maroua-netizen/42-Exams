/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

unsigned int	ft_atoi(char *str)
{
	unsigned int	n = 0;
	int	i = 0;
	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

void	putnbr_hex(unsigned int n)
{
	char	str[16] = "0123456789abcdef";
	if (n >= 16)
		putnbr_hex(n / 16);
	char	c = str[n % 16];
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		putnbr_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}
