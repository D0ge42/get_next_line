#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

char	*find_new_line(char *stash)
{
	int		i;
	char	*new_stash;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i += 1;
	j = i;
	while (stash[j])
		j++;
	new_stash = malloc(sizeof(char) * (j - i) + 1);
	if (((j - i) == 0 && !ft_strchr(stash, '\n')) || !new_stash)
	{
		free(new_stash);
		return (NULL);
	}
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

	if (!str)
		return (NULL);
	i = 0;
	if (str)
		linelenght = linelen(str);
	else
		linelenght = ft_strlen(str);
	line = malloc(sizeof(char) * linelenght + 1);
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
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return NULL;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			temp = stash;
			stash = ft_strjoin(stash, buf);
			free(temp);
			break ;
		}
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	line = extract_line(stash);
	temp = stash;
	stash = find_new_line(stash);
	free(temp);
	return (line);
}

/*int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	i = 37;
	while (i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
}*/