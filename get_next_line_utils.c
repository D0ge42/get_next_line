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

char	*ft_strjoin(char  *s1, char  *s2)
{
	char		*result;
	size_t		s1len;
	size_t		s2len;
	char		*ret;

  if (!s1)
  {
    return ft_strdup(s2);
  }
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!result)
		return (NULL);
	ret = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (ret);
}
