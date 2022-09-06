/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:14:45 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/06 10:07:01 by ahmez-za         ###   ########.fr       */
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

	fd = open (path, O_RDONLY);
	if (fd == -1)
		ft_err("Error: Can't open file\n");
	str = get_next_line(fd);
	while ((str) != NULL)
	{
		trim = ft_strtrim(str, " \t ");
		if (trim[0] == '1')
			reach_map = 1;
		if (ft_strlen_lib(trim) == 1 && !reach_map)
		{
			free(str);
			free(trim);
			str = get_next_line(fd);
			continue ;
		}
		add_new_node(head, str);
		free(trim);
		str = get_next_line(fd);
	}
	close(fd);
}

int	get_list_lk_len(t_map *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	validate_map(t_cub *cub, char *path)
{
	int		reach_map;
	t_map	*head;

	reach_map = 0;
	head = NULL;
	check_extension(path);
	init_linked_list(path, &head, reach_map);
	if (!head)
		ft_err("Error: No Data\n");
	if (get_list_lk_len(head) < 6)
		ft_err("Error: Missing some lines\n");
	if (get_list_lk_len(head) == 6)
		ft_err("Error: the map not found\n");
	check_empty_line(head);
	check_double(head);
	check_elements(head, cub);
	check_color(cub->floor_color, cub, 1);
	check_color(cub->ceilling_color, cub, 0);
	fill_the_map(head, cub);
	free_list(head);
	printf("\x1B[32m valid map\n");
}
