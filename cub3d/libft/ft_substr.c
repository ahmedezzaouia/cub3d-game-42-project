/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:54:19 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/19 14:26:48 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*new_str;

	if (!s)
		return (NULL);
	if (start > ft_strlen_lib(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen_lib(s))
		new_str = malloc((ft_strlen_lib(s) - start) * sizeof(char) + 1);
	else
		new_str = malloc(len * sizeof(char) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
