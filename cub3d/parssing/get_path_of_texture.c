/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_of_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:10:48 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 18:11:01 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *get_texture_path(char *ptr)
{
    int a;
    int b;
    int len;
    char *path;

    a = 2;
    b = -1;
    len = ft_strlen(ptr);
    len += 1;
    path = malloc(sizeof(char) * len);
    if(!path)
    {
        write(2,"Erorr : can't allocated\n",24);
        exit(1);
    }
    while(ptr[++a])
        path[++b] = ptr[a];
    path[b] = '.';
    path[b + 1] = 'x';
    path[b + 2] = 'p';
    path[b + 3] = 'm';
    path[b + 4] = '\0';
    free(ptr);
    return(path);
}