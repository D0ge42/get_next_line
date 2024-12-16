#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 4

typedef struct s_list
{
    void *data;
    struct s_list *next;
}       t_list;

t_list *lstnew(void *data);
void print_list(t_list *list);
int ft_strchr(char *str, char c);
void lst_add_back(t_list **list, t_list *node);
char *ft_strdup(char *str);
char *extract_line(char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
int clear_until_newline(char *str);

#endif // !GET_NEXT_LINE_H
