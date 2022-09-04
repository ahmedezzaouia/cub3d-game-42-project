/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:54:51 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/19 14:26:34 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mapped_str;

	i = 0;
	if (!s || !f)
		return (NULL);
	mapped_str = ft_calloc(ft_strlen_lib(s) + 1, sizeof(char));
	if (!mapped_str)
		return (NULL);
	while (s[i])
	{
		mapped_str[i] = f(i, s[i]);
		i++;
	}
	return (mapped_str);
}
