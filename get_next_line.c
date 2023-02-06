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
	int				readed;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	//1. read puis stocker dans liste
	read_addlst(fd, &list, &readed);
	if (list == NULL)
		return (NULL);
	//2. extraire la ligne de la liste
	make_line(list, &line);
	//3. clear la liste pour plus tard
	clear_list(list);
	return (line);
}

void	read_addlst(int fd, t_list **list, int *readed_ptr)
{
	char	*buffer;

	while (!found_newline(*list) && *readed_ptr != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if	(!buffer)
			return ;
		*readed_ptr = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && *readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buffer);
			return ;
		}
		buffer[*readed_ptr] = '\0';
		addlst(list, buffer, *readed_ptr);
		free(buffer);
	}
}

void	addlst(t_list **list, char *buffer, int readed)
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
	while (new_node->data[i] && i < readed)
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
	last = *list;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	make_line(t_list *list, char **line)
{
	t_list	*temp;
	size_t	len;
	size_t	i;

	len = 0;
	temp = list;
	line = malloc(sizeof(char) * (line_len(list) + 1));
	while (list != NULL)
	{
		i = 0;
		while (list->data[i] && list->data[i] != '\n')
		{
			*line[len] = list->data[i];
			len++;
			i++;
		}
		list = list->next;
	}
}

void	clear_list(t_list **list)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	while (*list != NULL)
	{
		temp = *list;
		free(temp->data);
		free(temp);
		*list = (*list)->next;
	}
	while ()
	{
		 
	}
}

#include <fcntl.h>

int main()
{
	int fd = open("book.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
