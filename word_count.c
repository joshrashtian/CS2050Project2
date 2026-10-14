#include <stdio.h>

int main(int argc, char *argv[]) {

  if(argc < 2) {
    printf("%s", "Missing a file to read!");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");

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

  printf("%d %d %d %s\n", lines, words, bytes, argv[1]);
  fclose(fp);

  return 0;
} 
