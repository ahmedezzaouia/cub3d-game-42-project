/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buff_of_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:39:39 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 14:39:42 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    get_buff_of_map_3(s_cub *cub, int fd, int a, int loop)
{
    while(true)
    {
        cub->buffer = get_next_line(fd);
        if(cub->buffer == NULL)
            break;
        else if(cub->buffer[0] != 'N' && cub->buffer[0] != 'S'
            && cub->buffer[0] != 'W' && cub->buffer[0] != 'E'
            && cub->buffer[0] != 'F' && cub->buffer[0] != 'C'
            && cub->buffer[0] != '\n')
        {
            ++loop;
            cub->map_buffer[++a] = cub->buffer;
        }
        else if(cub->buffer[0] == '\n' && loop)
        {
            free(cub->buffer);
            ft_error("map have a newline");
        }
        else
            free(cub->buffer);
    }
    cub->map_buffer[a + 1] = NULL;
}

void    get_buff_of_map_2(s_cub *cub, int *map_lines, int fd, int loop)
{
    while(++loop)
    {
        cub->buffer = get_next_line(fd);
        if(cub->buffer == NULL && loop == 1)
            ft_error("this file is empty");
        else if(cub->buffer == NULL)
            break;
        if(cub->buffer[0] == 'N')
            cub->north_path = cub->buffer;
        else if(cub->buffer[0] == 'S')
            cub->south_path = cub->buffer;
        else if(cub->buffer[0] == 'W')
            cub->west_path = cub->buffer;
        else if(cub->buffer[0] == 'E')
            cub->east_path = cub->buffer;
        else if(cub->buffer[0] == 'F')
            cub->floor_color = cub->buffer;
        else if(cub->buffer[0] == 'C')
            cub->ceilling_color = cub->buffer;
        else
        {
            free(cub->buffer);
            ++(*map_lines);
        }
    }
}

void    get_buff_of_map(s_cub *cub, char *path)
{
    int fd;
    int map_lines;

    map_lines = 0;
    fd = open(path, O_RDWR);
    if (fd == -1)
        ft_error("there no file have this name ,or this file have no permition");
    get_buff_of_map_2(cub, &map_lines, fd, 0);
    if (close(fd) == -1)
        ft_error("can't close file discriptor");
    fd = open(path, O_RDWR);
    if (fd == -1)
        ft_error("there no file have this name ,or this file have no permition");
    cub->map_buffer = malloc(sizeof(char *) * (map_lines + 1));
    if (!cub->map_buffer)
        ft_error("allocation faild for cub->map_buffer");
    get_buff_of_map_3(cub, fd, -1, 0);
    if (close(fd) == -1)
        ft_error("can't close file discriptor");
}