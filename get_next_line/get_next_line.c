/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/12 10:47:05 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checkstr(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd)
{
	ssize_t	byteread;
	char	*buf;

	buf = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	byteread = read(fd, buf, BUFFER_SIZE);
	if (byteread < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*ft_cases(int fd, char *str, char *buf)
{
	char	*output;
	char	*holding;

	output = ft_join(buf, str);
	ft_bzero(str, BUFFER_SIZE + 1);
	if (checkstr(output))
		ft_modsplit(output, str);
	else
	{
		holding = ft_read(fd);
		if (!*holding)
			return (output);
		else
		{
			ft_strlcpy(str, holding, BUFFER_SIZE + 1);
			free(holding);
			ft_cases(fd, str, output);
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*readstr;
	char		*holding;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (checkstr(str))
	{
		readstr = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (readstr == NULL)
			return (NULL);
		ft_strlcpy(readstr, str, BUFFER_SIZE + 1);
		ft_bzero(str, BUFFER_SIZE + 1);
		ft_modsplit(readstr, str);
	}
	else
	{
		holding = ft_read(fd);
		if (!*holding)
		{
			free(holding);
			return (str);
		}
		else
			readstr = ft_cases(fd, str, holding);
	}
	return (readstr);
}
