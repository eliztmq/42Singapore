/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:47:51 by elizabethte       #+#    #+#             */
/*   Updated: 2023/11/30 17:12:46 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	execoutchild(int *fd, int f2, char **argv, char **envp)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("Dup2 output child:");
	if (dup2(f2, STDOUT_FILENO) == -1)
		perror("Dup2 output child:");
	close(f2);
	execute_cmd(argv[3], envp);
	exit(EXIT_FAILURE);
}

void	execinchild(int *fd, int f1, char **argv, char **envp)
{
	close(fd[0]);
	if (dup2(f1, STDIN_FILENO) == -1)
		perror("Dup2 input child:");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("Dup2 input child:");
	close(f1);
	execute_cmd(argv[2], envp);
	exit(EXIT_FAILURE);
}

int	execpipe(int f1, int f2, char **argv, char **envp)
{
	int		fd[2];
	pid_t	inputchild;
	pid_t	outputchild;

	if (pipe(fd) == -1)
		perror("Pipe error:");
	inputchild = fork();
	if (inputchild == -1)
		perror("Input fork error:");
	else if (inputchild == 0)
	{
		execinchild(fd, f1, argv, envp);
		return (0);
	}
	outputchild = fork();
	if (outputchild == -1)
		perror("Output fork error:");
	else if (outputchild == 0)
	{
		execoutchild(fd, f2, argv, envp);
		return (0);
	}
	waitpid(inputchild, NULL, 0);
	waitpid(outputchild, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc < 5)
		write(1, "Insufficient inputs\n", 20);
	else
	{
		f1 = open(argv[1], O_RDONLY);
		f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 || f2 < 0)
			perror("Message from perror for files");
		execpipe(f1, f2, argv, envp);
	}
}
