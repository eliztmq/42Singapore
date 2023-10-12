/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:25:35 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/12 12:50:58 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

int		checkstr(char *str);
char	*ft_read(int fd);
char	*ft_cases(int fd, char *str, char *buf);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	ft_modsplit(char *temp, char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
