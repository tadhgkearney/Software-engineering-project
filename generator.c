/*
    Name: Tadhg Kearney
    Date: 15/10/19
    Purpose: take list of tokens and convert them to machine instructions
             generator portion of calculator
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "virtualMachine.h"


int generator()
{
    // pointer to file we are reading
    FILE *fptr;
    // pointer to file we are writing to
    FILE *fptr2;
    // checks to make sure that the file isn't empty
    // if it is it prints an error and exits the program
    if ((fptr = fopen("generator_input.txt","r")) == NULL){
        printf("Error! opening file");
        exit(0);
    }
    fptr2 = fopen("virtualMachine_input.txt", "w");
    char token[255];
    // fscanf reads up until it reaches a space
    // go through the file token by token until we reach the end of the file
    while(fscanf(fptr, "%s", token) == 1){
        if(token[0] == '+'){
            fprintf(fptr2, "ADD");
        }
        else if(token[0] == '-'){
            fprintf(fptr2, "SUB");
        }
        else if(token[0] == '*'){
            fprintf(fptr2, "MUL");
        }
        else if(token[0] == '/'){
            fprintf(fptr2, "DIV");
        }
        else if(token[0] == '^'){
            fprintf(fptr2, "POW");
        }
        else if(token[0] == '%'){
            fprintf(fptr2, "MOD");
        }
        else{
            // there is no in-bulit boolean value in c, so using 0 as false and 1 as true
            int is_float = 0;
            for(int i=0;i<255;i++){
                if(token[i]=='.'){
                    double r = atof(token);
                    // BUG ALERT: no float greater than 5 decimal places can be printed
                    // %g uses the shortest representation of a float. i.e. gets rid of trailing zeros
                    fprintf(fptr2, "LOADFLOAT %g", r);
                    is_float = 1;
                    break;
                }
            }
            if(!is_float){
                int t = atoi(token);
                fprintf(fptr2,"LOADINT %d", t);
            }
        }
        fprintf(fptr2, "\n");
        memset(token, 0, sizeof(token));
    }

    fclose(fptr);
    fclose(fptr2);
    return calculate();
}
