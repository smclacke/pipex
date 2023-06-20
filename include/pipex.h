/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:03:41 by smclacke      #+#    #+#                 */
/*   Updated: 2023/06/19 17:56:43 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/src/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# ifndef BUFFERSIZE
#  define BUFFERSIZE 100
# endif

void		ft_close(int var);

//-------Here_doc------//
int			here_doc(char *limiter, int argc);

//--------Pipex--------//
void		run_cmd(char **envp, char *argv);
int			child(char *argv, char **envp, int fd);
void		last_child(char *argv, char **envp, int infile, int outfile);

//--------Paths--------//
char		*ft_cmd_path(char **envp, char *cmd);

//-------Check---------//
void		error_no_cmd(void);
void		error_space(char *cmd);
char		**check_cmd(char *argv);

//--------Error--------//
void		error_args(int argc);
void		error_msg(void);
void		error_file(char **argv);
void		error_cmd(char **cmd);
void		error_here_doc(int argc);

//--------Utils--------//
void		close_pipes(int *pipes);
int			error_access(char *path);
void		error_path(char *cmd);
int			open_file(char *argv, int i);

#endif