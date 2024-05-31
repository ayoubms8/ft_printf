/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:40 by alemsafi          #+#    #+#             */
/*   Updated: 2023/03/17 22:06:42 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

void	ft_putchar2(char c, int *ret);
int		ft_printf(const char *str, ...);
void	ft_putnbr2(int nbr, int *ret);
void	ft_puthex(unsigned long nb, char c, int *ret, int call_num);
void	ft_putu(unsigned int nbr, int *ret);
void	ft_putstring(char *str, int *ret);
#endif