#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

char                *get_next_line(int fd);
int					ft_strchr(char *str, char c);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *str);
char				*ft_strdup(char *str);

#endif // !GET_NEXT_LINE_H
