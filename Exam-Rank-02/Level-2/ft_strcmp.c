/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((unsigned char) (s1[i] - s2[i]) > 0)
		return (1);
	if ((unsigned char) (s1[i] - s2[i]) < 0)
		return (-1);
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	printf("%d\n", ft_strcmp("\200", "\0"));
// }