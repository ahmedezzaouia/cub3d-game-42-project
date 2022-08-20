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

#include "../cub3d.h"

void check_map_if_valid_3(s_cub *cub, t_list *lst)
{
    if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c]
        && cub->map_buffer[lst->a + 1][lst->b] == ' ')
        lst->up_bad_map = 1;
    else if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c]
        && (cub->map_buffer[lst->a - 1][lst->b] == ' '
        || lst->b > ft_strlen(cub->map_buffer[lst->a - 1] + 3)))
        lst->down_bad_map = 1;
    else if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c]
        && (cub->map_buffer[lst->a][lst->b + 1] == ' '
        || lst->b > ft_strlen(cub->map_buffer[lst->a + 1] + 3)))
        lst->right_bad_map = 1;
    else if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c]
        && cub->map_buffer[lst->a][lst->b - 1] == ' ')
        lst->left_bad_map = 1;
    if(lst->up_bad_map == 1 || lst->down_bad_map == 1
        || lst->right_bad_map == 1 || lst->left_bad_map == 1)
    {
        if(lst->up_bad_map == 1)
            printf("up bad map\n");
        else if(lst->down_bad_map == 1)
            printf("down bad map\n");
        else if(lst->left_bad_map == 1)
            printf("left bad map\n");
        else if(lst->right_bad_map == 1)
            printf("right bad map\n");
        exit(1);
    }
}

void check_map_if_valid_2(s_cub *cub, t_list *lst)
{
    lst->a = -1;
    while(cub->map_buffer[++lst->a])
    {
        lst->b = -1;
        while(cub->map_buffer[lst->a][++lst->b])
        {
            lst->c = -1;
            while(lst->str[++lst->c])
            {
                if(cub->map_buffer[0][lst->b] == lst->str[lst->c])
                    ft_error("bad map");
                else if(cub->map_buffer[lst->a][0] == lst->str[lst->c])
                    ft_error("bad map 2");
                else if(cub->map_buffer[lst->a][lst->b]== lst->str[lst->c]
                    && cub->map_buffer[lst->a + 1] == NULL)
                    ft_error("bad map 3");
                else if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c]
                    && cub->map_buffer[lst->a][lst->b + 1] == '\n')
                    ft_error("bad map 4");
                else if(cub->map_buffer[lst->a][lst->b] == lst->str[lst->c])
                    check_map_if_valid_3(cub,lst);
            }
        }
    }
}
void _lst_init(t_list *lst)
{
    lst->a = 0;
    lst->b = 0;
    lst->c = 0;
    lst->up_bad_map = 0;
    lst->down_bad_map = 0;
    lst->right_bad_map = 0;
    lst->left_bad_map = 0;
    lst->str = "0NWSE";
}

void check_map_if_valid(s_cub *cub)
{
    t_list lst;

    _lst_init(&lst);
    while(cub->map_buffer[++lst.a])
    {
        lst.b = -1;
        while(cub->map_buffer[lst.a][++lst.b])
        {
            if(cub->map_buffer[lst.a][lst.b] != '0' && cub->map_buffer[lst.a][lst.b] != '1'
                && cub->map_buffer[lst.a][lst.b] != 'N' && cub->map_buffer[lst.a][lst.b] != 'W'
                && cub->map_buffer[lst.a][lst.b] != 'S' && cub->map_buffer[lst.a][lst.b] != 'e'
                && cub->map_buffer[lst.a][lst.b] != ' ' && cub->map_buffer[lst.a][lst.b] != '\n')
            {
                write(2,"Eroor :bad map\n",15);
                exit(1);
            }
        }
    }
    check_map_if_valid_2(cub, &lst);
}