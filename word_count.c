#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp = stdin;
  if(argc > 1) {
    fp=fopen(argv[1], "r");

    if (fp == NULL) {
       perror(argv[1]);
       return 1;
    }
  } 
  char currentChar;
  int words = -1;
  int lines = 0;
  int bytes = 0;
  //parsing through for " "
  while((currentChar = fgetc(fp)) != EOF)
  {
    if(currentChar == ' ' || currentChar == '\n') words++;
    if(currentChar == '\n') lines++;
    bytes += sizeof(char);
  }

  printf("%d %d %d", lines, words, bytes);
  if(argc > 1) printf("%s\n", argv[1]); else printf("\n");
  fclose(fp);

  return 0;
} 
