/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:27:22 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/10 16:46:49 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = ((unsigned char *)b);
	while (len-- > 0)
		*(ptr++) = ((unsigned char)c);
	return (b);
}
