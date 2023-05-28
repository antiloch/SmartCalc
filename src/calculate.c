#include "calculate.h"

int calculate(char *input, double *result)
{
    struct lexeme lexems[255];
    int status = SUCCESS;
    status = converter_to_lexeme(&input, lexems);
    if (status != FAIL) {
        status = to_postfix_notation(lexems);
        if (status != FAIL) {
            status = stack_calculations(lexems, 0, result);
        }
    }
    return status;
}

int stack_calculations(lexeme *input_lexemes, double variable, double *result)
{
    int status = SUCCESS;
    struct number_stack stack;
    initiate_num(&stack);
    if (input_lexemes->value_type == END) status = FAIL;
    while (input_lexemes->value_type != END)
    {
        if (input_lexemes->value_type == INT_NUMBER) push_num(&stack, input_lexemes->value);
        else if (input_lexemes->value_type == FLOAT_NUMBER) push_num(&stack, input_lexemes->double_num);
        else if (input_lexemes->value_type == VARIABLE) push_num(&stack, variable);
        else if (input_lexemes->value_type == OPERATOR) {
            handle_sum(input_lexemes, &status, &stack, result);
            handle_sub(input_lexemes, &status, &stack, result);
            handle_mul(input_lexemes, &status, &stack, result);
            handle_div(input_lexemes, &status, &stack, result);
            handle_pow(input_lexemes, &status, &stack, result);
            handle_ln(input_lexemes, &status, &stack, result);
            handle_lg(input_lexemes, &status, &stack, result);
            handle_sin(input_lexemes, &status, &stack, result);
            handle_cos(input_lexemes, &status, &stack, result);
            handle_tan(input_lexemes, &status, &stack, result);
            handle_asin(input_lexemes, &status, &stack, result);
            handle_acos(input_lexemes, &status, &stack, result);
            handle_atan(input_lexemes, &status, &stack, result);
            handle_sqrt(input_lexemes, &status, &stack, result);
            handle_unar_minus(input_lexemes, &status, &stack, result);
            handle_unar_plus(input_lexemes, &status, &stack, result);
            handle_mod(input_lexemes, &status, &stack, result);
        }
        input_lexemes = input_lexemes + 1;
    }
    *result = pop_num(&stack);
    return status;
}

void handle_sum(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == '+') {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack) + pop_num(stack);
        push_num(stack, *result);
    }
}

void handle_sub(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == '-') {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack);
        *result = pop_num(stack) - *result;
        push_num(stack, *result);
    }
}

void handle_mul(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == '*') {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack) * pop_num(stack);
        push_num(stack, *result);
    }
}

void handle_div(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == '/') {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack);
        if (*result == 0) *status = FAIL;
        *result = pop_num(stack) / *result;
        push_num(stack, *result);
    }
}

void handle_pow(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == '^') {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack);
        *result = pow(pop_num(stack), *result);
        push_num(stack, *result);
    }
}

void handle_ln(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == LN) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        if (*result <= 0) *status = FAIL;
        *result = log(*result);
        push_num(stack, *result);
    }
}

void handle_lg(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == LG) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        if (*result <= 0) *status = FAIL;
        *result = log10(*result);
        push_num(stack, *result);
    }
}

void handle_sin(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == SIN) {
        if (stack->size < 1) *status = FAIL;
        *result = sin(pop_num(stack));
        push_num(stack, *result);
    }
}

void handle_cos(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == COS) {
        if (stack->size < 1) *status = FAIL;
        *result = cos(pop_num(stack));
        push_num(stack, *result);
    }
}

void handle_tan(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == TAN) {
        if (stack->size < 1) *status = FAIL;
        *result = tan(pop_num(stack));
        push_num(stack, *result);
    }
}

void handle_asin(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == ASIN) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        if (*result < -1 || *result > 1) *status = FAIL;
        *result = asin(*result);
        push_num(stack, *result);
    }
}

void handle_acos(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == ACOS) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        if (*result < -1 || *result > 1) *status = FAIL;
        *result = acos(*result);
        push_num(stack, *result);
    }
}

void handle_atan(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == ATAN) {
        if (stack->size < 1) *status = FAIL;
        *result = atan(pop_num(stack));
        push_num(stack, *result);
    }
}

void handle_sqrt(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == SQRT) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        if (*result < 0) *status = FAIL;
        *result = sqrt(*result);
        push_num(stack, *result);
    }
}

void handle_unar_minus(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == UNAR_MINUS) {
        if (stack->size < 1) *status = FAIL;
        *result = -pop_num(stack);
        push_num(stack, *result);
    }
}

void handle_unar_plus(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == UNAR_PLUS) {
        if (stack->size < 1) *status = FAIL;
        *result = pop_num(stack);
        push_num(stack, *result);
    }
}

void handle_mod(lexeme *input_lexemes, int *status, number_stack *stack, double *result)
{
    if (input_lexemes->value == MOD) {
        if (stack->size < 2) *status = FAIL;
        *result = pop_num(stack);
        if (*result == 0) *status = FAIL;
        *result = fmod(pop_num(stack), *result);
        push_num(stack, *result);
    }
}
