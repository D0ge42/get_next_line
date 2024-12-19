#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*find_new_line(char *stash)
{
	int		i;
	char	*new_stash;
	int		j;

	i = 0;
	// Find first new line.
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i += 1;
	j = i;
	// Find end
	while (stash[j])
		j++;
	// Allocate enough memory for new stash.
	new_stash = malloc(sizeof(char) * (j - i) + 1);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (new_stash);
}

int	linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + 1);
}

char	*extract_line(char *str)
{
	int		i;
	int		linelenght;
	char	*line;

	i = 0;
	linelenght = linelen(str);
	line = malloc(sizeof(char) * linelenght + 1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*stash;
	int			bytes_read;
	char		*line;
	char		*str;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read != 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			stash = ft_strjoin(stash, buf);
			break ;
		}
		stash = ft_strjoin(stash, buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	line = extract_line(stash);
	// Has to be fixed str = find_new_line(stash);
	str = find_new_line(stash);
	free(stash);
	stash = str;
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// Change how many lines you wanna read.
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
