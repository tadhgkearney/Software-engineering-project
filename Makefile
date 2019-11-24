
default: all

all: Main

Main:
	gcc tokenizer.c InfixToPostfix.c generator.c virtualMachine.c main.c stack.c -lm
	./output.o

clean:
	rm -f *.o
	
test:
	gcc -o test.t test_gen.c generator.c
	prove ./test.t
