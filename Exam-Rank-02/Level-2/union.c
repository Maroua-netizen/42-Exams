/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int	i;
	int j;
	int k;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			k = 0;
			while (k < i)
			{
				if (av[1][i] == av[1][k])
					break;
				k++;
			}
			if (k == i)
				write(1, &av[1][i], 1);
			i++;
		}
		j = 0;
		while (av[2][j])
		{
			k = 0;
			while (k < j)
			{
				if (av[2][j] == av[2][k])
					break;
				k++;
			}
			if (k == j)
			{
				i = 0;
				while (av[1][i])
				{
					if (av[2][j] == av[1][i])
						break;
					i++;
				}
				if (av[1][i] == '\0')
					write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
}