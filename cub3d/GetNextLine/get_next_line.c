/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:43:54 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/06 09:45:53 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(int fd)
{
	char	buff[8000000];
	char	c;
	int		i;
	int		j;

	i = 0;
	ft_memset(buff, 0, 8000000);
	while (read(fd, &c, 1) > 0)
	{	
		if (c == '\t')
		{
			j = 0;
			while (j++ < 4)
				buff[i++] = ' ';
		}
		else
			buff[i++] = c;
		if (c == '\n')
			break ;
	}
	if (buff[0] == 0)
		return (NULL);
	return (ft_strdup(buff));
}
