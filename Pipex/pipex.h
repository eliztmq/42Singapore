/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:59:07 by elizabethte       #+#    #+#             */
/*   Updated: 2023/12/15 17:26:09 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>

//commands.c
char	**ft_readpath(char **envp);
char	**ft_getcmd(char *cmd);
void	execute_cmd(char *cmd, char **envp);

//pipex.c
void	execoutchild(int *fd, int f2, char **argv, char **envp);
void	execinchild(int *fd, int f1, char **argv, char **envp);
void	execpipe(int f1, int f2, char **argv, char **envp);

#endif