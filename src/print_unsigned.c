/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   print_unsigned.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/11 12:38:41 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/11 12:38:53 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nb >= 10)
	{
		i += ft_put_u(nb / 10);
	}
	n = nb % 10 + 48;
	i += write(1, &n, 1);
	return (i);
}
