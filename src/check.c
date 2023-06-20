/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 20:18:34 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 20:56:06 by smclacke      ########   odam.nl         */
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
	- check that there is a cmd
	- check if it is just a space, or there are consecutive spaces
	- error_space() prints, along with the error message, the cmd passed,
		rather than taking **cmd and parsing through the array
		(unnecessary in these cases)
	- returns the cmd back to run_cmd()
*/

static char	*check_empty(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		error_no_cmd();
	while (cmd[i])
	{
		if (ft_isspace(cmd[0]))
			error_space(cmd);
		if (ft_isspace(cmd[i] && ft_isspace(cmd[i - 1])
				&& ft_isspace(cmd[i + 1])))
			error_space(cmd);
		if (ft_isspace(cmd[i]) && (ft_isspace(cmd[i + 1])
				|| cmd[i + 1] == '\0'))
			error_space(cmd);
		i++;
	}
	return (cmd);
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

	check_empty(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		error_msg();
	check_empty(*cmd);
	return (cmd);
}
