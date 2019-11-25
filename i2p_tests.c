#include <ctap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "InfixToPostfix.h"

void testInputs(){
    char *inputs[4];
    char *outputs[4];
    inputs[0] = "0 1\n*\n0 2";
    outputs[0] = "1 2 * ";
    inputs[1] = "(\n1 4.5\n*\n0 2\n)\n^\n0 3\n+\n0 4";
    outputs[1] = "4.5 2 * 3 ^ 4 + ";
    inputs[2] = "1 11.11\n+\n0 22\n-\n1 33.34443\n^\n0 4\n*\n0 555\n/\n0 6";
    outputs[2] = "11.11 22 + 33.34443 4 ^ 555 * 6 / - ";
    inputs[3] = "1 0.234434434\n+\n1 3334.56\n^\n0 2";
    outputs[3] = "0.234434434 3334.56 2 ^ + ";

    for(int i=0;i<4;i++){
        FILE *test_i2p;
        test_i2p = fopen("infix2postfix_input.txt","w");
        fprintf(test_i2p, "%s", inputs[i]);
        fclose(test_i2p);
        i2p();
        FILE *test_output;
        char buffer[255];
        char i2p_output[255];
        memset(i2p_output, 0, strlen(i2p_output));
        test_output = fopen("generator_input.txt", "r");
        while(fgets(buffer, sizeof(buffer), test_output)){
            strcat(i2p_output, buffer);
        }
        if(i2p_output[strlen(i2p_output)-1]=='\n'){
            i2p_output[strlen(i2p_output)-1] = '\0';
        }
        int value = strcmp(outputs[i], i2p_output);
        ok(value == 0, "1: %s is not 2: %s", outputs[i], i2p_output);

        fclose(test_output);
    }
}

TESTS{


    //ok(isOperator('+') == 1, "+ is in fact an operator.");
    //ok(isOperator('&') == 0, "& is in fact not an operator.");

    //ok(precedence('^') == 3, "The precedence of '^' is in fact 3.");
    //ok(precedence('&') == 0, "There is in fact no precedence for this character as it in is not an operator.");

    testInputs();
}
