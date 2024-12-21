#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/*Function to update stash to the next new line.
Paramaters: Takes stash and make a new one out of it.*/

char	*update_stash(char *stash)
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

char	*extract_line(char *str, char *old_line)
{
	int		i;
	int		linelenght;
	char	*line;

	free(old_line);
	if (!str || ft_strlen(str) == 0)
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

char	*join_and_free(char *stash, char *buf)
{
	char	*temp;

	temp = stash;
	stash = ft_strjoin(stash, buf);
	free(temp);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	int			bytes_read;
	char		*temp;
	int FDS[1024];

	FDS[fd] = fd;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes_read = read(FDS[fd], line, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line[bytes_read] = '\0';
		stash = join_and_free(stash, line);
		if (ft_strchr(line, '\n'))
			break ;
		bytes_read = read(FDS[fd], line, BUFFER_SIZE);
	}
	line = extract_line(stash, line);
	temp = stash;
	stash = update_stash(stash);
	free(temp);
	return (line);
}


int	main(void)
{
	int		fd1;
	int		fd2;
	int		i;
	char	*line;

	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt",O_RDONLY);

	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd1));
	printf("%s",get_next_line(fd2));
}