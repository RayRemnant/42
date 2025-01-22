#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int    fd;
  char  *line;
  static int  count;

  count = 0;
  fd = open("example", O_RDONLY);
 if (fd == -1)
 {
  printf("Error opening file");
  return (1);
 }
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