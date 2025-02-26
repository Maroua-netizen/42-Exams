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

int	wordcount(char *str)
{
	int count = 0;
	int i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
		(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

char	*get_next_word(char *str)
{
	char	*next_word;
	static int	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	int j = i;
	while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
		j++;
	int len = j - i;
	next_word = malloc(len + 1);
	if (!next_word)
		return (NULL);
	next_word[len] = '\0';
	int k = 0;
	while (i < j)
	{
		next_word[k] = str[i];
		i++;
		k++;
	}
	return (next_word);
}

char    **ft_split(char *str)
{
	char	**splited = malloc((wordcount(str) + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	splited[wordcount(str)] = NULL;
	int i = 0;
	while (i < wordcount(str))
	{
		splited[i] = get_next_word(str);
		i++;
	}
	return (splited);
}

// #include <stdio.h>

// int main()
// {
// 	char str[] = "  this is a \nsplit test !\t";
// 	char **splited = ft_split(str);
// 	int i = 0;
// 	while (splited[i])
// 	{
// 		printf("%s\n", splited[i]);
// 		i++;
// 	}
// }