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


#include "haider.h"

void ft_bezero(s_cub *cub)
{
    int a = -1;
    while(++a < 100)
        cub->wall_width[a] = 0;
}

void ft_calc_width_walls(s_cub *cub)
{
    int a;
    int b;
    int arr[100];

    a = -1;
    ft_bezero(cub);
    cub->color_of_wall[0] = cub->color_of_wall[1];
    while(++a < 100)
        arr[a] = 0;
    a = -1;
    b = -1;
    while(++a < 500)
    {
        if(a > 1)
        {
            // if(cub->color_of_wall[a] == 16777215)
            // {
                if((cub->color_of_wall[a-1] == cub->color_of_wall[a]) && cub->color_of_wall[a] != 0)
                    ++arr[b];
                else
                    ++b;
            //}
        }
    }
    a = -1;
    b = -1;
    while(++a < 100)
        if(arr[a] != 0)
            cub->wall_width[++b] = arr[a];
    a = -1;
    while(++a < 15)
        printf("%d\n",cub->wall_width[a]);
    printf("---\n");
}