#include <stdio.h>
#include <string.h>
//#include "stack.h" // only works for ints

int calculate(){
  char instr[10];
  // struct Stack* stack = createStack(100); // created a stack
  float fno;
  int ino;

  // open files
  FILE *inp;
  inp = fopen("VM_input.txt", "r");

  // no input error
  if (inp == NULL){
    printf("Error: no input file recieved");
    return 1;
  }

  while (fscanf(inp, "%s", instr) != EOF){
    if (strcmp(instr, "LOADINT") == 0){
      // read the int and add to stack
      fscanf(inp, "%d", &ino); // integer stored in ino
      // push ino (integer) onto the stack
    } else if (strcmp(instr, "LOADFLOAT") == 0){
      // read the float and add to stack
      fscanf(inp, "%f", &fno); // float stored in fno
      // push fno (float) onto the stack
    } else if (strcmp(instr, "ADD") == 0){
      // pop top two numbers off stack
      // add two numbers
      // push result onto stack
    } else if (strcmp(instr, "SUB") == 0){
      // pop top two numbers off stack
      // subtract first from second
      // push result onto stack
    } else if (strcmp(instr, "MUL") == 0){
      // pop top two numbers off stack
      // multiply two numbers
      // push result onto stack
    } else if (strcmp(instr, "DIV") == 0){
      // pop top two numbers off stack
      // divide second by first
      // push result onto stack
    } else if (strcmp(instr, "MOD") == 0){
      // pop top two numbers off stack
      // second number to the power of the first
      // push result onto stack
    } else if (strcmp(instr, "MOD") == 0){
      // pop top two numbers off stack
      // second number modulo first number
      // push result onto stack
    } else {
      printf("Error: Invalid code taken into VM");
      return 1;
    }
  }

  // check that there's only one value on stack --> else Error
  // pop value off stack and print to screen
  return 0;
}


int main(){
  calculate();
  return 0;
}
