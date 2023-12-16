/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:09:37 by elizabethte       #+#    #+#             */
/*   Updated: 2023/12/15 18:04:59 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	**ft_readpath(char **envp)
{
	char	**possiblepath;
	char	*temppath;
	int		i;

	i = 0;
	possiblepath = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			possiblepath = ft_split(envp[i] + 5, ':');
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
	return (possiblepath);
}

char	**ft_getcmd(char *cmd)
{
	char	**output;
	char	*temp;
	char	div;
	int		i;
	int		count;

	i = 0;
	count = 0;
	output = ft_calloc(1, sizeof(char *));
	while (cmd[i])
	{
		div = ' ';
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			div = cmd[i];
			i++;
		}
		temp = ft_strchr(cmd + i, div);
		if (temp)
		{
			output[count] = ft_substr(cmd, i, temp - (cmd + i));
			i += temp - (cmd + i);
			count++;
			output = ft_realloc(output, (count + 1) * sizeof(char *),
					count * sizeof(char *));

		}
		else
		{
			output[count] = ft_substr(cmd, i, ft_strlen(cmd) - i);
			i += ft_strlen(cmd) - i;
		}
		i++;
	}
	output[count] = NULL ;
	return (output);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmdlst;
	char	**paths;
	char	*cmdpath;
	int		i;

	i = -1;
	cmdlst = ft_getcmd(cmd);
	paths = ft_readpath(envp);
	while (paths[++i])
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
