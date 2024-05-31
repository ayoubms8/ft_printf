/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:58 by alemsafi          #+#    #+#             */
/*   Updated: 2023/03/17 22:07:03 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long nb, char c, int *ret, int first_call)
{
	char	*bighex;
	char	*smolhex;

	bighex = "0123456789ABCDEF";
	smolhex = "0123456789abcdef";
	if (first_call && c == 'p' && !nb)
	{
		ft_putstring("(nil)", ret);
		return ;
	}
	else if (first_call && c == 'p')
		ft_putstring("0x", ret);
	if (nb < 16)
	{
		if (c == 'x' || c == 'p')
			write(1, &smolhex[nb], 1);
		else
			write(1, &bighex[nb], 1);
		*ret = *ret + 1;
	}
	else
	{
		ft_puthex(nb / 16, c, ret, 0);
		ft_puthex(nb % 16, c, ret, 0);
	}
}

void	ft_putu(unsigned int nbr, int *ret)
{
	if (nbr < 10)
		ft_putchar2(nbr + '0', ret);
	else
	{
		ft_putnbr2(nbr / 10, ret);
		ft_putnbr2(nbr % 10, ret);
	}
}
