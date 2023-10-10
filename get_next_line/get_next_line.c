/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/10 23:34:40 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

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
	char	*temp;
	char	*output;
	char	*holding;

	temp = ft_join(buf, str);
	ft_bzero(str, BUFFER_SIZE + 1);
	if (checkstr(temp))
		output = ft_modsplit(temp, str);
	else
	{
		holding = ft_read(fd);
		if (!*holding)
			return (temp);
		else
		{
			ft_strlcpy(str, holding, BUFFER_SIZE + 1);
			ft_cases(fd, str, temp);
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
		ft_strlcpy(holding, str, BUFFER_SIZE + 1);
		ft_bzero(str, BUFFER_SIZE + 1);
		readstr = ft_modsplit(holding, str);
	}
	else
	{
		holding = ft_read(fd);
		if (!*holding)
			return (str);
		else
			readstr = ft_cases(fd, str, holding);
	}
	return (readstr);
}