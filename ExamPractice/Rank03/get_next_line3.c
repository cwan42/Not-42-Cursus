#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (*s);
		s++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *src)
{
	int	len = ft_strlen(src + 1);
	char	*dst = malloc(len);

	if (!dst)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	BUFFER[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	line = ft_strdup(buf);
}
