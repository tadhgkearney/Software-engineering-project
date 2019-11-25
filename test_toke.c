#include <ctap.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tokenizer.h"

void testInputs(){
    char *inputs[10];
    char *outputs[10];
    inputs[0] = "+-*/^%()^";
    outputs[0] = "+\n-\n*\n/\n^\n%\n(\n)\n^";
    inputs[1] = "12 3 1457 1 23000000";
    outputs[1] = "0 12\n0 3\n0 1457\n0 1\n0 23000000";
    inputs[2] = "0.4 32.1 1.678 365.000 23.111";
    outputs[2] = "1 0.4\n1 32.1\n1 1.678\n1 365.000\n1 23.111";
    inputs[3] = "5(56)(3) 4";
    outputs[3] = "0 5\n*\n(\n0 56\n)\n*\n(\n0 3\n)\n*\n0 4";
    inputs[4] = " 1*2";
    outputs[4] = "0 1\n*\n0 2";
    inputs[5] = "2+1.3-2 *2/(12 ^2 % 3)";
    outputs[5] = "0 2\n+\n1 1.3\n-\n0 2\n*\n0 2\n/\n(\n0 12\n^\n0 2\n%\n0 3\n)";

    for(int i=0;i<6;i++){
        FILE *test_gen;
        test_gen = fopen("tokenizer_input.txt","w");
        fprintf(test_gen, "%s", inputs[i]);
        fclose(test_gen);
        tokenize();
        FILE *test_output;
        char buffer[255];
        char gen_output[255];
        memset(gen_output, 0, strlen(gen_output));
        test_output = fopen("infix2postfix_input.txt", "r");
        //fscanf(test_output, "%[^/n]", gen_output);
        while(fgets(buffer, sizeof(buffer), test_output)){
            strcat(gen_output, buffer);
        }
        if(gen_output[strlen(gen_output)-1]=='\n'){
            gen_output[strlen(gen_output)-1] = '\0';
        }
        int answer = strcmp(outputs[i],gen_output);
        ok(answer == 0, "1: %s is not 2: %s", outputs[i], gen_output);
        fclose(test_output);
    }
}

TESTS{
    testInputs();
}

