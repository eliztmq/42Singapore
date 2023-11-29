/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:09:37 by elizabethte       #+#    #+#             */
/*   Updated: 2023/11/29 22:46:28 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//function to retrieve the path and split it according to : && also add the / at the end
//function to split the command according to space - quotation marks in the command line are not considered in argv
//str_join the path split as well as the command

char	**ft_readpath(char **envp)
{
	char	**possiblepath;
	char	*temppath;
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			possiblepath = ft_split(envp[i] + 5, ":");
			break ;
		}
		i++;
	}
	i = 0;
	while (possiblepath[i])
	{
		temppath = ft_strjoin(possiblepath[i], "/");
		free(possiblepath[i]);
		possiblepath[i] = temppath;
		i++;
	}
	return(possiblepath);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmdlst;
	char	**paths;
	char	*cmdpath;
	int		i;

	i = -1;
	cmdlst = ft_split(cmd, " ");
	paths = ft_readpath(envp);
	while(paths[++i])
	{
		cmdpath = ft_strjoin(paths[i], cmdlst[0]);
		if (access(cmdpath, F_OK) == 0)
		{
			if (access(cmdpath, X_OK) == 0)
				execve(cmdpath, cmdlst, envp);
			else
				perror(cmdpath);
		}
		free(cmdpath);
	}
}