/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 15:47:53 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/12 21:28:40 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

static int	print_string(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

static int	ft_eval_format(char *str, va_list valist)
{
	int	i;

	i = 0;
	if (*str == 'c')
		return (i += print_char(va_arg(valist, int)));
	else if (*str == 's')
		return (i += print_string(va_arg(valist, char *)));
	else if (*str == 'd' || *str == 'i')
		return (i += print_nbr(va_arg(valist, int), 10));
	else if (*str == 'u')
		return (i += print_nbr(va_arg(valist, unsigned int), 10));
	else if (*str == 'x')
		return (i += print_nbr(va_arg(valist, unsigned int), 16));
	else if (*str == 'X')
		return (i += print_nbr2(va_arg(valist, unsigned int), 16));
	else if (*str == 'p')
	{
		i += write(1, "0x", 2);
		return (i += print_p(va_arg(valist, long long), 16));
	}
	else if (*str == '%')
	{
		return (i += print_char('%'));
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	valist;

	i = 0;
	va_start(valist, (char *)str);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			i += ft_eval_format((char *)str, valist);
		}
		else if (*str != '%')
				i += write(1, str, 1);
		if (str)
			str++;
	}
	va_end(valist);
	return (i);
}
