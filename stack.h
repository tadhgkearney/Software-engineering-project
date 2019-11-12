#ifndef __STA_CK__
#define __STA_CK__

struct Stack;
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int top(struct Stack* stack);

#endif
