/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 15:48:06 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/09 12:17:45 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putchar_lower(int c)
{
	if (c == 58)
		write(1, "a", sizeof(char));
	else if (c == 59)
		write(1, "b", sizeof(char));
	else if (c == 60)
		write(1, "c", sizeof(char));
	else if (c == 61)
		write(1, "d", sizeof(char));
	else if (c == 62)
		write(1, "e", sizeof(char));
	else if (c == 63)
		write(1, "f", sizeof(char));
	else
		write(1, &c, sizeof(char));
	return (1);
}

int	putchar_upper(int c)
{
	if (c == 58)
		write(1, "A", sizeof(char));
	else if (c == 59)
		write(1, "B", sizeof(char));
	else if (c == 60)
		write(1, "C", sizeof(char));
	else if (c == 61)
		write(1, "D", sizeof(char));
	else if (c == 62)
		write(1, "E", sizeof(char));
	else if (c == 63)
		write(1, "F", sizeof(char));
	else
		write(1, &c, sizeof(char));
	return (1);
}

int	print_nbr(long long n, int base)
{
	int	i;

	i = 0;
	if (n < 0 && base == 10)
	{
		n *= -1;
		i += write (1, "-", sizeof(char));
	}
	if (n >= base)
		i += print_nbr(n / base, base);
	i += putchar_lower((n % base) + '0');
	return (i);
}

int	print_nbr2(unsigned long long n, unsigned int base)
{
	int		i;

	i = 0;
	if (n >= base)
		i += print_nbr2(n / base, base);
	i += putchar_upper((n % base) + '0');
	return (i);
}

int	print_p(unsigned long long n, unsigned int base)
{
	int	i;

	i = 0;
	if (n >= base)
		i += print_p(n / base, base);
	i += putchar_lower((n % base) + '0');
	return (i);
}
