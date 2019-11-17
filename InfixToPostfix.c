/*
Infix To Postfix Converter:
A programme which takes in an infix expression (operators between numbers) and
and converts it to postfix(operators after numbers).

Input:
A .txt file containing each of the tokens of the infix equation on a separate line.

Output:
A .txt file containing the converted postfix equation on a single line.

@author: Colum O'Donovan

*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "generator.h"


#define size 256

// Two arrays used to process the inputted infix equation
char input_infix[size]; //
char output_infix[size];
// Stack used to convert infix to postfix
char stack[size];
int top = -1;


void push(char item) {
  /* Function to push items onto the stack
   * Function parameters are a single character
   * The function returns nothing
  */
  if (top>size-1) { //check overflow
    printf("Stack Overflow!");
  } else { // else add item to stack
    stack[++top] =item;
  }
}

int precedence(char symbol) {
  /* Function to return the precedence value of an operator
   * Function parameters are a single character
   * The function returns an integer value absed on an operators precedence
  */
  if(symbol=='^') {
    return 3;
  } else if(symbol=='%' || symbol=='*' || symbol=='/') {
    return 2;
  } else if(symbol=='+' || symbol=='-') {
    return 1;
  } else {
    return 0;
  }
}

char pop() {
  /* Function to remove an item from the top of the stack
   * No parameters
   * Returns an item from the top of the stack
  */
  return(stack[top--]);
}


int isOperator(char symbol) {
  /* Function to check if a character is an arithmetic operator
   * Function parameter is a single character
   * Returns 1 for true pr 0 for false
  */
  if(symbol=='%' || symbol=='^' || symbol=='*' || symbol=='+' || symbol=='-' || symbol== '/') {
    return 1;
  } else {
    return 0;
  }
}



int i2p() {
  FILE *in_file = fopen("infix2postfix_input.txt", "r"); // open input file in read mode
  FILE *out_file = fopen("generator_input.txt", "w"); //open output file in write mode

  size_t len = sizeof(input_infix);
  char *line = malloc(len);
  char item, temp; // used to store items from an array
  int count = 0; // count used to index output_infix array
  int lineIndex; // used to index a single line from the input text

  line[0] = '\0';
  /* The following while loop processes the input text line by line to create an output array
   * which can be easily processed for conversion later on
  */
  while(fgets(input_infix, sizeof(input_infix), in_file) != NULL) {
    strcat(line, input_infix);

    if(isalnum(line[0])){ // check to see if the first item is a number or operator

      item = (line[0]); // get the item from the line

      if (item=='0') { // if it is an integer
        output_infix[count] = line[2]; // add to output_infix

        lineIndex = 3; // while loop is used to add numbers that are more than one digit
        while (line[lineIndex] != '\n') {
          output_infix[++count] = line[lineIndex]; // add to output
          lineIndex++; // increase index pointer
        }
        output_infix[++count] = ' '; // add space
      } else if (item=='1') { // else if item is  float

        lineIndex = 4; // this i the index after the decimal point
        output_infix[count] = line[2]; // add digit to output
        output_infix[++count] = line[3]; // add decimal point to output
        while (line[lineIndex]!='\n') { // loop to add digits after decimal point to output
          output_infix[++count] = line[lineIndex];
          lineIndex++;
        }
        output_infix[++count] = ' '; // add space
      }
    } else { // else item is an operator
      // if elses are used to work out when spaces should be added
      if (line[0] != ')') { // if operator is not a closing bracket
        output_infix[count] = line[0]; //add operator
        if (line[0] != '(') { // do not add a space if it is an opening bracket
          output_infix[++count] = ' ';
        }
      } else if (line[0] == ')') {
        /* Need to remove a space when a closing bracket is to be added as
         * a space is always added after a number
        */
        output_infix[--count] = line[0]; // remove a space and add closing bracket
        output_infix[++count] = ' '; // add space
      }

    }
    line[0] = '\0';
    count++; //increase count
  }


  fclose(in_file); // close file
  char postfix[size];
  int i=0; // index pointers
  char space =  ' '; // used to print space to output file

  /*  the following while loop converts from infix to postfix and outputs result
   *  to a text file
  */
  while(output_infix[i]!='\0') {
    item = output_infix[i]; //get item from array



    if (item=='(') { //push an opening bracket straight to stack
      push(item);
    } else if(isalnum(item)) { // else if its a number
        fprintf(out_file, "%c", item); // print to file
        item = output_infix[++i]; // get next item as it may be multi-digit number/float

        if (item == ' ' || item == ')') { // if it is not a multi-digit number/float
          i--; // decrease pointer as it will be increased again at end of the if-else branching
        } else { // else loop until the end of the number printing each character to output file
          while (isalnum(item) || item == '.' ) {
            fprintf(out_file, "%c", item);
            item = output_infix[++i]; // get next item
          }
          i--; // decrease pointer
        }
        fprintf(out_file, "%c", space); // print space to output file


    } else if(isOperator(item)==1) { // else if item is an operator

        temp = pop(); // get operator(s) from stack and print to output file if they
                      // are of a higher precedence than the current operator
        while (isOperator(temp)==1 && precedence(temp)>=precedence(item)) {
          fprintf(out_file, "%c", temp); // print operator to output file
          fprintf(out_file, "%c", space);// print a space

          temp = pop(); // get next operator from stack
        }

        push(temp); // push both operators to stack ( item is of higher precedence than temp)
        push(item);
    } else if(item==')') {
      temp=pop(); // print all items on stack to output file until an opening bracket is found
      while(temp!='(') {

        fprintf(out_file, "%c", temp); // print item to output file
        fprintf(out_file, "%c", space);// print a space

        temp=pop(); // get next item from stack
      }
    }
    i++; //increase pointer
  }
  while(top>-1) { //print any remaining items in stack to output file
    fprintf(out_file, "%c", pop());
    fprintf(out_file, "%c", space);

  }
  fprintf(out_file, "\0"); // print end of line to output file
  fclose(out_file); // close file
  return generator();
}
