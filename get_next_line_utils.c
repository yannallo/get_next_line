/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:19:50 by yallo             #+#    #+#             */
/*   Updated: 2022/12/23 15:19:50 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

t_list *ft_newlst(char *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **head_ref, char *buffer)
{
	t_list *new_node;
	t_list *last = *head_ref;

	new_node = malloc(sizeof(t_list));
	new_node->data = buffer;
	new_node->next = NULL;
	if (*head_ref == NULL) 
	{
    	*head_ref = new_node;
    	return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
