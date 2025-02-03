/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char	*str;
	int		len;
	int 	i;

	len = 0;
	while (src[len])
		len++;
	str = malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <string.h>
// #include <stdio.h>

// int main()
// {
// 	char	str[] = "Hello World!";
// 	printf("%s\n", ft_strdup(str));
// }