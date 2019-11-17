#ifndef __STA_CK__
#define __STA_CK__

struct Stack;
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void pushF(struct Stack* stack, float item);
float popF(struct Stack* stack);
float topF(struct Stack* stack);

#endif
