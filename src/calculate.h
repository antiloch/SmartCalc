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
void handle_sum(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_sub(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_mul(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_div(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_pow(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_ln(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_lg(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_sin(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_cos(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_tan(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_asin(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_acos(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_atan(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_sqrt(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_unar_minus(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
void handle_unar_plus(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);

#ifdef __cplusplus
}
#endif
#endif  // CALCULATE_H_
