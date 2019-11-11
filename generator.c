/*
    Name: Tadhg Kearney
    Date: 15/10/19
    Purpose: take list of tokens and convert them to machine instructions
             generator portion of calculator
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    // pointer to file we are reading
    FILE *fptr;
    // pointer to file we are writing to
    FILE *fptr2;
    // checks to make sure that the file isn't empty
    // if it is it prints an error and exits the program
    if ((fptr = fopen("calculator.txt","r")) == NULL){
        printf("Error! opening file");
        exit(0);
    }
    fptr2 = fopen("calculator2.txt", "w");
    char token[255];
    int p;
    // fscanf reads up until it reaches a space
    fscanf(fptr, "%s", token);
    //printf(token);
    // go through the file token by token until we reach the end of the file
    while(token[0] != EOF){

        if(isdigit(token)){
            // convert the token to an integer
            int num = atoi(token);
            fprintf(fptr2, "LOADINT %d", num);
        }
        else if(token == "+"){
            fprintf(fptr2, "ADD");
        }
        else if(token == "-"){
            fprintf(fptr2, "SUB");
        }
        else if(token == "*"){
            fprintf(fptr2, "MUL");
        }
        else if(token == "/"){
            fprintf(fptr2, "DIV");
        }
        else if(token == "^"){
            fprintf(fptr2, "POW");
        }
        else if(token == "%"){
            fprintf(fptr2, "MOD");
        }
        else{
            for(int i=0;i<token.length();i++){
                if(token[i]=='.'){
                    double r = atoi(token);
                    fprintf(fptr2, "LOADFLOAT %f", r);
                }
            }
            int t = atoi(token);
            fprintf(fptr2,"LOADINT %d", t);
        }

        fscanf(fptr, "s", token);
    }

    fclose(fptr);
    fclose(fptr2);
    return 0;
}
