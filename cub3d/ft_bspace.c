/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:45:14 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/16 00:32:27 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

char	*ft_bspace(char *st, size_t len)
{
	char	*str;
	size_t	i;
	size_t	a;

	a = -1;
	i = len;
	str = st;
	while (++a < i)
		str[a] = ' ';
	str[a] = '\n';
	str[a + 1] = '\0';
	return (str);
}
/*
int main ()
{
	char *b;
	char *c;
	char a[] = "hello there who are you ?";
	char d[] = "hello there who are you ?";
	b = ft_bzero(a,-2147483650);
	c = bzero(b,2147483650);
	printf("%s\n%s\n",a);

}*/
