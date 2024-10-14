/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.h                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 18:22:47 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/10 18:22:49 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const	char *format, ...);
int		match_arg(va_list arg, const char c);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putstr(const char *s);
int		ft_putpos(unsigned long int nb, const char c);
int		ft_hex(unsigned int hex, const char c);
int		ft_putnbr(int nb);
int		ft_putptr(unsigned long int p);
int		ft_put_u(unsigned int nb);

#endif
