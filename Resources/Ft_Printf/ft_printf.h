/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:26:01 by cooi              #+#    #+#             */
/*   Updated: 2023/09/13 19:26:12 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

int			ft_printf(const char *s, ...);
int			handle_c(char c, va_list ap, int fd);
int			handle_hex(char c, va_list ap, int fd);
int			handle_num(char c, va_list ap, int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(long n, int fd, int *count);
void		ft_putnbr_base(unsigned long nbr, int flag, int *count);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		math(unsigned int start, size_t len, size_t i);
int			ft_strlen(const char *str);
int			ft_strchr(const char *s, int c);

#endif
