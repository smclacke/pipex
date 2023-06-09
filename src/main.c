/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:06:54 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/20 21:44:48 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*
	- recreating bash's behavior:
		bash: < infile cmd1 | cmd2 | cmd3 ... | cmdn > outfile
		pipex: ./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
	- recreating bash's behavior with here_doc:
		bash: cmd << LIMITER | cmd1 >> outfile
		pipex: ./pipex here_doc LIMITER cmd cmd1 cmd2  ... cmdn outfile
	- arguments passed >= 5
	- if 2nd argument is "here_doc", open outfile (last argument)
		infile becomes here_doc(), index set to 3 for cmd count
		(./prog, here_doc, LIMITER, cmd, ...)
	- if no here_doc, index set to 2 for cmd count
		(./prog, infile, cmd, ...)
	- open outfile (last argument), open infile (2nd argument)
	- while there are cmds, create children (pipe + fork for each)
		inside child()
	- call last_child, pipes are closed in child()
		last_child takes from the read end of the last child from child()
		writes to the outfile and closes both infile and outfile
	- waitpid() waits for the pid return of the last child process
	- wait(NULL) waiting for any other process to complete
	- exit on the last child's exit status
*/

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		infile;
	int		outfile;
	int		status;

	if (argc < 5)
		error_args(argc);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		i = 3;
		outfile = open_file(argv[argc - 1], 0);
		infile = here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		outfile = open_file(argv[argc - 1], 1);
		infile = open_file(argv[1], 2);
	}
	while (i < argc - 2)
		infile = child(argv[i++], envp, infile);
	last_child(argv[argc - 2], envp, infile, outfile);
	waitpid(-1, &status, 0);
	wait(NULL);
	return (WEXITSTATUS(status));
}
