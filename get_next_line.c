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

static char	*read_fd(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	readed;

	readed = 1;
	while (!ft_strchr_gnl(stash, '\n') && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[readed] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i])
		i++;
	line = ft_substr_gnl(stash, 0, i);
	return (line);
}

static char	*extract_buffer(char *stash)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	buf = ft_substr_gnl(stash, i + 1, ft_strlen_gnl(stash) - i - 1);
	free(stash);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_fd(fd, stash);
	line = extract_line(stash);
	stash = extract_buffer(stash);
	return (line);
}
