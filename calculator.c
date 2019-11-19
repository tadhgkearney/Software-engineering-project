#include <stdio.h>
#include "tokenizer.h"
#include "InfixToPostfix.h"
#include "generator.h"
#include "virtualMachine.h"

int main(int argc, char const *argv[]) {
  /* code */
  tokenize();
  i2p();
  generate();
  calculate();
  return 0;
}
