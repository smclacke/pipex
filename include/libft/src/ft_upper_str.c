/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_upper_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/22 22:13:52 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/22 22:18:38 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_upper_str(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
