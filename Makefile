
default: all

all: Tokenizer ItoP Generator VirtualMachine

Tokenizer: tokenizer.c
	gcc -o token tokenizer.c

ItoP: i2p.c
	gcc -o i2p i2p.c

Generator: generator.c
	gcc -o generate generator.c
	./generate

VirtualMachine: virtualMachine.c
	gcc -o vm virtualMachine.c stack.c -lm

clean:
	rm -f *.o
