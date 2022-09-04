/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:14:07 by ahmez-za          #+#    #+#             */
/*   Updated: 2021/11/21 12:06:16 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static int	ft_count_word(char *str, char sep)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (i == 0 && !ft_is_sep(str[i], sep))
			counter++;
		else if (i > 0 && \
				!ft_is_sep(str[i], sep) && ft_is_sep((str[i - 1]), sep))
			counter++;
		i++;
	}
	return (counter);
}

static int	*ft_count_size(char *str, char sep)
{
	int	i;
	int	index;
	int	*arr;
	int	size;

	size = ft_count_word(str, sep);
	arr = (int *) ft_calloc(size, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		if (!ft_is_sep(str[i], sep))
			arr[index]++;
		else if (i > 0 && \
				ft_is_sep(str[i], sep) && !ft_is_sep(str[i - 1], sep))
			index++;
		i++;
	}
	return (arr);
}

static void	ft_strncpy(char *src, char *dest, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	**ft_split(const char *str, char sep)
{
	int		i;
	int		index;
	int		*word;
	char	**words;

	if (!str)
		return (NULL);
	words = ft_calloc((ft_count_word((char *)str, sep) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	word = ft_count_size((char *)str, sep);
	i = -1;
	index = 0;
	while (str[++i])
	{
		if ((i == 0 && !ft_is_sep(str[i], sep)) || \
				(!ft_is_sep(str[i], sep) && ft_is_sep(str[i - 1], sep)))
		{
			words[index] = malloc(sizeof(char) * (word[index] + 1));
			ft_strncpy((char *)str + i, words[index], word[index]);
			index++;
		}
	}
	free(word);
	return (words);
}
