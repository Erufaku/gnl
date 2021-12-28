#include "get_next_line_bonus.h"

char*	ft_strchr(const char *s, int c)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)s;
	while (a[i] != (char)c && a[i] != '\0')
		i++;
	if (a[i] == (char)c)
		return (a + i);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) > len)
		p = (char *)malloc(len + 1);
	else
		p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_strrem(char **string)
{
	if (string)
	{
		free(*string);
		*string = (void *)0;
	}
}

char	*string_creator(int fd, char **string)
{
	int		i;
	char	*line;
	char	*saver;

	i = 0;
	line = (void *)0;
	while (string[fd][i] && string[fd][i] != '\n')
		i++;
	if (!string[fd][i])
	{
		line = ft_strdup(string[fd]);
		ft_strrem(&string[fd]);
	}
	else if (string[fd][i] == '\n')
	{
		line = ft_substr(string[fd], 0, i + 1);
		saver = ft_strdup(string[fd] + i + 1);
		ft_strrem(&string[fd]);
		string[fd] = saver;
		if (string[fd][0] == '\0')
			ft_strrem(&string[fd]);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*saver;
	char		buf[BUFFER_SIZE + 1];
	static char	*string[10200];

	if (fd < 0 || fd > 10199 || BUFFER_SIZE <= 0)
		return ((void *)0);
	bytes = read(fd, buf, BUFFER_SIZE);
	while (bytes > 0)
	{
		*(buf + bytes) = '\0';
		if (!*(string + fd))
			*(string + fd) = ft_strdup("");
		saver = ft_strjoin(*(string + fd), buf);
		ft_strrem(string + fd);
		*(string + fd) = saver;
		if (ft_strchr(*(string + fd), '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes < 0 || (bytes == 0 && !*(string + fd)))
		return ((void *)0);
	return (string_creator(fd, string));
}
