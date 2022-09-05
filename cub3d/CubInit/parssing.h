/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:20:07 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 21:20:08 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSSING_H
# define PARSSING_H

typedef struct s_list
{
	int		a;
	int		b;
	int		c;
	int		up_bad_map;
	int		down_bad_map;
	int		right_bad_map;
	int		left_bad_map;
	char	*str;
}	t_list;

#endif