#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif
typedef struct s_list
{
    void *data;
    struct s_list *next;
}       t_list;

int ft_strcmp(char *s1, char *s2);
int ft_strchr(char *str, char c);
char *extract_line(char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
char *ft_strdup(char *str);
int linelen(char *str);

#endif // !GET_NEXT_LINE_H
