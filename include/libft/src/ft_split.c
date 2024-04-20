/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 16:31:47 by smclacke      #+#    #+#                 */
/*   Updated: 2024/04/20 16:25:34 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	unsigned int	i;
	int				words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_letters(char const *s, char c, char **arr)
{
	unsigned int	b;
	unsigned int	e;
	int				words;

	b = 0;
	words = 0;
	while (s[b] && words < ft_words(s, c))
	{
		e = 0;
		while (s[b] == c)
			b++;
		while (s[b + e] != c && s[b + e] != '\0')
			e++;
		arr[words] = ft_substr(s, b, e);
		if (!arr[words])
		{
			ft_free(arr, ft_words(s, c));
			return (0);
		}
		b += e;
		words++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc((ft_words(s, c) + 1), sizeof(char *));
	if (!arr)
		return (0);
	if (!(ft_letters(s, c, arr)))
	{
		ft_free(arr, ft_words(s, c));
		return (NULL);
	}
	return (arr);
}
