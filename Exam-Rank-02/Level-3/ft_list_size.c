/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list *curr;

	i = 0;
	curr = begin_list;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	ft_list_size_recursive(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	return (1 + ft_list_size_recursive(begin_list->next));
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	t_list root;

// 	root.data = "abc";
// 	root.next = malloc(sizeof(t_list));
// 	root.next->data = "def";
// 	root.next->next = NULL;
// 	printf("%d\n", ft_list_size_recursive(&root));
// }