#include <stdio.h>

int isSpace(int currentChar) {
  return currentChar == ' ' || currentChar == '\n' || currentChar == '\t';
}

int main(int argc, char *argv[]) {

  FILE *fp = stdin;
  int isFile = 0;

  if(argc > 1) {
    fp=fopen(argv[1], "r");
    isFile = 1;

    if (fp == NULL) {
       perror(argv[1]);
       return 1;
    }
  } 
  int currentChar;
  int words = 0;
  int lines = 0;
  int bytes = 0;

  int inWord = 0;
  //parsing through for " "
  while((currentChar = fgetc(fp)) != EOF)
  {
    if(isSpace(currentChar)) {
      
      inWord = 0;
    }
    else if (!inWord) {
      inWord =1;
      words++;
    };

    if(currentChar == '\n') lines++;
    bytes += sizeof(char);
  }

  printf("%d %d %d", lines, words, bytes);
  if(argc > 1) printf("%s\n", argv[1]); else printf("\n");
  
  if(isFile) fclose(fp);

  return 0;
} 
