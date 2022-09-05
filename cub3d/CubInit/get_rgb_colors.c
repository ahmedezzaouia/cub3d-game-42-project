/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:51:06 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/05 22:18:40 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	*get_rgb_color_2(char *str, int *num)
{
	int	a;
	int	b;

	a = 1;
	b = 0;
	while (str[++a])
	{
		if (str[a] == ',' || str[a] == '\n')
		{
			num[b] /= 10;
			++b;
		}
		if (str[a] > 47 && str[a] < 58)
		{
		num[b] += str[a] - 48;
		num[b] *= 10;
		}
	}
	return (num);
}

int	*get_rgb_color(char *str)
{
	int	*num;

	if (!str)
		ft_err("there is no element_color\n");
	num = malloc(sizeof(int) * 3);
	if (!num)
		ft_err("Erorr : can't allocated\n");
	num[0] = 0;
	num[1] = 0;
	num[2] = 0;
	num = get_rgb_color_2(str, num);
	return (num);
}
