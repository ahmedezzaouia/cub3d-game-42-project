/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:19:41 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/06 12:00:02 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_is_surrounded(t_cub *cub)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (cub->map_buffer[i])
	{
		str = cub->map_buffer[i];
		j = 0;
		while (str[j] == ' ')
			j++;
		if (str[j] != '1' || str[ft_strlen_lib(str) - 1] != '1')
		{
			printf("Error: map is not surrounded by wall\n");
			exit(1);
		}
		i++;
	}
}

int	is_valid_char(char c)
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
	else if (c == '\t')
		return (1);
	else
		return (0);
}

void	check_is_one_player(char c, int *players)
{
	if (c != '0' && c != '1' && c != ' ' && c != '\t')
	{
		(*players)++;
	}
}

void	check_playes_zero(t_cub *cub, char *str, int i, int j)
{
	if (str[j] != ' ' && str[j] != '1' && str[j] != '\t')
	{
		if (((int)ft_strlen_lib(cub->map_buffer[i + 1]) <= j || (int)ft_strlen_lib(cub->map_buffer[i - 1]) <= j))
			ft_err("Error: Map is not valide1111\n");
		// if (!str[j - 1] || !str[j + 1] || cub->map_buffer[i - 1][j] || cub->map_buffer[i + 1][j])
		if (str[j] == '0' && (cub->map_buffer[i + 1][j] == ' ' || \
			str[j + 1] == ' ' || \
			str[j - 1] == ' ' || cub->map_buffer[i - 1][j] == ' '))
			ft_err("Error: Map is not valide\n");
	}
}

void	check_map_characthers(t_cub *cub)
{
	int		i;
	int		j;
	char	*str;
	int		players;

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
			check_playes_zero(cub, str, i, j);
			j++;
		}
		i++;
	}
	if (players != 1)
		ft_err("Error: should be one player\n");
}
