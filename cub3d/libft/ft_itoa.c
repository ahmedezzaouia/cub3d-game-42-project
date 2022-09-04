/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:52:48 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/21 12:53:07 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static void	ft_handle_negative_signe(char *buffer, long *nbr)
{
	buffer[0] = '-';
	*nbr = *nbr * -1;
}

static char	*ft_is_equal_to_zero(char *buffer)
{
	buffer[0] = 48;
	buffer[1] = '\0';
	return (buffer);
}

char	*ft_itoa(int b)
{
	int		i;
	char	*buffer;
	int		len;
	long	nbr;

	i = 0;
	nbr = b;
	len = ft_count_digit(nbr);
	buffer = ft_calloc(len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (nbr == 0)
		return (ft_is_equal_to_zero(buffer));
	if (nbr < 0)
		ft_handle_negative_signe(buffer, &nbr);
	len--;
	while (len >= 0 && nbr != 0)
	{
		buffer[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (buffer);
}
