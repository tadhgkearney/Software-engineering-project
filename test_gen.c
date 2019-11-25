#include <ctap.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generator.h"

void testInputs(){
    char *inputs[10];
    char *outputs[10];
    inputs[0] = "1";
    outputs[0] = "LOADINT 1";
    inputs[1] = "1 2 +";
    outputs[1] = "LOADINT 1\nLOADINT 2\nADD";
    inputs[2] = "1.2 3 +";
    outputs[2] = "LOADFLOAT 1.2\nLOADINT 3\nADD";

    for(int i=0;i<3;i++){
        FILE *test_gen;
        test_gen = fopen("generator_input.txt","w");
        fprintf(test_gen, "%s", inputs[i]);
        fclose(test_gen);
        generate();
        FILE *test_output;
        char buffer[255];
        char gen_output[255];
        memset(gen_output, 0, strlen(gen_output));
        test_output = fopen("virtualMachine_input.txt", "r");
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
