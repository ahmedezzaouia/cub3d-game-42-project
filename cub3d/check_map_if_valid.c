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
    int c;
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
            if(cub->map_buffer[0][0] == '1')
            {
                c = -1;
                while(cub->map_buffer[0][++c])
                {    
                    if(cub->map_buffer[0][c] == '0')
                    {
                        printf("here\n");
                        left_bad_map = 1;
                        break;
                    }
                }    
                c = -1;
                while(cub->map_buffer[++c][0])
                {    
                    if(cub->map_buffer[c][0] == '0')
                    {
                        printf("here1\n");
                        left_bad_map = 1;
                        break;
                    }
                }
            }

            if(cub->map_buffer[a][b] == ' ')
            {
                c = a + 1;
                while(--c >= 0)
                {
                    if(cub->map_buffer[c][b] == '1' && c == 0)
                        break;
                    else if(cub->map_buffer[c][b] == '1' && cub->map_buffer[c + 1][b] == ' ')
                        break;
                    else if(cub->map_buffer[c][b] == '0' && cub->map_buffer[c + 1][b] == ' ')
                    {
                        up_bad_map = 1;
                        break;
                    }
                    // else if(cub->map_buffer[c][b] != '1' && c == 0)
                    //     up_bad_map = 2;
                }
                c = a - 1;
                while(cub->map_buffer[++c] != NULL)
                {
                    if(cub->map_buffer[c][b] == '1' && cub->map_buffer[c + 1] == NULL)
                        break;
                    if(cub->map_buffer[c][b] == '1' && cub->map_buffer[c - 1][b] == ' ')
                        break;
                    else if(cub->map_buffer[c][b] == '0' && cub->map_buffer[c - 1][b] == ' ')
                    {
                        down_bad_map = 1;
                        break;
                    }
                    // else if(cub->map_buffer[c][b] != '1' && cub->map_buffer[c + 1] == NULL)
                    //     down_bad_map = 2;
                }
                c = b + 1;
                while(--c >= 0)
                {
                    if(cub->map_buffer[a][c] == '1' && c == 0)
                        break;
                    else if(cub->map_buffer[a][c] == '1' && cub->map_buffer[a][c + 1] == ' ')
                        break;
                    else if(cub->map_buffer[a][c] == '0' && cub->map_buffer[a][c + 1] == ' ')
                    {
                        left_bad_map = 1;
                        break;
                    }
                    // else if(cub->map_buffer[a][c] != '1' && c == 0)
                    //     left_bad_map = 2;
                }
                c = b - 1;
                while(cub->map_buffer[a][++c] != '\0')
                {
                    if(cub->map_buffer[a][c] == '1' && cub->map_buffer[a][c + 1] == '\n')
                        break;
                    else if(cub->map_buffer[a][c] == '1' && cub->map_buffer[a][c - 1] == ' ')
                        break;
                    else if(cub->map_buffer[a][c] == '0' && cub->map_buffer[a][c - 1] == ' ')
                    {
                        right_bad_map = 1;
                        break;
                    }
                    // else if(cub->map_buffer[a][c] != '1' && cub->map_buffer[a][c + 1] == '\n')
                    //     right_bad_map = 2;
                }
                // printf("------%d-----%d------\n",a,b);
                // printf("up %d\n",up_bad_map);
                // printf("down %d\n",down_bad_map);
                // printf("right %d\n",right_bad_map);
                // printf("left %d\n",left_bad_map);
                // if((right_bad_map == 2 && left_bad_map == 2 && up_bad_map == 2 && down_bad_map == 0)
                //     || (right_bad_map == 2 && left_bad_map == 2 && down_bad_map == 2 && up_bad_map == 0)
                //     || (up_bad_map == 2 && down_bad_map == 2 && right_bad_map == 2 && left_bad_map == 0)
                //     || (up_bad_map == 2 && down_bad_map == 2 && left_bad_map == 2 && right_bad_map == 0))
                    // ;          
                // else if((right_bad_map == 2 && left_bad_map == 2) || (up_bad_map == 2 && down_bad_map == 2))
                //    break;
                // else if((right_bad_map == 2 || left_bad_map == 2) || (up_bad_map == 2 || down_bad_map == 2))
                //     break;
                if((right_bad_map == 1 || left_bad_map == 1) || (up_bad_map == 1 || down_bad_map == 1))
                   break;
            }
        }
        // if((right_bad_map == 2 && left_bad_map == 2 && up_bad_map == 2 && down_bad_map == 0)
        //     || (right_bad_map == 2 && left_bad_map == 2 && down_bad_map == 2 && up_bad_map == 0)
        //     || (up_bad_map == 2 && down_bad_map == 2 && right_bad_map == 2 && left_bad_map == 0)
        //     || (up_bad_map == 2 && down_bad_map == 2 && left_bad_map == 2 && right_bad_map == 0))
        //     ;
        // else if((right_bad_map == 2 && left_bad_map == 2) || (up_bad_map == 2 && down_bad_map == 2))
        //    break;
        // else if((right_bad_map == 2 || left_bad_map == 2) || (up_bad_map == 2 || down_bad_map == 2))
        //     break;
        if((right_bad_map == 1 || left_bad_map == 1) || (up_bad_map == 1 || down_bad_map == 1))
            break;
    }
    // if((right_bad_map == 2 && left_bad_map == 2 && up_bad_map == 2 && down_bad_map == 0)
    //     || (right_bad_map == 2 && left_bad_map == 2 && down_bad_map == 2 && up_bad_map == 0)
    //     || (up_bad_map == 2 && down_bad_map == 2 && right_bad_map == 2 && left_bad_map == 0)
    //     || (up_bad_map == 2 && down_bad_map == 2 && left_bad_map == 2 && right_bad_map == 0))
    //     printf("good map 2\n");
    // else if((right_bad_map == 2 && left_bad_map == 2) || (up_bad_map == 2 && down_bad_map == 2))
    //     printf("bad map\n");
    // else if((right_bad_map == 2 || left_bad_map == 2) || (up_bad_map == 2 || down_bad_map == 2))
    //     printf("bad map 2\n");
    if((right_bad_map == 1 || left_bad_map == 1) || (up_bad_map == 1 || down_bad_map == 1))
        printf("bad map\n");
    else if((!right_bad_map || !left_bad_map) && (!up_bad_map || !down_bad_map))
        printf("good map\n");
}