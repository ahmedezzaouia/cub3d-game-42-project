/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:14:45 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 18:20:45 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_new_node(t_map **head, char *str)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	new->content = str;
	new->next = NULL;
	ft_lstadd_back_min(head, new);
}

void	init_linked_list(char *path, t_map **head, int reach_map)
{
	int		fd;
	char	*trim;
	char	*str;

	reach_map = 0;
	fd = open (path, O_RDONLY);
	if (fd == -1)
		ft_err("Error: Can't open file\n");
	while ((str = get_next_line(fd)) != NULL)
	{
		trim = ft_strtrim(str, " ");
		if (trim[0] == '1')
			reach_map = 1;
		if (ft_strlen_lib(trim) == 1 && !reach_map)
		{
			free(str);
			free(trim);
			continue ;
		}
		add_new_node(head, str);
		free(trim);
	}
	close(fd);
}

void	validate_map(s_cub *cub, char *path)
{
	int		reach_map;
	t_map	*head;

	reach_map = 0;
	head = NULL;
	check_extension(path);
	init_linked_list(path, &head, reach_map);
	if (!head)
		ft_err("Error: map is not filled correctly\n");
	check_empty_line(head);
	check_double(head);
	check_elements(head, cub);
	check_color(cub->floor_color);
	check_color(cub->ceilling_color);
	fill_the_map(head, cub);
	cub->f_rgb = get_rgb_color(cub->floor_color);
	cub->c_rgb = get_rgb_color(cub->ceilling_color);
	free_list(head);
	printf("\x1B[32m valid map\n");
}
