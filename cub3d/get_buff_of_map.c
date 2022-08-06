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


#include "haider.h"

void get_buff_of_map(s_cub *cub, char *path)
{
    int a;
    int fd;
    int map_lines;
    int loop;

    fd = open(path, O_RDWR);
    loop = 0;
    map_lines = 0;

    if(fd == -1)
    {
        write(2,"Error there no file have this name ,or this file have no permition\n",67);
        exit(1);
    }
    while(true)
    {
        a = 0;
        ++loop;
        cub->buffer = get_next_line(fd);
        if(cub->buffer == NULL && loop == 1)
        {
            write(2,"Error this file is empty\n",25);
            exit(1);
        }
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
            ++map_lines;
        }
    }
    if(close(fd) == -1)
    {
        write(2,"Error in close fd 1\n",18);
        exit(1);
    }
    fd = open(path, O_RDWR);
    if(fd == -1)
    {
        write(2,"Error there no file have this name ,or this file have no permition\n",67);
        exit(1);
    }
    cub->map_buffer = malloc(sizeof(char *) * (map_lines + 1));
    if(!cub->map_buffer)
    {
        write(2,"Erorr : can't allocated\n",24);
        exit(1);
    }
    a = -1;
    loop = 0;
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
            write(2,"Error map have a newline\n",25);
            free(cub->buffer);
            exit(1);
        }
        else
            free(cub->buffer);
    }
    cub->map_buffer[a + 1] = NULL;
    if(close(fd) == -1)
    {
        write(2,"Error in close fd\n",18);
        exit(1);
    }
    a = -1;
    while(cub->map_buffer[++a])
        printf("%d %s",a,cub->map_buffer[a]);
    printf("\n");
    // system("leaks cub3D");

}