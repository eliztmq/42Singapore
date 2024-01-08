/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:41:49 by cooi              #+#    #+#             */
/*   Updated: 2023/11/22 22:23:39 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	s[9999999] = {'\0'};
	static int	i = 0;
	int			j;
	int			k;
	char		*r;

	j = 1;
	k = 0;
	while (j > 0)
	{
		j = read(fd, s + k, BUFFER_SIZE);
		if (j == -1 || !*(s + i))
			return (NULL);
		k += j;
	}
	j = 0;
	while (s[i + j] && s[i + j] != '\n')
		j++;
	r = malloc(j + 1 + (s[i + j] == '\n'));
	if (!r)
		return (NULL);
	r[j + (s[i + j] == '\n')] = '\0';
	k = 0;
	while (k <= j)
		r[k++] = s[i++];
	return (r);
}
