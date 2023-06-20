/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:03:03 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 20:55:39 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	- search through the envp to find PATH=
	- if successful, returns the substring of the PATH environment 
		without 'PATH=' included
	- else (if e.g. path is unset) return NULL to ft_get_paths()
*/


static char	*ft_get_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{		
		if (ft_strnstr(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (NULL);
}

/*
	- if PATH= is successfully found and the substring is returned
		path = the list of directories inside the PATH= environment
	- split between these directories and return the array of directories
		to ft_cmd_path()
*/

static char	**ft_get_paths(char **envp, char *cmd)
{
	char	**path_parts;
	char	*paths;

	paths = ft_get_env(envp);
	if (!paths)
		error_path(cmd);
	path_parts = ft_split(paths, ':');
	if (!path_parts)
		error_msg();
	free(paths);
	return (path_parts);
}

/*
	- if passing an local executable (e.g. ./program)
		don't search through the path directories, just return cmd to run_cmd()
	- if an absolute path is passed (e.g. /bin/cat) 
		don't search through the path directories, just return cmd to run_cmd()
	- else return 0 and search the path directories for the correct cmd path
*/

static char	*check_slash(char *cmd)
{
	if (!ft_strncmp("./", cmd, 2) && access(cmd, F_OK) == 0)
		return (cmd);
	if (access(cmd, F_OK || X_OK) == 0)
		return (cmd);
	return (0);
}

/*
	- after checking the cmd passed is not local or the absolute path, 
		strjoin '/' so that cmd -> /cmd
	- parse through the path directoris adding /cmd on to the end
		till access(F_OK), command has been found
	- return arg_path to run_cmd where its existence and
		executability is checked 
*/

char	*ft_cmd_path(char **envp, char *cmd)
{
	char	*arg_path;
	char	**path_parts;
	char	*cmd_args;
	int		i;

	i = 0;
	cmd_args = 0;
	if (check_slash(cmd))
		return (cmd);
	path_parts = ft_get_paths(envp, cmd);
	if (!path_parts)
		error_path(cmd);
	cmd_args = ft_strjoin("/", cmd);
	while (path_parts[i])
	{
		arg_path = ft_strjoin(path_parts[i], cmd_args);
		if (access(arg_path, F_OK) == 0)
			break ;
		free(arg_path);
		arg_path = NULL;
		i++;
	}
	ft_free_arr(path_parts);
	free(cmd_args);
	return (arg_path);
}
