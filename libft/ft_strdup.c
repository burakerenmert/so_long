/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buramert <buramert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 22:12:06 by buramert          #+#    #+#             */
/*   Updated: 2025/03/28 08:07:06 by buramert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret_arr;
	int		i;

	i = 0;
	ret_arr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret_arr)
		return (NULL);
	while (src[i])
	{
		ret_arr[i] = src[i];
		i++;
	}
	ret_arr[i] = '\0';
	return (ret_arr);
}
