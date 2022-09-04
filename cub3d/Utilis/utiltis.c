/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiltis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:54:17 by mabdelou          #+#    #+#             */
/*   Updated: 2022/09/04 19:14:41 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[++a])
		;
	return (a + 1);
}

// char	*ft_strdup(char *s1)
// {
// 	char	*cpy;
// 	size_t	a;
// 	size_t	len;

// 	a = 0;
// 	len = ft_strlen(s1);
// 	cpy = (char *)malloc(sizeof(char) * len + 1);
// 	if (cpy == NULL)
// 		return (NULL);
// 	while (s1[a])
// 	{
// 		cpy[a] = s1[a];
// 		a++;
// 	}
// 	cpy[a] = '\0';
// 	return (cpy);
// }

// int	ft_strcmp(char *S1, char *S2)
// {
// 	int	a;
// 	int	result;

// 	result = 0;
// 	a = -1;
// 	while (S1[++a] && S2[a])
// 		if (S1[a] != S2[a])
// 			result = -1;
// 	if (S1[a] != '\0' || S2[a] != '\0')
// 		result = -1;
// 	return (result);
// }

// int	ft_strncmp2(char *S1, char *S2, int num)
// {
// 	int	a;
// 	int	b;
// 	int	c;
// 	int	loop;

// 	a = ft_strlen(S1);
// 	b = ft_strlen(S2);
// 	loop = 0;
// 	c = 0;
// 	while (a && b && loop < num)
// 		if (S1[--a] != S2[--b])
// 			c = -1;
// 	if (b)
// 		c = -1;
// 	return (c);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	char	*arr;

// 	if (s1 == NULL)
// 	{
// 		s1 = malloc(sizeof(char) * 1);
// 		s1[0] = '\0';
// 	}
// 	if (s2 == NULL)
// 		return (NULL);
// 	c = ft_strlenn(s1) + ft_strlenn(s2);
// 	a = -1;
// 	arr = (char *)malloc((c + 1) * sizeof(char));
// 	if (arr == NULL)
// 		return (NULL);
// 	while (s1[++a] != '\0' && a < c)
// 		arr[a] = s1[a];
// 	b = -1;
// 	while (s2[++b] != '\0' && (a + b) < c)
// 		arr[a + b] = s2[b];
// 	arr[a + b] = '\0';
// 	free(s1);
// 	free(s2);
// 	return (arr);
// }