/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:20:39 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_the_map(t_map *head, t_cub *cub)
{
	int		i;
	int		j;
	char	*trim;

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
}

void	check_extension(char *map)
{
	char	*str;

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

void	free_list(t_map *head)
{
	t_map	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
