#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

int calculate(){
  char instr[10];
  struct Stack* stack = createStack(100); // created a stack
  float no, a, b, answer;

  // open files
  FILE *inp;
  inp = fopen("virtualMachine_input.txt", "r");

  // no input error
  if (inp == NULL){
    printf("Error: no input file recieved");
    return 1;
  }

  while (fscanf(inp, "%s", instr) != EOF){
    if (strcmp(instr, "LOADINT") == 0){
      // read the int and add to stack
      fscanf(inp, "%f", &no);
      pushF(stack, no);

    } else if (strcmp(instr, "LOADFLOAT") == 0){
      // read the float and add to stack
      fscanf(inp, "%f", &no);
      pushF(stack, no);

    } else if (strcmp(instr, "ADD") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // add two numbers
      answer = a + b;
      // push result onto stack
      pushF(stack, answer);
    } else if (strcmp(instr, "SUB") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // subtract first from second
      answer = b - a;
      // push result onto stack
      pushF(stack, answer);
    } else if (strcmp(instr, "MUL") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // multiply two numbers
      answer = b * a;
      // push result onto stack
      pushF(stack, answer);
    } else if (strcmp(instr, "DIV") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // divide second by first
      answer = b / a;
      // push result onto stack
      pushF(stack, answer);
    } else if (strcmp(instr, "POW") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // second number to the power of the first
      answer = powf(b, a);
      // push result onto stack
      pushF(stack, answer);
    } else if (strcmp(instr, "MOD") == 0){
      // pop top two numbers off stack
      a = popF(stack);
      b = popF(stack);
      // second number modulo first number
      answer = fmodf(b, a);
      // push result onto stack
      pushF(stack, answer);
    } else {
      printf("Error: Invalid code taken into VM");
      return 1;
    }
  }

  // check that there's only one value on stack --> else Error
  // pop value off stack and print to screen

  answer = popF(stack);
  //outputting answer to file for testing
  FILE *inp2;
  inp2 = fopen("virtualMachine_output.txt", "w");
  fprintf(inp2, "%g", answer);
  fclose(inp2);
  if (isEmpty(stack) == 0){
    printf("%g\n", answer);
    printf("Error: Extra items left on stack");
    return 1;
  }
  printf("%g\n", answer);
  return 0;
}
