#include "static_stack.h"

void initiate(static_stack *stack)
{
    stack->size = 0;
}

void push(static_stack *stack, lexeme element)
{
    stack->data[stack->size] = element;
    stack->size++;
}

struct lexeme pop(static_stack *stack)
{
    // if (stack->size == 0) exit(FAIL);
    stack->size--;
    return stack->data[stack->size];
}
