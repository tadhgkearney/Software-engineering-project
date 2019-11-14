#ifndef __STA_CK__
#define __STA_CK__

struct Stack;
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, float item);
float pop(struct Stack* stack);
float top(struct Stack* stack);

#endif
