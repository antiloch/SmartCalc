#ifndef NUMBER_STACK_H_
#define NUMBER_STACK_H_

typedef struct number_stack
{
    double data[255];
    int size;
} number_stack;

void initiate_num(number_stack *stack);
void push_num(number_stack *stack, double number);
double pop_num(number_stack *stack);
double get_first_number(number_stack *stack);
double get_second_number(number_stack *stack);

#endif