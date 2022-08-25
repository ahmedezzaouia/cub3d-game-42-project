/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_of_map_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:03:08 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 12:03:09 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_path_of_map_file(char *path)
{
	if (ft_strncmp2(path, ".cub", 4) == -1)
		ft_error("bad path of map file");
	else if (ft_strcmp(path, ".cub") == 0)
		ft_error("bad path of map file");
}