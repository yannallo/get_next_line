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

void	printlst(t_list **list)
{
	while ((*list)->next)
	{
		printf("%s\n", (*list)->content);
		*list = (*list)->next;
	}
	printf("%s\n", (*list)->content);
}

int	check(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	char 	*buffer;
	t_list	**list;

	buffer = NULL;
	while (check(buffer) && read(fd, buffer, 5) != 0)
	{
		printf("buffer == %s\n", buffer);
	}
	return ("WoW");
}

#include <fcntl.h>

int main(void)
{
	int fd = open("book.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}