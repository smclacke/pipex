/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 18:53:23 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 21:43:22 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	- close one pipe at a time
		as opposed to both at once with close_pipes()
*/

void	ft_close(int var)
{
	if (close(var) == -1)
		perror("pipex");
}

/*
	- not sure how to create a failure for close()
		but good practice to protect close() anyway
*/

void	close_pipes(int *pipes)
{
	if (pipes)
	{
		if (close(pipes[0]) == -1)
			perror("pipex");
		if (close(pipes[1]) == -1)
			perror("pipex");
	}
}

int	error_access(char *path)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": permission denied\n", STDERR_FILENO);
	exit(126);
}

void	error_path(char *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	exit(127);
}

/*
	- depending on the file passed:
		write, create, append
		write, create, truncate
		read
	- files are passed from the main depending on whether it is 
		here_doc infile/outfile
		or else, just infile/outfile
	- in here_doc, the infile - here_doc where the 'infile' is read from STDIN
*/

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	if (file == -1)
		error_file(&argv);
	return (file);
}
