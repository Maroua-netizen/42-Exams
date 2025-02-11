/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

int	my_strchr(char *str, char c, int str_base)
{
	int	i;

	i = 0;
	while (i < str_base)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		n;
	int		sign;
	int		i;
	char	stru[] = "0123456789ABCDEF";
	char	strl[] = "0123456789abcdef";
	int		u;
	int		l;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		u = my_strchr(stru, str[i], str_base);
		l = my_strchr(strl, str[i], str_base);
		if (u != -1)
			n = n * str_base + u;
		else if (l != -1)
			n = n * str_base + l;
		else
			return (0);
		i++;
	}
	return (n * sign);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("30", 5));
// }
