/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:14:45 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 02:58:27 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    ft_err(char *msg)
{
    printf("\x1B[31m %s", msg);
    exit(1);
}

void     handle_elements(char *str, s_cub *cub)
{
    char *join;
    char *new;
    int fd;

    new = ft_strtrim(str, " \n  ");
    if (new[0] == 'F')
    {
        cub->floor_color =  ft_strdup(ft_strtrim(new + 2 , " "));
        return ;
    }
    else if (new[0] == 'C')
    {
        cub->ceilling_color = ft_strdup(ft_strtrim(new + 2 , " "));
        return ;
    }
    join = ft_strjoin(new + 2 , ft_strdup(".xpm"));
    join = ft_strtrim(join, " \n  ");
    printf("%s\n", join);
    fd = open(join, O_RDONLY);
    if (fd == -1)
    {
        printf("\x1B[31m image path not found\n");
        exit(1);
    }
    if (new[0] == 'N' && new[1] == 'O')
        cub->north_path = ft_strdup(join);
    else if (new[0] == 'S' && new[1] == 'O')
        cub->south_path = ft_strdup(join);
    else if (new[0] == 'W' && new[1] == 'E')
        cub->west_path = ft_strdup(join);
    else if (new[0] == 'E' && new[1] == 'A')
        cub->east_path = ft_strdup(join);
    free(join);
    free(new);
    close(fd);
}

void	ft_lstadd_back_min(t_map **lst, t_map *new)
{
	t_map	*temp;

	if (new == NULL)
		return ;
	if (*lst)
	{
		temp = (*lst);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
	{
		*lst = new;
	}
}

void check_empty_line(t_map *head)
{
    while (head)
    {
        if (ft_strlen_lib(head->content) == 1)
        {
            printf("Error: empty line\n");
            exit(1);
        }
        head = head->next;
    }
}

void    check_elements(t_map *head, s_cub *cub)
{
    int     i;

    i = 0;
    (void)cub;
    (void)head;
    while (i < 6 && head)
    {
        handle_elements(head->content, cub);
        head = head->next;
        i++;
    }
    
}

void    check_color(char *color)
{
    char    **split;
    int     i;

    i = 0;
    split = ft_split(color, ',');
    while (split[i])
        i++;
    if (i != 3)
    {
        printf("\x1B[31m Error: collor is not correct\n");
        exit(1);
    }
    i = 0;
    while (split[i])
    {
        printf("split[%d] == %d\n", i, ft_atoi(split[i]));
        if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
        {
            printf("errsplit[%d] == %d\n", i, ft_atoi(split[i]));
            
            printf("\x1B[31m Error color numbers range\n");
            exit(1);
        }
        i++;
    }
}

int calcule_map_lines(t_map *head)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (head)
    {
        head = head->next;
        if (i > 5)
            len++;
        i++;
    }
    return (len);
}

void check_is_surrounded(s_cub *cub)
{
    int i;
    char *str;

    i = 0;
    while (cub->map_buffer[i])
    {
        str = cub->map_buffer[i];
        if (str[0] != '1' && str[ft_strlen_lib(str) - 1] != '1')
        {
            printf("Error: map is not surrounded by wall\n");
            exit(1);
        }
        i++;
    }
    
}

int    is_valid_char(char c)
{
    if (c == '0')
        return (1);
    else if (c == '1')
        return (1);
    else if (c == 'S')
        return (1);
    else if (c == 'W')
        return (1);
    else if (c == 'E')
        return (1);
    else if (c == 'S')
        return (1);
    else if (c == 'N')
        return (1);
    else if (c == ' ')
        return (1);
    else
        return (0);
}

void check_is_one_player(char c, int *players)
{
    if (c != '0' && c != '1' && c != ' ')
    {
        (*players)++;
    }
}

void    check_map_characthers(s_cub *cub)
{
    int i;
    int j;
    char *str;
    int  players;

    i = 0;
    players = 0;
    while (cub->map_buffer[i])
    {
        j = 0;
        str = cub->map_buffer[i];
        while (str[j])
        {
            if (!is_valid_char(str[j]))
                ft_err("Error: unvalide character\n");
            check_is_one_player(str[j], &players);
            if (str[j] != ' ' && str[j] != '1')
            {    
                if (!str[j - 1] || !str[j + 1] || \
                    !cub->map_buffer[i - 1][j] || !cub->map_buffer[i + 1][j])
                    ft_err("Error: Map is not valide\n");
                if (str[j] == '0' && cub->map_buffer[i + 1][j] == ' ')
                    ft_err("Error: Map is not valide\n");

            }
            
            j++;
        }
        i++;
    }
    printf("player == %d\n", players);
    if (players != 1)
        ft_err("Error: should be one player\n");
}

void    fill_the_map(t_map *head, s_cub *cub)
{
    int i;
    int j;
    char *trim;

    i = 0;
    j = 0;
    trim = NULL;
    cub->map_buffer = ft_calloc(sizeof(char *), calcule_map_lines(head) + 1);
    while (head)
    {
        if (i > 5)
        {
            trim = ft_strtrim(head->content, "\n");
            cub->map_buffer[j] = ft_strdup(trim);
            j++;
            free(trim);
        }
        head = head->next;
        i++;
    }
    check_is_surrounded(cub);
    check_map_characthers(cub);
    // check_is_one_player(cub);
}

void check_extension(char *map)
{
    char *str;

    str = ft_strrchr(map, '.');
    if (str == NULL)
    {
        printf("Error: map path must end buy .cub\n");
        exit(1);
    }
    if (ft_strncmp(str + 1, "cub", 4) != 0)
    {
        printf("Error: map path must end buy .cub\n");
        exit(1);
    }
}


void    free_list(t_map *head)
{
    t_map *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

void validate_map(s_cub *cub, char *path)
{
    int fd;
    char *trim;
    char *str;
    int reach_map;
    t_map *head;
    t_map *new;

    reach_map = 0;
    head = NULL;
    check_extension(path);
    fd = open (path, O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        trim = ft_strtrim(str, " ");
        if (trim[0] == '1')
            reach_map = 1;
        if (ft_strlen_lib(trim) == 1 && !reach_map)
        {
            free(str);
            free(trim);
            continue;
        }
        new = malloc(sizeof(t_map));
        new->content = str;
        new->next = NULL;
        ft_lstadd_back_min(&head, new);
        free(trim);
    }
    close(fd);
    if (!head)
    {
        printf("Error: map is not filled correctly\n");
        exit(1);
    }
    check_empty_line(head);
    check_elements(head, cub);
    check_color(cub->floor_color);
    check_color(cub->ceilling_color);
    fill_the_map(head, cub);
    cub->f_rgb = get_rgb_color(cub->floor_color);
	cub->c_rgb = get_rgb_color(cub->ceilling_color);
    free_list(head);
    printf("\x1B[32m valid map\n");
}

