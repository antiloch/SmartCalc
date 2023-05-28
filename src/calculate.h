#ifndef CALCULATE_H_
#define CALCULATE_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"
#include "number_stack.h"

int calculate(char *input, double *result);
int stack_calculations(struct lexeme *input_lexemes, double variable, double *result);

#ifdef __cplusplus
}
#endif
#endif  // CALCULATE_H_
