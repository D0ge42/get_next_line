#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

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
	line = malloc(sizeof(char) * linelenght);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	else
		line[i] = '\0';
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	int			bytes_read;
	char		*line;
	char		*str;

	buf = malloc(sizeof(char ) * BUFFER_SIZE + 1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read != 0)
	{
		buf[bytes_read] = '\0';
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
	free(buf);
	stash = str;
	return (line);
}

int	main(void)
{
	int	fd;
	int	i;

	fd = open("file.txt", O_RDONLY);
	// Change how many lines you wanna read.
	i = 22;
	while (i)
	{
		printf("%s", get_next_line(fd));
		i--;
	}
	// printf("%s",extract_line("1\n\n1\n1\n1\n\n1"));
}
