/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/01 18:06:39 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 20:56:02 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_args(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("pipex: Too few arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
		error_msg();
}

void	error_msg(void)
{
	perror("pipex");
	exit(EXIT_FAILURE);
}

void	error_file(char **argv)
{
	if (access(*argv, F_OK) == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(*argv, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	else if (access(*argv, X_OK) == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(*argv, STDERR_FILENO);
		ft_putstr_fd(": permission denied\n", STDERR_FILENO);
	}
	exit(1);
}

void	error_cmd(char **cmd)
{
	int	i;

	ft_putstr_fd("pipex: ", STDERR_FILENO);
	i = 0;
	while (cmd[i])
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd(cmd[i], STDERR_FILENO);
		i++;
	}
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free_arr(cmd);
	exit(127);
}

void	error_here_doc(int argc)
{
	if (argc < 6)
	{
		ft_putstr_fd("pipex: Too few arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else
		error_msg();
}
