#ifndef CALCULATE_H_
#define CALCULATE_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"
#include "number_stack.h"

/// @brief Основная функция, преобразовывает строку в лексемы, лексемы в постфиксную нотацию, вычисляет выражение
/// @param input Входная срока
/// @param result Указатель на значение, куда запишется результат вычисления
/// @param variable Значение переменной x
/// @return 
int calculate(char *input, double *result, double variable);
/// @brief Вычисление выражения на основе разбиения на постфиксные лексемы
/// @param input_lexemes Лексемы с выражением
/// @param variable Значение переменной x
/// @param result Указатель на значение, записываемое в резултат
/// @return 
int stack_calculations(struct lexeme *input_lexemes, double variable, double *result);
/// @brief Обработка суммы
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_sum(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка вычитания
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_sub(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка умножения
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_mul(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка деления
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_div(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка возведения в степень
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_pow(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка натурального логарифма
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_ln(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка десятичного логарифма
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_lg(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка синуса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_sin(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка косинуса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_cos(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка тангенса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_tan(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка арктангенса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_asin(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка арккосинуса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_acos(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка арктангенса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_atan(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка корня
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_sqrt(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка унарного минуса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_unar_minus(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка унарного плюса
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_unar_plus(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);
/// @brief Обработка деления с остатком
/// @param input_lexemes Входная лексема
/// @param status Указатель на стататус ошибки 
/// @param stack Указатель на стэк чисел
/// @param result Указатель на значение, записываемое в резултат
void handle_mod(struct lexeme *input_lexemes, int *status, struct number_stack *stack, double *result);

#ifdef __cplusplus
}
#endif
#endif  // CALCULATE_H_
