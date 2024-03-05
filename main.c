#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int  fd;
 char *line;
 int  count;

  count = 0;
  fd = open("file4.txt", O_RDONLY);
  while (1)
 {
  line = get_next_line(fd);
  if (line == NULL)
   break ;
  count++;
  printf("[%d]:%s\n", count, line);
  free(line);
  line = NULL;
 }
  close(fd);
  return (0);
}