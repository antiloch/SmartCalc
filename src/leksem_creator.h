#ifndef LEXEME_CREATOR_H_
#define LEXEME_CREATOR_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INT_NUMBER 1
#define FLOAT_NUMBER 2
#define OPERATOR 3
#define END 0 
#define SUCCESS 1
#define FAIL 0

typedef struct lexeme
{
    int value;
    double double_num;
    int value_type;
} lexeme;

int converter_to_lexeme(char **input_str, struct lexeme *output_lexemes);
int handle_number(char **input_str, struct lexeme *output_lexeme);
int handle_operator(char **input_str, struct lexeme *output_lexeme);
void add_number(char **input_str, struct lexeme *output_lexeme);
int converter_str_to_int(char **input_str);


#endif // LEXEME_CREATOR_H_