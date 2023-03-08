/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:44:12 by yallo             #+#    #+#             */
/*   Updated: 2023/02/01 15:44:12 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}

int	check_newline(t_list *head_ref)
{
	size_t	i;
	t_list	*last;

	if (head_ref == NULL)
		return (0);
	last = last_node(head_ref);
	i = 0;
	while (last->data[i])
	{
		if (last->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	malloc_line(t_list *list, char **line)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->data[i])
		{
			len++;
			if (list->data[i] == '\n')
				break ;
			i++;
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

t_list	*last_node(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	free_list(t_list **list)
{
	t_list	*temp;

	while (*list != NULL)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->data);
		free(temp);
	}
}
