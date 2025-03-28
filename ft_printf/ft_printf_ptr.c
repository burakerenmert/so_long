/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by buramert          #+#    #+#             */
/*   Updated: 2025/03/28 08:04:25 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptrlen(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static void	ft_putptr_helper(unsigned long ptr, char *hex)
{
	if (ptr < 16)
	{
		ft_putchar(hex[ptr % 16]);
	}
	else
	{
		ft_putptr_helper(ptr / 16, hex);
		ft_putchar(hex[ptr % 16]);
	}
}

int	ft_putptr(unsigned long ptr)
{
	int	counter;

	counter = 0;
	counter += write(1, "0x", 2);
	if (ptr == 0)
		counter += write(1, "0", 1);
	else
	{
		ft_putptr_helper(ptr, "0123456789abcdef");
		counter += ptrlen(ptr);
	}
	return (counter);
}
