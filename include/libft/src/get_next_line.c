/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 14:43:48 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/13 21:07:28 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next(char **mem, int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(*mem);
		return (NULL);
	}
	if (read_bytes == 0)
		return (*mem);
	buffer[read_bytes] = '\0';
	if (!*mem)
		*mem = gnl_strdup(buffer);
	else
		*mem = gnl_strjoin(*mem, buffer);
	if (gnl_strchr(*mem, '\n'))
		return (*mem);
	return (get_next(mem, fd));
}

char	*store_next(char **mem, size_t length)
{
	size_t	i;
	char	*line;

	i = gnl_strlen(*mem, '\0') - length;
	if (i == 0 || !gnl_strchr(*mem, '\n'))
	{
		free(*mem);
		return (NULL);
	}
	line = gnl_strdup(*mem + length);
	free(*mem);
	return (line);
}

char	*give_next(char **mem)
{
	char	*line;
	int		i;

	if (gnl_strchr(*mem, '\n'))
		i = gnl_strlen(*mem, '\n') + 1;
	else
		i = gnl_strlen(*mem, '\0');
	line = malloc((i + 1) * sizeof(char));
	if (!line)
	{
		free(*mem);
		return (NULL);
	}
	gnl_strlcpy(line, *mem, i + 1);
	*mem = store_next(mem, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*mem[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read (fd, 0, 0) < 0)
	{
		free(mem[fd]);
		mem[fd] = NULL;
		return (NULL);
	}
	mem[fd] = get_next(&mem[fd], fd);
	if (!mem[fd])
		return (NULL);
	line = give_next(&mem[fd]);
	return (line);
}
