#include <ctap.h>
#include "tester.h"

TESTS {
    // tokenizer tests
    ok(testTokenizer("+-*/^%()^\n") == "+\n-\n*\n/\n^\n%\n(\n)\n^\n", "Tokenizer - correct output - all operators detected, spaces ignored");
    ok(testTokenizer("12 3 1457 1 23000000\n") == "0 12\n0 3\n0 1457\n0 1\n0 23000000\n", "Tokenizer - correct output - detects integers of different length");
    ok(testTokenizer("0.4 32.1 1.678 365.000 23.111\n") == "1 0.4\n1 32.1\n1 1.678\n1 365.000\n1 23.111\n", "Tokenizer - correct output - detects floats of different length");
    ok(testTokenizer("5(56)(3) 4\n") == "0 5\n*\n(\n0 56\n)\n*\n(\n0 3\n)\n*\n0 4\n", "Tokenizer - correct output - different sequences of brackets add multiply sign");
    ok(testTokenizer(" 1*2\n") == "0 1\n*\n0 2", "Tokenizer - correct output - mixed input");
    ok(testTokenizer("2+1.3-2 *2/(12 ^2 % 3)\n") == "0 2\n+\n1 1.3\n-\n0 2\n*\n0 2\n/\n(\n0 12\n^\n0 2\n%\n0 3\n)\n", "Tokenizer - correct output - mixed input all token types used");
    ok(testTokenizer("hello") == "1", "Tokenizer - correct error reached - letters entered");
    ok(testTokenizer("12 + 2.3.9") == "1", "Tokenizer - correct error reached - float with 2 decimal points entered");

    // Infix to Postfix tests
    ok(isOperator('+') == 1. "+ is in fact an operator.");
    ok(isOperator('&') == 0. "& is in fact not an operator.");
    ok(precedence('^') == 3, "The precedence of '^' is in fact 3.");
    ok(precedence('&') == 0, "There is in fact no precedence for this character as it in is not an operator.");
    ok(testI2P("0 1\n*\n0 2") == ("1 2 *"), "The postfix for '1 * 2' is in fact '1 2 *.''");
    ok(testI2P("(\n1 4.5\n*\n0 2\n)\n^\n0 3\n+\n0 4") == ("4.5 2 * 3 ^ 4 +"), "The postfix for (4.5 * 2) ^ 3 + 4' is in fact '4.5 2 * 3 ^ 4 +.'");
    ok(testI2P("1 11.11\n+\n0 22\n-\n1 33.34443\n^\n0 4\n*\n0 555\n/0 6") == ("11.11 22 - 33.34443 4 ^ 555 * 6 / +"), "The postfix for '11.11 + 22 - 33.34443 ^ 4 * 555 / 6' is in fact '11.11 22 - 33.34443 4 ^ 555 * 6 / +.'");
    ok(testI2P("1 0.234434434\n +\n1 3334.56\n^\n0 2") == ("0.234434434 3334.56 2 ^ +"), "The postfix for '0.234434434 + 3334.56 ^ 2' is in fact '0.234434434 3334.56 2 + ^.'");

}
