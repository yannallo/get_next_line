/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:44:09 by yallo             #+#    #+#             */
/*   Updated: 2023/01/30 15:44:09 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	read_addlst(fd, &list);
	if (list == NULL)
		return (NULL);
	make_line(list, &line);
	if (line[0] == '\0')
	{
		free_list(&list);
		free(line);
		return (NULL);
	}
	clear_list(&list);
	return (line);
}

void	read_addlst(int fd, t_list **list)
{
	int		readed;
	char	*buffer;

	readed = 1;
	while (!check_newline(*list) && readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((list == NULL && readed == 0) || readed == -1)
			return (free(buffer));
		buffer[readed] = '\0';
		add_list(list, buffer, readed);
		free(buffer);
	}
}

void	add_list(t_list **list, char *buffer, int readed)
{
	size_t	i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->data = malloc(sizeof(char) * (readed + 1));
	if (new_node->data == NULL)
		return ;
	i = 0;
	while (buffer[i])
	{
		new_node->data[i] = buffer[i];
		i++;
	}
	new_node->data[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = last_node(*list);
	last->next = new_node;
}

void	make_line(t_list *list, char **line)
{
	size_t	len;
	size_t	i;

	malloc_line(list, line);
	if (*line == NULL)
		return ;
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->data[i])
		{
			(*line)[len] = list->data[i];
			len++;
			if (list->data[i] == '\n')
				break ;
			i++;
		}
		list = list->next;
	}
	(*line)[len] = '\0';
}

void	clear_list(t_list **list)
{
	int		i;
	t_list	*last;

	i = 0;
	last = last_node(*list);
	while (last->data[i] != '\n')
	{
		if (last->data[i] == '\0')
		{
			free_list(list);
			return ;
		}
		i++;
	}
	add_list(list, &(last->data[i + 1]), ft_strlen(last->data) - i);
	while ((*list)->next != NULL)
	{
		last = *list;
		(*list) = (*list)->next;
		free(last->data);
		free(last);
	}
}

/*#include <fcntl.h>

int main()
{
	char *line;
	int i = 0;
	int fd = open("book.txt", O_RDONLY);

	while (i == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
}*/