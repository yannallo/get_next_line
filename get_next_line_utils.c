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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	ft_lstadd_back(t_list **head, char *buf)
{
	t_list	*tracer;

	tracer = *head;
	while (tracer->next)
		tracer = tracer->next;
	tracer->next = ft_newlst(buf);
}

#include <stdio.h>

int main(void)
{
	t_list	*list;

	list = ft_newlst("Bonjour");
	ft_lstadd_back(&list, "Bonsoir");
	ft_lstadd_back(&list, "Bonsoir");
	ft_lstadd_back(&list, "Bonnonn");
	while (list->next)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
	printf("%s\n", list->data);
}
