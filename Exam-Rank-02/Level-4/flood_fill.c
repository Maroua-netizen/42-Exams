/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------
Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is prototyped like this:
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0
1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
------------------------------------------------------------------------------*/

#include "flood_fill.h"

void fill(char **tab, t_point size, int row, int column, char old_char)
{

	if (row < 0 || row >= size.x || column < 0 || column >= size.y || tab[row][column] != old_char || tab[row][column] == 'F')
		return;
	tab[row][column] = 'F';
    fill(tab, size, row + 1, column, old_char);
    fill(tab, size, row - 1, column, old_char);
    fill(tab, size, row, column + 1, old_char);
    fill(tab, size, row, column - 1, old_char);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char old_char;

	old_char = tab[begin.x][begin.y];
	fill(tab, size, begin.x, begin.y, old_char);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void print_tab(char **tab)
// {
// 	int i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}	
// }

// char **make_area(char **tab, t_point size)
// {
// 	int i;
// 	char **area;

// 	area = calloc(size.x + 1, sizeof(char *));
// 	if (!area)
// 		return (NULL);
// 	i = 0;
// 	while (i < size.x)
// 	{
// 		area[i] = strdup(tab[i]);
// 		if (!area[i])
// 			return (NULL);
// 		i++;
// 	}
// 	return (area);
// }

// int main()
// {
// 	char **area;
// 	t_point size = {5, 8};
// 	t_point begin = {0, 0};
// 	char *tab[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 		NULL
// 	};
// 	printf("initial tab:\n");
// 	print_tab(tab);
// 	area = make_area(tab, size);
// 	flood_fill(area, size, begin);
// 	putchar('\n');
// 	printf("flood filled tab:\n");
// 	print_tab(area);
// }