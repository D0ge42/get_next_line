#include "get_next_line.h"
#include <fcntl.h> 
#include <string.h>
#include <unistd.h>

//Il problema è che non pulendo stash, la stringa non entra nel loop perchè c'è subito la '\n'.

// char	*get_next_line(int fd)
// {
//   static t_list *stash;
//   t_list *new;
//   int i = 0;
//   char buf[BUFFER_SIZE];
//   int list_size;

//   while(!ft_strchr(buf,'\n'))
//   {
//     read(fd,buf,BUFFER_SIZE);
//     new = lstnew(ft_strdup(buf));
//     if(!stash)
//       stash = new;
//     else
//       lst_add_back(&stash,new);
//     i++;
//   }
//   char *line = malloc(sizeof(char) * (BUFFER_SIZE * i + 1));
//   while(i)
//   {
//     strcat(line,stash->data);
//     stash = stash->next;
//     i--;
//   }
//   line = extract_line(line);
//   return(line);
// }


char *get_next_line(int fd)
{
  int i = 0;
  char buf[BUFFER_SIZE];
  static char *stash = NULL;
  while(!ft_strchr(buf,'\n'))
  {
    read(fd,buf,BUFFER_SIZE);
    stash = ft_strjoin(stash,buf);
  }
  printf("%s\n", stash);
  char *line = extract_line((char *)stash);
  printf("%s",line);
  bzero((char *)stash,ft_strlen(line));
  memmove(stash,&stash[ft_strlen(line)],2);
  printf("Stash ora è %s\n",stash);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
}
