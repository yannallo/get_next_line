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

int	found_newline(t_list *head_ref)
{
	size_t	i;
	t_list	*last;

	if (head_ref == NULL)
		return (0);
	last = head_ref;
	while (last->next != NULL)
		last = last->next;
	i = 0;
	while (last->data[i])
	{
		if (last->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	line_len(t_list *list)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->data[i])
		{
			if (list->data[i] != '\n')
				return (len++);
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*lstnode(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
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