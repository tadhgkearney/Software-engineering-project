#include <ctap.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

void testInputs(){
    char *inputs[10];
    char *outputs[10];
    inputs[0] = "1 1 +";
    outputs[0] = "LOADINT 1";
    //inputs[0] = "1 2 +";
    /*outputs[0] = "LOADINT 1\nLOADINT 2\nADD";*/

    for(int i=0;i<1;i++){
        FILE *test_gen;
        test_gen = fopen("generator_input.txt","w");
        fprintf(test_gen, "%s", inputs[i]);
        generate();
        FILE *test_output;
        char *gen_output = 0;
        test_output = fopen("virtualMachine_input.txt", "r");
        /*fseek(test_output, 0, SEEK_END);
        long length = ftell(test_output);
        fseek(test_output, 0, SEEK_SET);
        gen_output = malloc(length);
        fread(gen_output, 1, length, test_output);*/
        fscanf(test_output, "%s", gen_output);
        ok(outputs[i] == gen_output, "1: %s is not 2: %s", outputs[i], gen_output);
        fclose(test_gen);
        fclose(test_output);
    }
}

TESTS{
    testInputs();
}
