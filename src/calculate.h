#ifndef CALCULATE_H_
#define CALCULATE_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"
#include "number_stack.h"

double calculate(char *input);
double stack_calculations(struct lexeme *input_lexemes, double variable);

#ifdef __cplusplus
}
#endif
#endif  // CALCULATE_H_
