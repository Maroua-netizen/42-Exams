/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int n;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (ft_isalpha(argv[1][i]) == 1)
				n = argv[1][i] - 'a' + 1;
			else if (ft_isalpha(argv[1][i]) == 2)
				n = argv[1][i] - 'A' + 1;
			else
				n = 1;
			while (n)
			{
				write(1, &argv[1][i], 1);
				n--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}