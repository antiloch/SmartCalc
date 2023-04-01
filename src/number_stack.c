#include "number_stack.h"

void initiate_num(number_stack *stack)
{
    stack->size = 0;
}

void push_num(number_stack *stack, double number)
{
    stack->data[stack->size] = number;
    stack->size++;
}

double pop_num(number_stack *stack)
{
    stack->size--;
    return stack->data[stack->size];
}

double get_first_number(number_stack *stack)
{
    return stack->data[stack->size - 1];
}

double get_second_number(number_stack *stack)
{
    return stack->data[stack->size - 2];
}
