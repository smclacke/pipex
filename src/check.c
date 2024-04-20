/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 20:18:34 by smclacke      #+#    #+#                 */
/*   Updated: 2024/04/20 16:33:14 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_no_cmd(void)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

void	error_space(char *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

/*
	- calls check_empty for the argument passed
	- splits through the spaces in the cmd
	- calls check_empty for the separated cmd
	- returns the cmd back to run_cmd()
*/

char	**check_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_msg();
	return (cmd);
}
