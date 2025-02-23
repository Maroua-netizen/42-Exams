/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/

#include <stdlib.h>

int		wordcount(char *str);
char	*get_next_word(char *str);

char    **ft_split(char *str)
{
	char	**strs;
	int		len = wordcount(str);

	strs = malloc((len + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[len] = NULL;
	int	i = 0;
	while (i < len)
	{
		strs[i] = get_next_word(str);
		if (!strs[i])
		{
			i = 0;
			while (strs[i])
			{
				free(strs[i]);
				i++;
			}
			free(strs);
			return (NULL);
		}
		i++;
	}
	return (strs);
}

char	*get_next_word(char *str)
{
	static int	i = 0;
	char		*next_str;

	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	int	len = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		len++;
		i++;
	}
	int	last_i = i;
	next_str = malloc(len + 1);
	if (!next_str)
		return (NULL);
	next_str[len] = '\0';
	while (len - 1 >= 0)
	{
		next_str[len - 1] = str[last_i - 1];
		last_i--;
		len--;
	}
	return (next_str);
}

int		wordcount(char *str)
{
	int	count = 0;
	int	i = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' 
			&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

// #include <stdio.h>

// void	leaks()
// {
// 	system("leaks -q a.out");
// }

// int		main()
// {
// 	atexit(leaks);
// 	char	str[] = " Hello world!";

// 	char	**strs = ft_split(str);
// 	int	i = 0;
// 	while (strs[i])
// 	{
// 		printf("%s\n", strs[i]);
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// }
