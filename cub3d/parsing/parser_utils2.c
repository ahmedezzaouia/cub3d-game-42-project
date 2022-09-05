/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:18:47 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 22:29:30 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	check_empty_line(t_map *head)
{
	while (head)
	{
		if (ft_strlen_lib(head->content) == 1)
			ft_err("Error: Empty line\n");
		head = head->next;
	}
}

void	check_elements(t_map *head, t_cub *cub)
{
	int	i;

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

void	check_color(char *color)
{
	char	**split;
	int		i;

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
			printf("\x1B[31m Error color numbers range\n");
			exit(1);
		}
		i++;
	}
}

int	calcule_map_lines(t_map *head)
{
	int	i;
	int	len;

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
