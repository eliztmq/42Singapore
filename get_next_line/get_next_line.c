/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/09 23:46:31 by elizabethte      ###   ########.fr       */
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
	size_t	copy;

	temp = ft_join(buf, str);
	ft_strzero(str, BUFFER_SIZE + 1);
	if (checkstr(temp))
		output = ft_modsplit(temp, str);
	else
	{
		copy = ft_strlcpy(str, ft_read(fd), BUFFER_SIZE + 1);
		ft_cases(fd, str, temp);
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
		readstr = ft_modsplit(str);
	else
	{
		holding = ft_read(fd);
		readstr = ft_cases(fd, str, holding);
	}
	return (readstr);
}