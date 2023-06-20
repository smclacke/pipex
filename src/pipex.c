/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:06:21 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 20:55:46 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	- check if the cmd exists
	- get the cmd path (cmd -> /cmd -> /bin/cat) and 
		check that the cmd is executable
	- call execve() which if successful will take over and once finished,
		returns to the parent
*/

void	run_cmd(char **envp, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = check_cmd(argv);
	path = ft_cmd_path(envp, cmd[0]);
	if (path && access(path, X_OK) == -1)
		error_access(path);
	if (execve(path, cmd, envp) == -1)
		error_space(argv);
}

/*
	- create pipe with write side (pipe[1]) and read side (pipe[0])
	- fork to child, if pid == 0, inside child process
	- fd = which each file descriptor is passed from the main
	- dup2() copies the fd STDIN/STDOUT
		STDOUT is copied to pipes[1]
		STDIN is copied to the file descritor given in main
	- close the pipes and fd
*/

int	child(char *argv, char **envp, int fd)
{
	pid_t	pid;
	int		pipes[2];

	if (pipe(pipes) == -1)
		error_msg();
	pid = fork();
	if (pid == -1)
		error_msg();
	if (pid == 0)
	{
		if (dup2(pipes[1], STDOUT_FILENO) == -1)
			error_msg();
		if (dup2(fd, STDIN_FILENO) == -1)
			error_msg();
		close_pipes(pipes);
		ft_close(fd);
		run_cmd(envp, argv);
	}
	ft_close(pipes[1]);
	ft_close(fd);
	return (pipes[0]);
}

/*
	- after returning to parent from child(), we use whatever was last read
		from child()
	- fork into the last_child, copy STDOUT to outfile and STDIN to infile
		both given in main
	- close in and out files (pipes are already closed)
*/

void	last_child(char *argv, char **envp, int infile, int outfile)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_msg();
	if (pid == 0)
	{
		if (dup2(outfile, STDOUT_FILENO) == -1)
			error_msg();
		if (dup2(infile, STDIN_FILENO) == -1)
			error_msg();
		ft_close(outfile);
		ft_close(infile);
		run_cmd(envp, argv);
	}
	ft_close(outfile);
	ft_close(infile);
}
