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

size_t	ft_strlen(const char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(buf))
		return (0);
	while (str[i] != '\0')
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

void	ft_lstadd_back(t_list **head_ref, char *buffer)
{
	t_list	*new_node;
	t_list	*last;

	if (buffer == NULL)
		return ;
	last = *head_ref;
	new_node = malloc(sizeof(t_list));
	new_node->data = ft_strdup(buffer);
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}
