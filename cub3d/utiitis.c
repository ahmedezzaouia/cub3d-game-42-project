/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiitis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:10:44 by mabdelou          #+#    #+#             */
/*   Updated: 2022/08/04 12:10:46 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "haider.h"

int ft_strlen(char *str)
{
    int a;

    a = 0;
    while(str[++a])
        ;
    return (a + 1);
}

char	*ft_strdup(char *s1)
{
	char			*cpy;
	size_t			a;
	size_t			len;

	a = 0;
	len = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (cpy == NULL)
		return (NULL);
	while (s1[a])
	{
		cpy[a] = s1[a];
		a++;
	}
	cpy[a] = '\0';
	return (cpy);
}

int ft_strcmp(char *S1, char *S2)
{
    int a;
    int result;

    result = 0;
    a = -1;
    while(S1[++a] && S2[a])
       if(S1[a] != S2[a])
            result = -1;
    if(S1[a] != '\0' || S2[a] != '\0')
        result = -1;
    return(result);
}
int ft_strncmp2(char *S1, char *S2, int num)
{
    int a;
    int b;
    int c;
    int loop;

    a = ft_strlen(S1);
    b = ft_strlen(S2);
    loop = 0;
    c = 0;
    while(a && b && loop < num)
       if(S1[--a] != S2[--b])
            c = -1;
    if(b)
        c = -1;
    return(c);
}