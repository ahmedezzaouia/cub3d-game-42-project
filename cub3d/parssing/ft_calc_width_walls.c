/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_width_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 12:50:43 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/12 12:50:45 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_bezero(s_cub *cub)
{
    int a = -1;
    while(++a < 100)
        cub->wall_width[a] = 0;
}

void ft_calc_width_walls(s_cub *cub, int a, int b)
{
    int c;
    int arr[1000];

    ft_bezero(cub);
    cub->color_of_wall[0] = cub->color_of_wall[1];
    while(++a < 1000)
        arr[a] = 0;
    a = -1;
    b = -1;
    while(++a < 1500 && b < 1000)
    {
        if(a > 1)
        {
            if((cub->color_of_wall[a-1] == cub->color_of_wall[a]) && cub->color_of_wall[a] != 0)
                ++arr[b];
            else
                ++b;
        }
    }
    a = -1;
    c = -1;
    while((++c < b + 1) && a < 100)
        if(arr[c] != 0)
            cub->wall_width[++a] = arr[c];
}