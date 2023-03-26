#ifndef LEXEME_CREATOR_H_
#define LEXEME_CREATOR_H_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_NUMBER 1
#define FLOAT_NUMBER 2
#define OPERATOR 3
#define VARIABLE 4
#define END 0

#define SUCCESS 1
#define FAIL 0

#define LN 1000
#define LG 1001
#define SIN 2000
#define COS 2001
#define TAN 2002
#define ASIN 2010
#define ACOS 2011
#define ATAN 2012
#define SQRT 3000
#define UNAR_MINUS 4000
#define UNAR_PLUS 4001

#define LOW_PRIORITY 0
#define MID_PRIORITY 1
#define HIGH_PRIORITY 2
#define SUPREME_PRIORITY 3

typedef struct lexeme {
  int value;
  double double_num;
  int value_type;
} lexeme;

int converter_to_lexeme(char **input_str, struct lexeme *output_lexemes);
int handle_number(char **input_str, struct lexeme *output_lexeme);
int handle_operator(char **input_str, struct lexeme *output_lexeme);
int handle_variable(char **input_str, struct lexeme *output_lexeme);
int one_symbol_operator(char **input_str, struct lexeme *output_lexeme);
int multi_symbol_operator(char **input_str, struct lexeme *output_lexeme);
void add_number(char **input_str, struct lexeme *output_lexeme);
void read_number(char **input_str, int *int_number, int *int_float);
void write_number(struct lexeme *output_lexeme, int int_number, int int_float);
int converter_str_to_int(char **input_str);

#endif  // LEXEME_CREATOR_H_