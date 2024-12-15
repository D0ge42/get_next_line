#include "get_next_line.h"


int ft_strchr(char *str, char c)
{
  while(*str)
  {
    if(*str == c)
      return 1;
    str++;
  }
  return 0;
}


int ft_strlen(char *str)
{
  int i = 0;
  while(str[i])
    i++;
  return i;
}

char *ft_strdup(char *str)
{
  int i = 0;
  int len = ft_strlen(str);
  char *new = malloc(sizeof(char ) * len + 1);
  while(str[i])
  {
    new[i] = str[i];
    i++;
  }
  return new;
}

void lst_add_back(t_list **list, t_list *node)
{
  t_list *temp;
  if(!(*list))
  {
    *list = node;
    return;
  }
  temp = *list;
  while(temp->next)
    temp = temp->next;
  temp->next = node;
}

t_list *lstnew(void *data)
{
  t_list *new;
  new = (t_list *)malloc(sizeof(t_list));
  new->data = data;
  new->next = NULL;
  return new; 
}

int ft_list_size(t_list *list)
{
  int i = 0;
  while(list)
  {
    list = list->next;
    i++;
  }
  return i;
}

char *extract_line(char *str)
{
  int i = 0;

  while(str[i] != '\n' && str[i])
    i++;
  char *string = malloc(sizeof(char) * i + 1);
  i = 0;
  while(str[i] != '\n')
  {
    string[i] = str[i];
    i++;
  }
  string[i] = '\n';
  string[i + 1] = '\0';
  return string;
}



void print_list(t_list *list)
{
  while(list)
  {
    printf("%s ->",(char *)list->data);
    list = list->next;
  }
}
