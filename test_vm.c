#include <ctap.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "virtualMachine.h"

void testInputs(){
    char *inputs[10];
    char *outputs[10];
    inputs[0] = "LOADINT 1\nLOADINT 2\nADD";
    outputs[0] = "3";
    inputs[1] = "LOADFLOAT 1.2\nLOADINT 3\nADD";
    outputs[1] = "4.2";
    inputs[2] = "LOADINT 4\nLOADINT 3\nLOADINT 1\nSUB\nDIV";
    outputs[2] = "2";
    inputs[3] = "LOADINT 5\nLOADFLOAT 2.5\nDIV";
    outputs[3] = "2";

    for(int i=0;i<4;i++){
        FILE *test_vm;
        test_vm = fopen("virtualMachine_input.txt","w");
        fprintf(test_vm, "%s", inputs[i]);
        fclose(test_vm);
        calculate();
        FILE *test_output;
        char buffer[255];
        char vm_output[255];
        memset(vm_output, 0, strlen(vm_output));
        test_output = fopen("virtualMachine_output.txt", "r");
        //fscanf(test_output, "%[^/n]", vm_output);
        while(fgets(buffer, sizeof(buffer), test_output)){
            strcat(vm_output, buffer);
        }
        if(vm_output[strlen(vm_output)-1]=='\n'){
            vm_output[strlen(vm_output)-1] = '\0';
        }
        int answer = strcmp(outputs[i],vm_output);
        ok(answer == 0, "1: %s is not 2: %s", outputs[i], vm_output);
        fclose(test_output);
    }
}

TESTS{
    testInputs();
}
