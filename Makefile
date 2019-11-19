
default: all

all: Main

Main:
	gcc tokenizer.c InfixToPostfix.c generator.c virtualMachine.c main.c stack.c -lm

clean:
	rm -f *.o
