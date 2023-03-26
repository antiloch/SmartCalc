#ifndef TO_POSTFIX_NOTATION_H_
#define TO_POSTFIX_NOTATION_H_

#include "leksem_creator.h"
#include "static_stack.h"

int to_postfix_notation(struct lexeme *input_lexemes);
int create_postix_lexeme(struct lexeme *input_lexemes, struct lexeme *output_lexemes);

#endif  // TO_POSTFIX_NOTATION_H_