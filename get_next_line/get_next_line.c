/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/15 16:55:12 by elizabethte      ###   ########.fr       */
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

char	*ft_read(int fd, char *str)
{
	ssize_t	byteread;
	char	*hold;
	char	*buf;
	char	*output;

	buf = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	hold = ft_substr(str, 0, BUFFER_SIZE + 1);
	byteread = read(fd, buf, BUFFER_SIZE);
	if (byteread <= 0)
	{
		free(buf);
		free(hold);
		return (NULL);
	}
	buf[byteread] = '\0';
	output = ft_join(hold, buf);
	free(buf);
	free(hold);
	ft_bzero(str, BUFFER_SIZE + 1);
	return (output);
}

char	*ft_cases(int fd, char *str, char *buf)
{
	char	*output;
	char	*holding;

	if (checkstr(buf))
	{
		ft_modsplit(buf, str);
		return (buf);
	}
	else
	{
		holding = ft_read(fd, str);
		if (holding == NULL)
			return (buf);
		if (!*holding)
		{
			free (holding);
			return (buf);
		}
		else
			output = ft_cases(fd, str, holding);
	}
	return (output);
}

char	*check_str(char *str)
{
	char	*readstr;

	readstr = ft_substr(str, 0, BUFFER_SIZE + 1);
	ft_bzero(str, BUFFER_SIZE + 1);
	ft_modsplit(readstr, str);
	return (readstr);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*readstr;
	char		*holding;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (checkstr(str))
		readstr = check_str(str);
	else
	{
		holding = ft_read(fd, str);
		if (!holding)
			return (NULL);
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
