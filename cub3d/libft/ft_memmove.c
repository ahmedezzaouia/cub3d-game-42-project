/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:06:26 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/21 12:47:37 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy(char *dt, char *sc, size_t i, size_t len)
{
	while (i < len)
	{
		dt[i] = sc[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	int				j;
	char			*dt;
	char			*sc;

	if (!dst && !src)
		return (0);
	sc = (char *) src;
	dt = dst;
	i = 0;
	if (dt > sc)
	{
		j = len - 1;
		i = ft_strlen((char *)dt) - 1;
		while (j >= 0)
		{
			dt[j] = sc[j];
			j--;
		}
	}
	else
		ft_copy(dt, sc, i, len);
	return (dst);
}
