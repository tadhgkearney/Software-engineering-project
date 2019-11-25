#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "generator.h"
#include "InfixToPostfix.h"

char * testTokenizer(char* file_contents){

  FILE *inp; // files
  inp = fopen("tokenizer_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  int result;
  result = tokenize();
  if (result == 1){
    return "1";
  }

  char * buffer = 0;
  long length;
  FILE * f = fopen ("infix2postfix_input.txt", "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length + 1);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  buffer[length] = '\0';
  return buffer;
}

char * testI2P(char* file_contents){

  FILE *inp; // files
  inp = fopen("infix2postfix_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  i2p();

  char * buffer = 0;
  long length;
  FILE * f = fopen ("generator_input.txt", "rb");

  if (f)
  {
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length + 1);
    if (buffer)
    {
      fread (buffer, 1, length, f);
    }
    fclose (f);
  }
  buffer[length] = '\0';
  return buffer;
}


// Showing you how to use it on tokenizer
//int main(int argc, char const *argv[]) {
  //char * answer;
  // put the input file contents as the argument
  //answer = testTokenizer("12 + 2.3.9");
  //printf("%s", answer );

  //return 0;
//}
