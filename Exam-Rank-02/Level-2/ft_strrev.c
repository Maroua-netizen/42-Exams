/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

char    *ft_strrev(char *str)
{
	int len;
	int i;
	char c;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		c = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "Hello";
// 	printf("%s\n", ft_strrev(str));
// }