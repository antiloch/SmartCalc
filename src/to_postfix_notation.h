#ifndef TO_POSTFIX_NOTATION_H_
#define TO_POSTFIX_NOTATION_H_

#include "leksem_creator.h"
#include "static_stack.h"

int to_postfix_notation(struct lexeme *input_lexemes);
int create_postfix_lexeme(struct lexeme *input_lexemes, struct lexeme *output_lexemes);
int while_lexemes_to_read(struct lexeme *input_lexemes, struct lexeme **output_lexemes, struct static_stack *stack);
void check_number(struct lexeme *input_lexemes, struct lexeme **output_lexemes);
void check_prefix_open_bracket(struct lexeme *input_lexemes, struct static_stack *stack);
int check_close_braket(struct lexeme **output_lexemes, struct static_stack *stack);
void check_operation(struct lexeme *input_lexemes, struct lexeme **output_lexemes, struct static_stack *stack);
int pops_remain_operators(struct lexeme **output_lexemes, struct static_stack *stack);
void change_input_to_output(struct lexeme *input_lexemes, struct lexeme *output_lexemes);

#endif  // TO_POSTFIX_NOTATION_H_