/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:46 by alemsafi          #+#    #+#             */
/*   Updated: 2023/03/17 22:06:49 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstring(char *str, int *ret)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*ret = *ret + 6;
		return ;
	}
	while (str[i])
	{
		write(1, &str[i++], 1);
		*ret = *ret + 1;
	}
}

void	ft_putchar2(char c, int *ret)
{
	write(1, &c, 1);
	*ret = *ret + 1;
}

void	ft_putnbr2(int nbr, int *ret)
{
	if (nbr == -2147483648)
	{
		ft_putstring("-2147483648", ret);
		return ;
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar2('-', ret);
	}
	if (nbr < 10)
		ft_putchar2(nbr + '0', ret);
	else
	{
		ft_putnbr2(nbr / 10, ret);
		ft_putnbr2(nbr % 10, ret);
	}
}

void	put_var(char c, va_list args, int *ret)
{
	if (c == 'c')
		ft_putchar2(va_arg(args, int), ret);
	else if (c == 'd' || c == 'i')
		ft_putnbr2(va_arg(args, int), ret);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), c, ret, 1);
	else if (c == 's')
		ft_putstring(va_arg(args, char *), ret);
	else if (c == '%')
		ft_putchar2('%', ret);
	else if (c == 'u')
		ft_putu(va_arg(args, unsigned int), ret);
	else if (c == 'p')
		ft_puthex(va_arg(args, unsigned long), c, ret, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
			put_var(str[++i], args, &ret);
		else
		{
			write(1, &str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}
