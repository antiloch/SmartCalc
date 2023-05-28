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
    stack->size--;
    return stack->data[stack->size];
}

lexeme get_top_lexeme(static_stack *stack)
{
    return stack->data[stack->size - 1];
}
