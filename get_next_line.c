/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:17:07 by yallo             #+#    #+#             */
/*   Updated: 2022/12/23 15:17:07 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	check(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (-1);
		i++;
	}
	return (0);
}

void	printlst(t_list *list)
{
	int i = 0;
	t_list	*new;

	while (list->next)
	{
		new = list;
		printf("%d == %p == %s\n", i, list, list->data);
		list = list->next;
		free(new);
		i++;
	}
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	t_list	*list;

	list = NULL;
	while (check(buffer) == 0 && read(fd, buffer, BUFFER_SIZE) != 0)
	{
		ft_lstadd_back(&list, buffer);
	}
	printlst(list);
	return ("WOW");
}

#include <fcntl.h>

int main(void)
{
	int i = 0;
	int fd = open("book.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
