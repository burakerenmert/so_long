/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by buramert          #+#    #+#             */
/*   Updated: 2025/03/28 08:04:21 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	static char	buffer[16];
	int			i;
	int			counter;
	long		num;

	i = 0;
	counter = 0;
	num = nbr;
	if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		counter += write(1, "-", 1);
		num = -num;
	}
	while (num)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}
	while (i--)
		counter += write(1, &buffer[i], 1);
	return (counter);
}

int	ft_putnbr_u(unsigned int nbr)
{
	static char	buffer[16];
	int			i;
	int			counter;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	counter = 0;
	while (nbr)
	{
		buffer[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i--)
		counter += write(1, &buffer[i], 1);
	return (counter);
}

int	ft_puthex(unsigned int nbr, char *base)
{
	static char	buffer[16];
	int			i;
	int			counter;

	if (nbr == 0)
		return (write(1, "0", 1));
	i = 0;
	counter = 0;
	while (nbr)
	{
		buffer[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i--)
		counter += write(1, &buffer[i], 1);
	return (counter);
}
