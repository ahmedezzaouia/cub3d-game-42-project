/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:14:45 by ahmez-za          #+#    #+#             */
/*   Updated: 2022/09/04 16:00:37 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void     handle_elements(char *str)
{
    char *join;
    char *new;
    int fd;

    new = ft_strtrim(str, " \n  ");
    join = ft_strjoin(new + 2 , ft_strdup(".xpm"));
    join = ft_strtrim(join, " \n  ");

    printf("%s\n", join);
    fd = open(join, O_RDONLY);
    if (fd == -1)
    {
        printf("image not found\n");
        exit(1);
    }

    // if (join[0] == 'N' && join[1] == 'O')
    // {
    // }
    // else if (join[0] == 'S' && join[1] == 'O')
    // {

        
    // }
    // else if (join[0] == 'W' && join[1] == 'E')
    // {

        
    // }
    // else if (join[0] == 'E' && join[1] == 'A')
    // {
        
    // }


}

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

void check_empty_line(t_map *head)
{
    while (head)
    {
        if (ft_strlen(head->content) == 1)
        {
            printf("Error: empty line\n");
            exit(1);
        }
        head = head->next;
    }
    
}

void    check_elements(t_map *head)
{
    t_map *temp;
    int     i;

    temp = head;
    i = 0;
    while (i < 10)
    {
        handle_elements(temp->content);
        i++;
        temp = temp->next;
    }
    
}

void validate_map()
{
    int fd;
    char *trim;
    char *str;
    int reach_map;
    t_map *head;
    t_map *new;

    reach_map = 0;
    head = NULL;
    fd = open ("map.cub", O_RDONLY);   
    while ((str = get_next_line(fd)) != NULL)
    {
        trim = ft_strtrim(str, " ");
        if (trim[0] == '1')
            reach_map = 1;
        if (ft_strlen(trim) == 1 && !reach_map)
        {
            free(str);
            free(trim);
            continue;
        }
        new = malloc(sizeof(t_map));
        new->content = str;
        new->next = NULL;
        ft_lstadd_back_min(&head, new);
        free(trim);
    }
    close(fd);    
    check_empty_line(head);
    check_elements(head);
    printf("\x1B[32m valid map\n");
}

