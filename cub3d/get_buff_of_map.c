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
    int len;
    int loop;
    char *buf;

    fd = open(path, O_RDWR);
    len = 0;
    loop = 0;

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
        if(cub->buffer[0] == 'N' && cub->buffer[1] == 'O')
            cub->north_path = cub->buffer;
        else if(cub->buffer[0] == 'S' && cub->buffer[1] == 'O')
            cub->south_path = cub->buffer;
        else if(cub->buffer[0] == 'W' && cub->buffer[1] == 'E')
            cub->west_path = cub->buffer;
        else if(cub->buffer[0] == 'E' && cub->buffer[1] == 'A')
            cub->east_path = cub->buffer;
        else if(cub->buffer[0] == 'F')
            cub->floor_color = cub->buffer;
        else if(cub->buffer[0] == 'C')
            cub->ceilling_color = cub->buffer;
        else if(cub->buffer[0] == '1' || cub->buffer[0] == ' ')
        {
            a = ft_strlen(cub->buffer) - 1;
            free(cub->buffer);
        }
        else if(cub->buffer[0] == '\n')
            free(cub->buffer);
        len += a;
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
    buf = malloc(sizeof(char) * len + 1);
    while(true)
    {
        cub->buffer = get_next_line(fd);
        if(cub->buffer[0] == '1' || cub->buffer[0] == ' ')
            break;
        else if(cub->buffer == NULL)
            break;
        free(cub->buffer);
    }
    a = read(fd,buf,len);
    if(close(fd) == -1)
    {
        write(2,"Error in close fd\n",18);
        exit(1);
    }
    if(a == -1)
    {
        write(2,"Error in read\n",14);
        exit(1);
    }
    buf[a] = '\0';
    cub->map_buffer = ft_strjoin(cub->buffer,buf);
    // printf("\n%s\n\n",cub->north_path);
    // printf("%s\n\n",cub->south_path);
    // printf("%s\n\n",cub->west_path);
    // printf("%s\n\n",cub->east_path);
    // printf("%s\n\n",cub->floor_color);
    // printf("%s\n\n",cub->ceilling_color);
    // printf("%s\n",cub->map_buffer);
    // exit(0);
    return ;
}