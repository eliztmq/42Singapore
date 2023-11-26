/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:47:51 by elizabethte       #+#    #+#             */
/*   Updated: 2023/11/26 22:57:23 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	//first check if files are valid (first and last of argument)
		//if first file does not exist, stderror message
		//if last file does not exist, it will be created, take note that > means that the whole information inside will be replaced with the output

	//function to retrieve the path and split it according to :
	//function to split the command according to space(taking into account the quotation marks)
	//str_join the path split as well as the command, make sure to add a /

	//pipe, initiate the fd[2]
	//fork, first child process, dup2 to change f1 into input, change output to write into pipe
		//run execve function with the combination of the above with the command retrieved, make sure to return

	//fork again, dup2 change input to pipe read fd and output to f2
}