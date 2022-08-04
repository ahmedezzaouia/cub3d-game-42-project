/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:41 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/16 00:50:18 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	int		c;
	char	*arr;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	c = ft_strlenn(s1) + ft_strlenn(s2);
	a = -1;
	arr = (char *)malloc((c + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (s1[++a] != '\0' && a < c)
		arr[a] = s1[a];
	b = -1;
	while (s2[++b] != '\0' && (a + b) < c)
		arr[a + b] = s2[b];
	arr[a + b] = '\0';
	free(s1);
	free(s2);
	return (arr);
}