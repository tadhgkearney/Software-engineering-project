#include <ctap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generator.h"

void testInputs(){
    char *inputs[4];
    char *outputs[4];
    inputs[0] = "1 1 +";
    outputs[0] = "LOADINT 1";
    inputs[1] = "1 2 +";
    outputs[1] = "LOADINT 1\nLOADINT 2\nADD";
    inputs[2] = "1.2 3 +";
    outputs[2] = "LOADFLOAT 1.2\nLOADINT 3\nADD";
    inputs[3] = "";
    outputs[3] = "";

    for(int i=0;i<4;i++){
        FILE *test_gen;
        test_gen = fopen("generator_input.txt","w");
        fprintf(test_gen, "%s", inputs[i]);
        generate();
        FILE *test_output;
        char *gen_output = 0;
        test_output = fopen("virtualMachine_input.txt", "r");
        while(fgets(buffer, sizeof(buffer), test_output)){
            strcat(gen_output, buffer);
        }
        if(gen_output[strlen(gen_output)-1]=='\n'){
            gen_output[strlen(gen_output)-1] = '\0';
        }
        int value = strcmp(gen_output, outputs[i]);
        ok(value == 0, "1: %s is not 2: %s", outputs[i], gen_output);
        fclose(test_gen);
        fclose(test_output);
    }
}

TESTS{
    testInputs();
}
