/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	*arr;
	int	i;
	int	size;

	if (end >= start)
		size = end - start + 1;
	else
		size = start - end + 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (end >= start)
			arr[i] = start++;
		else
			arr[i] = start--;
		i++;
	}
	return (arr);
}

// #include <stdio.h>

// int main()
// {
// 	int i;
// 	int	*arr;

// 	arr = ft_range(0, -3);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// }
