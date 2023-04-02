#include "calculate.h"

double calculate(char *input)
{
    struct lexeme lexems[255];
    converter_to_lexeme(&input, lexems);
    to_postfix_notation(lexems);
    return stack_calculations(lexems, 0);
}

double stack_calculations(lexeme *input_lexemes, double variable)
{
    double result = 0;
    struct number_stack stack;
    initiate_num(&stack);
    while (input_lexemes->value_type != END)
    {
        if (input_lexemes->value_type == INT_NUMBER) push_num(&stack, input_lexemes->value);
        else if (input_lexemes->value_type == FLOAT_NUMBER) push_num(&stack, input_lexemes->double_num);
        else if (input_lexemes->value_type == VARIABLE) push_num(&stack, variable);
        else if (input_lexemes->value_type == OPERATOR) {
            if (input_lexemes->value == '+') {
                result = pop_num(&stack) + pop_num(&stack);
                push_num(&stack, result);
            }
            else if (input_lexemes->value == '-') {
                result = pop_num(&stack);
                result = pop_num(&stack) - result;
                push_num(&stack, result);
            }
            else if (input_lexemes->value == '*') {
                result = pop_num(&stack) * pop_num(&stack);
                push_num(&stack, result);
            }
            else if (input_lexemes->value == '/') {
                result = pop_num(&stack);
                result = pop_num(&stack) / result;
                push_num(&stack, result);
            }
            else if (input_lexemes->value == '^') {
                result = pop_num(&stack);
                result = pow(pop_num(&stack), result);
                push_num(&stack, result);
            }
            else if (input_lexemes->value == LN) {
                result = log(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == LG) {
                result = log10(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == SIN) {
                result = sin(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == COS) {
                result = cos(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == TAN) {
                result = tan(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == ASIN) {
                result = asin(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == ACOS) {
                result = acos(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == ATAN) {
                result = atan(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == SQRT) {
                result = sqrt(pop_num(&stack));
                push_num(&stack, result);
            }
            else if (input_lexemes->value == UNAR_MINUS) {
                result = -pop_num(&stack);
                push_num(&stack, result);
            }
            else if (input_lexemes->value == UNAR_PLUS) {
                result = pop_num(&stack);
                push_num(&stack, result);
            }
        }
        input_lexemes = input_lexemes + 1;
    }
    return pop_num(&stack);
}
