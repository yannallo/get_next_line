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

int	check(char *buffer)
{
	size_t	i;

	i = 0;
	if (buffer[i] == '\0')
		return (1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	size_of(t_list *head)
{
	t_list	*tmp;
	size_t	count;
	size_t	i;

	tmp = head;
	count = 0;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->data[i] != '\n' && tmp->data[i] != '\0')
		{
			count++;
			i++;
		}
		tmp = tmp->next;
	}
	return (count + 1);
}

char	*make_line(t_list *head, char *buffer)
{
	int		i_list;
	int		count;
	char	*line;

	count = 0;
	line = malloc(sizeof(char) * size_of(head));
	while (head != NULL)
	{
		i_list = 0;
		while (i_list < BUFFER_SIZE)
		{
			line[count] = head->data[i_list];
			count++;
			i_list++;
		}
		head = head->next;
	}
	line[count] = '\0';
	return (line);
}

void	ft_free(t_list *list)
{
	size_t	i;
	t_list	*head;

	while (list->next != NULL)
	{
		head = list;
		list = list->next;
		free(head->data);
		free(head);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	list = NULL;
	while (read(fd, buffer, BUFFER_SIZE) != 0 && check(buffer) == -1)
		ft_lstadd_back(&list, buffer);
	line = make_line(list, buffer);
	ft_free(list);
	return (line);
}

#include <fcntl.h>

int main(void)
{
	char *line;
	int i = 0;
	int fd = open("book.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
}
