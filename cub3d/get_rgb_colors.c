/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:51:06 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 18:51:17 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

int *get_rgb_color(char *str)
{
    int a;
    int b;
    int *num;

    if(!str)
    {
        write(2,"there is no element_color \n",27);
        exit(1);
    }
    num = malloc(sizeof(int) * 3);
    if(!num)
    if(!num)
    {
        write(2,"Erorr : can't allocated\n",24);
        exit(1);
    }
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    a = 1;
    b = 0;
    while(str[++a])
    {
        if(str[a] == ',' || str[a] == '\n')
        {
            num[b] /= 10;
            
            ++b;
        }
        if(str[a] > 47 && str[a] < 58)
        {
            num[b] += str[a] - 48;
            num[b] *= 10;
        }
    }
    return (num);
}