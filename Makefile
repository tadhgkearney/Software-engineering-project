
default: all

all: Tokenizer I2p Generator VM

Tokenizer: tokenizer.c
	gcc -o token tokenizer.c
	./token

I2p: i2p.c
	gcc -o i2p i2p.c
	./i2p

Generator: generator.c
	gcc -o generate generator.c
	./generate

VM: virtualMachine.c
	gcc -o vm virtualMachine.c stack.c -lm
	./vm

clean:
	rm -f *.o
