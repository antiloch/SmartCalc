#include "to_postfix_notation.h"
#include "helper.h"

int to_postfix_notation(lexeme *input_lexemes)
{
    int result = SUCCESS;
    struct lexeme output_lexemes[255];
    result = create_postix_lexeme(input_lexemes, output_lexemes);
    lexeme_print(output_lexemes);
    return result;
}

int create_postix_lexeme(lexeme *input_lexemes, lexeme *output_lexemes)
{
    int result = SUCCESS;
    struct static_stack stack;
    initiate(&stack);
    while (input_lexemes->value_type != END && result != FAIL)
    {
        int top_stack_value = 0;
        int top_stack_type = 0;
        int top_stack_priority = 0;
        if (stack.size > 0) {
            top_stack_value = stack.data[stack.size - 1].value;
            top_stack_type = stack.data[stack.size - 1].value_type;
            top_stack_priority = stack.data[stack.size - 1].double_num;
        }
        if (input_lexemes->value_type == INT_NUMBER || input_lexemes->value_type == VARIABLE || input_lexemes->value_type == FLOAT_NUMBER)
        {
            *output_lexemes = *input_lexemes;
            output_lexemes = output_lexemes + 1;
        }
        else if (input_lexemes->value >= LN || input_lexemes->value == '(')
        {
            push(&stack, *input_lexemes);
        }
        else if (input_lexemes->value == ')')
        {
            while (top_stack_value != '(' && top_stack_type == OPERATOR && result != FAIL)
            {
                if (stack.size == 0) result = FAIL;
                else {
                    *output_lexemes = pop(&stack);
                    output_lexemes = output_lexemes + 1;
                    top_stack_value = stack.data[stack.size - 1].value;
                    top_stack_type = stack.data[stack.size - 1].value_type;
                }
            }
            pop(&stack);
        }
        else 
        {
            while ((top_stack_value >= LN || top_stack_priority >= input_lexemes->double_num) && stack.size > 0 && top_stack_value != '(')
            {
                *output_lexemes = pop(&stack);
                output_lexemes = output_lexemes + 1;
                top_stack_value = stack.data[stack.size - 1].value;
                top_stack_priority = stack.data[stack.size - 1].double_num;
            }
            push(&stack, *input_lexemes);
        }
        input_lexemes = input_lexemes + 1;
    }
    while (stack.size > 0 && result != FAIL)
    {
        int top_stack_type = stack.data[stack.size - 1].value_type;
        int top_stack_value = stack.data[stack.size - 1].value;
        if (top_stack_type != OPERATOR || top_stack_value == '(' || top_stack_value == ')') result = FAIL;
        else {
            *output_lexemes = pop(&stack);
            output_lexemes = output_lexemes + 1;
        }
    }
    return result;
}
