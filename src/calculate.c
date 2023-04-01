#include "calculate.h"

int calculate(char *input)
{
    struct lexeme lexems[255];
    converter_to_lexeme(&input, lexems);
    lexeme_print(lexems);
    to_postfix_notation(lexems);
    lexeme_print(lexems);
    printf("%lf\n", stack_calculations(lexems, 5));
    return 0;
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
        }
        input_lexemes = input_lexemes + 1;
        printf("HERE, %lf\n", get_first_number(&stack));
    }
    return pop_num(&stack);
}
