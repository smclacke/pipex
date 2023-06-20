/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:13:01 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/10 16:46:43 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = ((unsigned char *)dst);
	ptr2 = ((unsigned char *)src);
	while (n-- > 0 && (ptr1 || ptr2))
		*(ptr1++) = *(ptr2++);
	return (dst);
}
