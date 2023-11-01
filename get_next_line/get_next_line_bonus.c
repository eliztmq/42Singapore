/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:58:49 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/24 16:43:31 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *output)
{
	ssize_t	byteread;
	char	*buf;
	char	*tmp;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	byteread = 1;
	while (byteread > 0 && checkstr(output) == 0)
	{
		byteread = read(fd, buf, BUFFER_SIZE);
		if (byteread < 0)
		{
			free(buf);
			free(output);
			return (NULL);
		}
		tmp = ft_join(output, buf);
		free(output);
		output = tmp;
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
	static char	str[1024][BUFFER_SIZE + 1];
	char		*readstr;
	char		*tmp;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = ft_substr(str[fd], 0, BUFFER_SIZE + 1);
	readstr = ft_read(fd, tmp);
	ft_bzero(str[fd], BUFFER_SIZE + 1);
	if (readstr == NULL)
		return (NULL);
	if (!*readstr)
	{
		free (readstr);
		return (NULL);
	}
	ft_modsplit(readstr, str[fd]);
	return (readstr);
}
