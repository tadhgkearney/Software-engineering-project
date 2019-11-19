#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

char * testTokenizer(char* file_contents){

  FILE *inp; // files
  inp = fopen("tokenizer_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  tokenize();

  char * buffer = 0;
  long length;
  FILE * f = fopen ("infix2postfix_input.txt", "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  return buffer;
}

char * testI2P(char* file_contents){

  FILE *inp; // files
  inp = fopen("infix2postfix_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  tokenize();

  char * buffer = 0;
  long length;
  FILE * f = fopen ("generator_input.txt", "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  return buffer;
}

char * testGenerator(char* file_contents){

  FILE *inp; // files
  inp = fopen("generator_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  tokenize();

  char * buffer = 0;
  long length;
  FILE * f = fopen ("virtualMachine_input.txt", "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  return buffer;
}


// Showing you how to use it on tokenizer
int main(int argc, char const *argv[]) {
  /* code */
  char * answer;
  // put the input file contents as the argument
  answer = testTokenizer(" 1*2\n");
  printf("%s", answer );
  // the test suite will do something similar to this
  if (strcmp(answer, "0 1\r\n*\r\n0 2") == 0){
    printf("\nyes\n");
  }
  return 0;
}
