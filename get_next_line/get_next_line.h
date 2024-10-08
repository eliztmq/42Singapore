/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:23:49 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/16 22:49:24 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

int		checkstr(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_modsplit(char *srcstr, char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
