/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:17:39 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/06 18:29:26 by ahmez-za         ###   ########.fr       */
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
	char	*color;

	if (new[0] == 'F')
	{
		if (cub->floor_color)
			ft_err("Error: can't get floor color\n");
		color = ft_strtrim(new + 2, " ");
		cub->floor_color = color;
	}
	else if (new[0] == 'C')
	{	
		if (cub->ceilling_color)
			ft_err("Error: can't get ceilling color\n");
		color = ft_strtrim(new + 2, " ");
		cub->ceilling_color = color;
	}
	free(new);
}

void	fill_elemenets(t_cub *cub, char *new, char *join)
{
	if (new[0] == 'N' && new[1] == 'O')
		cub->north_path = join;
	else if (new[0] == 'S' && new[1] == 'O')
		cub->south_path = join;
	else if (new[0] == 'W' && new[1] == 'E')
		cub->west_path = join;
	else if (new[0] == 'E' && new[1] == 'A')
		cub->east_path = join;
}

void	handle_elements(char *str, t_cub *cub)
{
	char	*join;
	char	*new;
	int		fd;
	char	*xpm;

	new = ft_strtrim(str, " \n  ");
	if (new[0] == 'F' || new[0] == 'C')
	{
		fill_colors(cub, new);
		return ;
	}
	xpm = ft_strjoin(new + 2, ".xpm");
	join = ft_strtrim(xpm, " \n  ");
	fd = open(join, O_RDONLY);
	if (fd == -1)
		ft_err("image path not found\n");
	fill_elemenets(cub, new, join);
	free(xpm);
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
		trim = ft_strtrim(head->content, " \t ");
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
