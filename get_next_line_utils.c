#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return 0;
	i = 0;
	while (s[i])
		i++;
	return i;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t slen;
	char *buf;

	if (!s)
		return NULL;
	slen = ft_strlen(s);
	if (start >= slen)
		return NULL;
	if (len > slen - start)
		len = slen - start;
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return NULL;
	i = 0;
	while (i < len)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return buf;
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return NULL;
	while (*s)
	{
		if (*s == (char) c)
			return (char *) s;
		s++;
	}
	if (*s == (char) c)
		return (char *) s;
	return NULL;
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t i;
	size_t j;
	char *buf;

	if (!s1 && !s2)
		return NULL;
	buf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buf)
		return NULL;
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		buf[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		buf[j] = s2[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	free(s1);
	return buf;
}

