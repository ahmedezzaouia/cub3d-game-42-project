/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haider.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:00:04 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 12:00:06 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAIDER_H
# define HAIDER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/errno.h>
# include "./get_next_line/get_next_line.h"

typedef struct t_list
{
    char *north_path;
    char *south_path;
    char *west_path;
    char *east_path;
    char *floor_color;
    char *ceilling_color;
    char **map_buffer;
    char *buffer;
    int *F_RGB;
    int *C_RGB;
}s_cub;

void check_path_of_map_file(char *path);
int ft_strlen(char *str);
int ft_strncmp2(char *S1, char *S2, int num);
int ft_strcmp(char *S1, char *S2);
char	*ft_strjoin(char *s1, char *s2);

char	*get_next_line(int fd);
void get_buff_of_map(s_cub *cub, char *path);

void check_north_texture_path(s_cub *cub);
void check_south_texture_path(s_cub *cub);
void check_west_texture_path(s_cub *cub);
void check_east_texture_path(s_cub *cub);

char *get_texture_path(char *ptr);

int *get_rgb_color(char *str);
void check_map_if_valid(s_cub *cub);

// void error_bad_path(void);

#endif