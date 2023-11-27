/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:09:37 by elizabethte       #+#    #+#             */
/*   Updated: 2023/11/27 23:09:04 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//function to retrieve the path and split it according to : && also add the / at the end
//function to split the command according to space(taking into account the quotation marks)
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

char	**ft_cmdarg(char *cmd)
{
	
}