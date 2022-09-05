/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_of_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:23:02 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 21:24:10 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_len_of_map(s_cub *cub)
{
	int	a;

	a = -1;
	while (cub->map_buffer[++a])
		;
	cub->b_map_buf = malloc(sizeof(int) * a);
	if (!cub->b_map_buf)
		ft_error("can't allocated for b_map_buf");
	a = -1;
	while (cub->map_buffer[++a])
		cub->b_map_buf[a] = ft_strlen(cub->map_buffer[a]);
	cub->a_map_buf = a;
}
