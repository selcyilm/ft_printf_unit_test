/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putptr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: selcyilm <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2024/10/10 18:23:14 by selcyilm       #+#    #+#                */
/*   Updated: 2024/10/10 18:23:15 by selcyilm       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putptr(unsigned long int p)
{
	if (!p || p == 0)
		return (ft_putstr("(nil)"));
	return (write(1, "0x", 2) + ft_putpos(p, 'p'));
}
