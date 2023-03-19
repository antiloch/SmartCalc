#include "leksem_creator.h"

int converter_to_lexeme(char **input_str, struct lexeme *output_lexemes)
{
    int result = FAIL;
    while (**input_str != '\0')
    {
        if (handle_number(input_str, output_lexemes)) result = SUCCESS;
        else if (handle_operator(input_str, output_lexemes)) result = SUCCESS;
        else result = FAIL;
        output_lexemes = output_lexemes + 1;
    }
    return result;
}

int handle_number(char **input_str, struct lexeme *output_lexeme)
{
    int result = FAIL;
    if (**input_str <= '9' && **input_str >= '0')
    {
        add_number(input_str, output_lexeme); 
        result = SUCCESS;
    }
    return result;
}

int handle_operator(char **input_str, struct lexeme *output_lexeme)
{   
    int result = SUCCESS;
    output_lexeme->value_type = OPERATOR;
    if (**input_str == '(') output_lexeme->value = '(';
    else if (**input_str == ')') output_lexeme->value = ')';
    else if (**input_str == '*') output_lexeme->value = '*';
    else if (**input_str == '-') output_lexeme->value = '-';
    else if (**input_str == '+') output_lexeme->value = '+';
    else if (**input_str == '/') output_lexeme->value = '/';
    else if (**input_str == '^') output_lexeme->value = '^';
    else result = FAIL;
    *input_str = *input_str + 1;
    return result;
}

void add_number(char **input_str, struct lexeme *output_lexeme)
{
    int int_number = converter_str_to_int(input_str), int_float = 0;
    if (**input_str == '.') {
        *input_str = *input_str + 1;
        int_float = converter_str_to_int(input_str);
    }
    if (int_float == 0)
    {
        output_lexeme->value = int_number;
        output_lexeme->value_type = INT_NUMBER;
    }
    else
    {
        int nDigits = floor(log10(int_float)) + 1;
        output_lexeme->double_num = int_number + int_float * pow(10, -nDigits);
        output_lexeme->value_type = FLOAT_NUMBER;
    }
    
}

int converter_str_to_int(char **input_str)
{
    char *str_number = calloc(255, sizeof(char));
    strncpy(str_number, *input_str, strspn(*input_str, "0123456789"));
    *input_str = *input_str + strspn(*input_str, "0123456789");
    int result = atoi(str_number);
    free(str_number);
    return result;
}
