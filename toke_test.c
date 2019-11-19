#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

char * testTokenizer(char* file_contents){
  char src[50], dest[50];
  strcpy(dest,  "");
  char *str_to_ret = malloc (sizeof (char) * 50);
  FILE *inp, *out; // files
  inp = fopen("tokenizer_input.txt", "w");
  fprintf(inp, "%s", file_contents);
  //close files
  fclose(inp);
  tokenize();

  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  out = fopen("infix2postfix_input.txt", "r");

    if (out == NULL)
        exit(0);

    while ((read = getline(&line, &len, out)) != -1) {
        strcpy(src,  line);
        strcat(dest, src);
        //printf("%s\n", line );
    }

  fclose(out);
  str_to_ret = dest;
  //printf("%s\n",str_to_ret);
  return str_to_ret;
}

int main(int argc, char const *argv[]) {
  /* code */
  char * answer;
  answer = testTokenizer("1 + 2\n");
  printf("%s", answer );
  return 0;
}
