/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 14:54:04 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 20:55:30 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	get_line(char **line)
{
	char	*buf;
	int		ret;
	char	c;
	int		i;

	ret = 0;
	i = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	ret = read(0, &c, 1);
	while (ret && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buf[i] = c;
		i++;
		ret = read(0, &c, 1);
	}
	buf[i] = '\n';
	buf[++i] = '\0';
	*line = buf;
	free(buf);
	return (ret);
}

/*
	- reads from get_line()
	- if LIMITER is passed, break and return to here_doc()
	- else, write to the write pipe[1] whatever is passed on STDIN
*/

static void	ft_read(char *limiter, int *pipes)
{
	char	*line;

	while (get_line(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ((ft_strlen(limiter) + 1) == ft_strlen(line)))
			break ;
		write(pipes[1], line, ft_strlen(line));
	}
	exit(EXIT_SUCCESS);
}

/*
	- here_doc: only works with 6+ arguments
		(./prog, here_doc, LIMITER, cmd, cmd, ..., outfile)
	- pipe to open write and read sides
	- fork, read becomes the child process
	- if in child process (read == 0), ft_read() to read from STDIN
		close read side of pipe
	- else, close write side and return read side to parent to handle cmds
*/

int	here_doc(char *limiter, int argc)
{
	pid_t	read;
	int		pipes[2];

	if (argc < 6)
		error_here_doc(argc);
	if (pipe(pipes) == -1)
		error_msg();
	read = fork();
	if (read == 0)
	{
		close(pipes[0]);
		ft_read(limiter, pipes);
	}
	ft_close(pipes[1]);
	return (pipes[0]);
}
