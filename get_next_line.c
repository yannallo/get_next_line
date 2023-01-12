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

char	*get_next_line(int fd)
{
	char	buffer[8];
	t_list	**list;
	t_list	*tmp;

	//(*list) = ft_newlst("First node"); //Origine probleme == **list essayer plutot *list;
	while (check(buffer) == 0 && read(fd, buffer, 8))
	{
		tmp = ft_newlst(buffer);
		printf("%s", tmp->data);
		ft_lstadd_back(list, tmp);
	}
	/*while ((*list)->next)
	{
		printf("%s", (*list)->data);
		list = &(*list)->next;
	}*/
	return ("WOW");
}

#include <fcntl.h>

int main(void)
{
	int fd = open("book.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}