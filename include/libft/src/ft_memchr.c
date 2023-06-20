/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:21:40 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/10 16:46:35 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	{
		i = 0;
		str = (void *)s;
		while (i < n)
		{
			if (str[i] == (char)c)
				return (&str[i]);
			i++;
		}
		return (0);
	}	
}
