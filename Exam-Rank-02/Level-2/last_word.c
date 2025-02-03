/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int	i;
	int start;

	if (ac == 2)
	{
		i = 0;
		start = 0;
		while (av[1][i])
		{
			if ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] != ' ' 
				&& av[1][i + 1] != '\t' && av[1][i + 1] != '\0')
				start = i + 1;
			i++;
		}
		while (av[1][start] && av[1][start] != ' ' && av[1][start] != '\t' 
			&& av[1][start] != '\0')
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}