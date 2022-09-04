/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:26:29 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/21 13:05:21 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dt;
	char			*sr;

	if (dst != src)
	{
		if (!dst && !src)
			return (0);
		sr = (char *) src;
		dt = dst;
		i = 0;
		while (i < n)
		{
			dt[i] = sr[i];
			i++;
		}
	}
	return (dst);
}
