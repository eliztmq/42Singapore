/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/16 22:47:36 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	ssize_t	byteread;
	char	*buf;
	char	*output;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	byteread = 1;
	output = ft_substr(str, 0, BUFFER_SIZE + 1);
	while (byteread > 0 && checkstr(output) == 0)
	{
		byteread = read(fd, buf, BUFFER_SIZE);
		if (byteread < 0)
		{
			free(buf);
			free(output);
			return (NULL);
		}
		output = ft_join(output, buf);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	free(buf);
	return (output);
}

void	ft_modsplit(char *srcstr, char *str)
{
	int		i;
	int		cnt;
	char	*tmp;

	i = 0;
	cnt = 0;
	while (srcstr[cnt])
		cnt++;
	while (srcstr[i] && srcstr[i] != '\n')
		i++;
	tmp = ft_substr(srcstr, i + 1, cnt - i);
	if (srcstr[i] == '\n')
		srcstr[i + 1] = '\0';
	if (tmp == NULL)
		return ;
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*readstr;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	readstr = ft_read(fd, str);
	ft_bzero(str, BUFFER_SIZE + 1);
	if (readstr == NULL)
		return (NULL);
	if (!*readstr)
	{
		free (readstr);
		return (NULL);
	}
	ft_modsplit(readstr, str);
	return (readstr);
}
