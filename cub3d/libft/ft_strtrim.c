/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:29:56 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/05 18:39:56 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*trim_str;
	char	*k;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_is_set(s1[i], (char *)set))
		i++;
	k = ft_strchr(s1, (char)s1[i]);
	len = ft_strlen_lib(k) - 1;
	if (ft_strlen_lib(k) == 0)
		return (ft_calloc(1, sizeof(char)));
	while (len >= 0 && ft_is_set(k[len], (char *)set))
		len--;
	len++;
	trim_str = ft_substr(k, 0, len);
	return (trim_str);
}
