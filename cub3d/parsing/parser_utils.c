/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:17:39 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_err(char *msg)
{
	printf("\x1B[31m %s", msg);
	exit(1);
}

void	fill_colors(t_cub *cub, char *new)
{
	if (new[0] == 'F')
	{
		cub->floor_color = ft_strdup(ft_strtrim(new + 2, " "));
	}
	else if (new[0] == 'C')
	{
		cub->ceilling_color = ft_strdup(ft_strtrim(new + 2, " "));
	}
}

void	fill_elemenets(t_cub *cub, char *new, char *join)
{
	if (new[0] == 'N' && new[1] == 'O')
		cub->north_path = ft_strdup(join);
	else if (new[0] == 'S' && new[1] == 'O')
		cub->south_path = ft_strdup(join);
	else if (new[0] == 'W' && new[1] == 'E')
		cub->west_path = ft_strdup(join);
	else if (new[0] == 'E' && new[1] == 'A')
		cub->east_path = ft_strdup(join);
}

void	handle_elements(char *str, t_cub *cub)
{
	char	*join;
	char	*new;
	int		fd;

	new = ft_strtrim(str, " \n  ");
	if (new[0] == 'F' || new[0] == 'C')
	{
		fill_colors(cub, new);
		return ;
	}
	join = ft_strjoin(new + 2, ft_strdup(".xpm"));
	join = ft_strtrim(join, " \n  ");
	fd = open(join, O_RDONLY);
	if (fd == -1)
		ft_err("image path not found\n");
	fill_elemenets(cub, new, join);
	free(join);
	free(new);
	close(fd);
}

void	check_double(t_map *head)
{
	char	*trim;
	int		i;

	i = 0;
	while (head)
	{
		trim = ft_strtrim(head->content, " ");
		if (trim[0] == '1')
			break ;
		head = head->next;
		i++;
		free(trim);
	}
	free(trim);
	if (i > 6)
		ft_err("Error: double lines\n");
}
