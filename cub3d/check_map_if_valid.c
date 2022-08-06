/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_if_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:10:40 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 21:10:45 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

void check_map_if_valid(s_cub *cub)
{
    int a;
    int b;
    int up_bad_map;
    int down_bad_map;
    int right_bad_map;
    int left_bad_map;
    
    a = -1;
    while(cub->map_buffer[++a])
    {
        b = -1;
        while(cub->map_buffer[a][++b])
        {
            up_bad_map = 0;
            down_bad_map = 0;
            right_bad_map = 0;
            left_bad_map = 0;
            if(cub->map_buffer[0][b] == '0')
            {
                printf("bad map\n");
                exit(1);
            }
            else if(cub->map_buffer[a][0] == '0')
            {
                printf("bad map 2\n");
                exit(1);
            }
            else if(cub->map_buffer[a][b] == '0' && cub->map_buffer[a + 1] == NULL)
            {
                printf("bad map 3\n");
                exit(1);
            }
            else if(cub->map_buffer[a][b] == '0' && cub->map_buffer[a][b + 1] == '\n')
            {
                printf("bad map 4\n");
                exit(1);
            }
            else if(cub->map_buffer[a][b] == '0')
            {
                if(cub->map_buffer[a][b] == '0' && cub->map_buffer[a + 1][b] == ' ')
                    up_bad_map = 1;
                else if(cub->map_buffer[a][b] == '0'
                    && (cub->map_buffer[a - 1][b] == ' ' || b > ft_strlen(cub->map_buffer[a - 1] + 3)))
                    down_bad_map = 1;
                else if(cub->map_buffer[a][b] == '0'
                    && (cub->map_buffer[a][b + 1] == ' ' || b > ft_strlen(cub->map_buffer[a + 1] + 3)))
                    right_bad_map = 1;
                else if(cub->map_buffer[a][b] == '0' && cub->map_buffer[a][b - 1] == ' ')
                    left_bad_map = 1;
                if(up_bad_map == 1 || down_bad_map == 1 || right_bad_map == 1 || left_bad_map == 1)
                {
                    if(up_bad_map == 1)
                        printf("up bad map\n");
                    else if(down_bad_map == 1)
                        printf("down bad map\n");
                    else if(left_bad_map == 1)
                        printf("left bad map\n");
                    else if(right_bad_map == 1)
                        printf("right bad map\n");
                    exit(1);
                }
            }
        }
    }

}