#ifndef STATIC_STACK_H_
#define STATIC_STACK_H_

#include "leksem_creator.h"

typedef struct static_stack
{
    struct lexeme data[255];
    int size;
} static_stack;

void initiate(static_stack *stack);
void push(static_stack *stack, struct lexeme element);
struct lexeme pop(static_stack *stack);
struct lexeme get_top_lexeme(static_stack *stack);

#endif  // STATIC_STACK_H_