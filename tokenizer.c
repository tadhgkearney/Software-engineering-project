/*
Tokenizer
A program which takes in a stream of characters in a file and separates them
into appropriate number or operator tokens. Each token is printed on a separate
line in the output file. Number tokens are preceded by a bit representing their
type (integer or float)

Input:
A .txt file containing one line of characters which should represent an
arithmetic expression

Output:
A .txt file containing each of the tokens on separate lines.
Or an error

@author: Peter O'Donoghue
*/

#include <stdio.h>
#include <ctype.h>
#include "InfixToPostfix.h"

int tokenize(void){
  /*
  function which carries out the full tokenizing process, converting a stream
  of characters into separate number/operator tokens
  */
  // initializing necessary variables for the function
  char ops[] = {'+', '-', '*', '/', '^', '%', '(', ')'}; // operator array
  FILE *inp, *out; // files
  char buffer[255]; // buffer for storing numbers
  size_t n = 0; // pointer for buffer position
  char c,d; // character to be read in
  size_t type = 0; // number type
  size_t op;

  // open files
  inp = fopen("tokenizer_input.txt", "r");
  out = fopen("infix2postfix_input.txt", "w");

  // no input error
  if (inp == NULL){
    printf("Error: no input file recieved");
    return 1;
  }

  // loop through input file getting new character each time
  while ((c = fgetc(inp)) != '\n'){
    // ignore space characters
    if (c == ' '){
      // print any previous numbers to output if we hit a space
      if(n != 0){
        buffer[n++] = '\0';
        fprintf(out, "%d ", type);
        fprintf(out, "%s\n", buffer);
        n = 0;
        type = 0;
      }
    }
    // add any number or decimal point to the buffer
    else if (isdigit(c) || c == '.'){
      // number after bracket same as multiplied
      if (d == ')'){
        fprintf(out, "*\n");
      }
      buffer[n++] = (char) c;
      if(c == '.'){
        // adjust number type if we get a decimal point
        type++;
      }
      // more than 1 decimal point in a number error
      if(type > 1){
        printf("Error: invalid float number recieved");
        return 1;
      }
    }
    else{
      // print any number in buffer if we hit
      //any char that's not a number, decimal point or space
      if(n != 0){
        buffer[n++] = '\0';
        fprintf(out, "%d ", type);
        fprintf(out, "%s\n", buffer);
        n = 0;
        type = 0;
      }
      // check if this char is a valid operator
      // if so print to output
      op = 0;
      for(int i = 0; i < 8; i++ ){
        if (c == ops[i]){
          // check for situation like (a)(b) or a(b) which should be multiplied
          if ((c == '(' && d == ')') || (c == '(' && isdigit(d))){
            fprintf(out, "*\n");
          }
          fprintf(out, "%c\n", c);
          op = 1;
          break;
        }
      }
      if (op == 0){
        // error if the character isn't an operator
        printf("Error: invalid character received");
        return 1;
      }
    }
    // store last char to check for multiplication situations
    if (c != ' '){
        d = c;
    }
  }
  // print out any final number to the output
  if(n != 0){
    buffer[n++] = '\0';
    fprintf(out, "%d ", type);
    fprintf(out, "%s", buffer);
  }
  //close all files
  fclose(inp);
  fclose(out);
  // call infix to postfix
  return i2p();
}

int main(int argc, char const *argv[]) {
  /* run the function to tokenize */
  return tokenize();
}
