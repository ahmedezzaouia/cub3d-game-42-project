/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_of_texture_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:03:17 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 12:03:18 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

void check_north_texture_path(s_cub *cub)
{  
    int fd;

    if(!cub->north_path)
    {
        write(2,"there is no north_path\n",23);
        exit(1);
    }
    cub->north_path = get_texture_path(cub->north_path);
    fd = open(cub->north_path,O_RDWR);
    if(fd == -1)
    {
        write(2,"Error there no file have this name ",35);
        write(2,cub->north_path,ft_strlen(cub->north_path));
        write(2," ,or this file have no permition\n",33);
        exit(1);
    }
    
    close(fd);

}
void check_south_texture_path(s_cub *cub)
{
    int fd;

    if(!cub->south_path)
    {
        write(2,"there is no south_path\n",23);
        exit(1);
    }
    cub->south_path = get_texture_path(cub->south_path);
    fd = open(cub->south_path,O_RDWR);
    if(fd == -1)
    {
        write(2,"Error there no file have this name ",35);
        write(2,cub->south_path,ft_strlen(cub->south_path));
        write(2," ,or this file have no permition\n",33);
        exit(1);
    }
    close(fd);
}
void check_west_texture_path(s_cub *cub)
{
    int fd;
    
    if(!cub->west_path)
    {
        write(2,"there is no west_path\n",22);
        exit(1);
    }
    cub->west_path = get_texture_path(cub->west_path);
    fd = open(cub->west_path,O_RDWR);
    if(fd == -1)
    {
        write(2,"Error there no file have this name ",35);
        write(2,cub->west_path,ft_strlen(cub->west_path));
        write(2," ,or this file have no permition\n",33);
        exit(1);
    }
    close(fd);
    
}
void check_east_texture_path(s_cub *cub)
{
    int fd;

    if(!cub->east_path)
    {
        write(2,"there is no east_path\n",232);
        exit(1);
    }
    cub->east_path = get_texture_path(cub->east_path);
    fd = open(cub->east_path,O_RDWR);
    if(fd == -1)
    {
        write(2,"Error there no file have this name ",35);
        write(2,cub->east_path,ft_strlen(cub->east_path));
        write(2," ,or this file have no permition\n",33);
        exit(1);
    }
    close(fd);
}