#include "to_postfix_notation.h"
#include "helper.h"

int to_postfix_notation(lexeme *input_lexemes)
{
    int result = SUCCESS;
    struct lexeme output_lexemes[255];
    lexemes_initiate(output_lexemes);
    result = create_postfix_lexeme(input_lexemes, output_lexemes);
    change_input_to_output(input_lexemes, output_lexemes);
    return result;
}

int create_postfix_lexeme(lexeme *input_lexemes, lexeme *output_lexemes)
{
    int result = SUCCESS;
    struct static_stack stack;
    initiate(&stack);
    result = while_lexemes_to_read(input_lexemes, &output_lexemes, &stack);
    if (result != FAIL) result = pops_remain_operators(&output_lexemes, &stack);
    return result;
}

int while_lexemes_to_read(lexeme *input_lexemes, lexeme **output_lexemes, static_stack *stack)
{
    int result = SUCCESS;
    while (input_lexemes->value_type != END && result != FAIL)
    {
        if (input_lexemes->value_type == INT_NUMBER || input_lexemes->value_type == VARIABLE || input_lexemes->value_type == FLOAT_NUMBER) check_number(input_lexemes, output_lexemes);
        else if (input_lexemes->value >= LN || input_lexemes->value == '(') check_prefix_open_bracket(input_lexemes, stack);
        else if (input_lexemes->value == ')') result = check_close_braket(output_lexemes, stack);
        else if (result != FAIL) check_operation(input_lexemes, output_lexemes, stack);
        input_lexemes = input_lexemes + 1;
    }
    return result;
}

void check_number(lexeme *input_lexemes, lexeme **output_lexemes)
{
    **output_lexemes = *input_lexemes;
    *output_lexemes = *output_lexemes + 1;
}

void check_prefix_open_bracket(lexeme *input_lexemes, static_stack *stack)
{
    push(stack, *input_lexemes);
}

int check_close_braket(lexeme **output_lexemes, static_stack *stack)
{
    int result = SUCCESS;
    while (get_top_lexeme(stack).value != '(' && result != FAIL)
    {
        if (stack->size == 0) result = FAIL;
        else {
            **output_lexemes = pop(stack);
            *output_lexemes = *output_lexemes + 1;
        }
    }
    pop(stack);
    return result;
}

void check_operation(lexeme *input_lexemes, lexeme **output_lexemes, static_stack *stack)
{
    while ((get_top_lexeme(stack).value >= LN || get_top_lexeme(stack).priority >= input_lexemes->priority) && stack->size > 0 && get_top_lexeme(stack).value != '(')
    {
        **output_lexemes = pop(stack);
        *output_lexemes = *output_lexemes + 1;
    }
    push(stack, *input_lexemes);
}

int pops_remain_operators(lexeme **output_lexemes, static_stack *stack)
{
    int result = SUCCESS;
    while (stack->size > 0 && result != FAIL)
    {
        if (get_top_lexeme(stack).value_type != OPERATOR || get_top_lexeme(stack).value == '(' || get_top_lexeme(stack).value == ')') result = FAIL;
        else {
            **output_lexemes = pop(stack);
            *output_lexemes = *output_lexemes + 1;
        }
    }
    return result;
}

void change_input_to_output(lexeme *input_lexemes, lexeme *output_lexemes)
{
    while (input_lexemes->value_type != END)
    {
        *input_lexemes = *output_lexemes;
        input_lexemes = input_lexemes + 1;
        output_lexemes = output_lexemes + 1;
    }
    input_lexemes->value_type = END;
}
