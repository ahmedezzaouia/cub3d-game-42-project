/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:54:23 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 11:54:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

s_cub *cub_init(char **argv)
{
    s_cub *cub;

    cub = malloc(sizeof(s_cub));

    cub->ceilling_color = NULL;
    cub->east_path = NULL;
    cub->floor_color = NULL;
    cub->map_buffer = NULL;
    cub->north_path = NULL;
    cub->south_path = NULL;
    cub->west_path = NULL;
    cub->buffer = NULL;
    get_buff_of_map(cub, argv[1]);
    check_north_texture_path(cub);
    check_south_texture_path(cub);
    check_west_texture_path(cub);
    check_east_texture_path(cub);
    // get_floor_rgb_color(cub);
    cub->F_RGB = get_rgb_color(cub->floor_color);
    cub->C_RGB =  get_rgb_color(cub->ceilling_color);

    return (cub);
}

int main (int argc,char **argv)
{
    s_cub *cub;

    if(argc != 2)
    {   
        write(2,"Erorr bad number of argumment\n",30);
        return (1);
    }
    check_path_of_map_file(argv[1]);
    cub = cub_init(argv);
    // system("leaks cub3D");
    return(0);
}
