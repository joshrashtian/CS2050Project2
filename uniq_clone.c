#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  FILE *fp = stdin;  
  char *buffer = NULL;
  size_t size=0;
  int isFile = 0;

  if(argc == 2)
  {
    fp = fopen(argv[1], "r");
    isFile = 1;
  }

  if(fp == NULL)
  {
    printf("%s", "File pointer is null");
    return 1;
  }

  char *prevLine = NULL; size_t prevSize = 0;
  
  while(getline(&buffer, &size, fp) != -1)
  {
    if(prevLine == NULL || strcmp(buffer, prevLine) != 0) printf("%s", buffer);
    char *tempLine = buffer;
    buffer = prevLine;
    prevLine = tempLine;

    size_t tempSize = size;
    size = prevSize;
    prevSize = tempSize;
  }
  
  if(isFile) fclose(fp);
  free(buffer); 
  free(prevLine);

  return 0;
}
