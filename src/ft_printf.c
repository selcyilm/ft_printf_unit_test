/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf_main.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 18:22:30 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/10 18:22:33 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const	char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += match_arg(arg, s[i]);
		}
		else
		{
			write(1, &s[i], 1);
			if (s[i])
				len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int	match_arg(va_list arg, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		len = ft_putptr(va_arg(arg, unsigned long int));
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		len = ft_put_u(va_arg(arg, unsigned int));
	if (c == 'x' || c == 'X')
		len = ft_hex(va_arg(arg, unsigned int), c);
	if (c == '%')
		len = ft_putchar('%');
	return (len);
}
