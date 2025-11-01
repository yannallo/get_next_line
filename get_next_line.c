#include "get_next_line.h"

char *read_fd(int fd, char *stash)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t readed = 1;

	while (!ft_strchr(stash, '\n') && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			if (stash)
				free(stash);
			return NULL;
		}
		buffer[readed] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return NULL;
	}
	return stash;
}

char *extract_line(char *stash)
{
	size_t i = 0;
	char *line = NULL;

	if (!stash)
		return NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i])
		i++;
	line = ft_substr(stash, 0, i);
	return line;
}

char *extract_buffer(char *stash)
{
	size_t i = 0;
	char *buf = NULL;

	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return NULL;
	}
	buf = ft_substr(stash, i+1, ft_strlen(stash) - i - 1);
	free(stash);
	return buf;
}

char *get_next_line(int fd)
{
	static char *stash;
	char *line;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return NULL;
	stash = read_fd(fd, stash);
	line = extract_line(stash);
	stash = extract_buffer(stash);
	return line;
}
