/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdlib.h>

int	mini_atoi(char *str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + str[i] - '0';
		else
			return (0);
		i++;
	}
	return (n);
}

int	is_prime(int n)
{
	int div;

	if (n < 2)
		return (0);
	div = 2;
	while (div <= n / 2)
	{
		if (n % div == 0)
			return (0);
		div++;
	}
	return (1);
}

void mini_putnbr(int n)
{
	char	c;

	if (n >= 10)
		mini_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int	arg;
	int	i;
	int	n;

	if (ac != 2)
	{
		write(1, "0\n", 2);
		exit(1);
	}
	arg = mini_atoi(av[1]);
	n = 0;
	i = 0;
	while (i <= arg)
	{
		if (is_prime(i))
			n += i;
		i++;
	}
	mini_putnbr(n);
	write(1, "\n", 1);
}
