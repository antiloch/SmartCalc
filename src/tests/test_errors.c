#include "test_main.h"

START_TEST(error_no_numbers) {
  char *test = "((+))";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_extra_brackets) {
  char *test = "((1+2)))";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
  char *test2 = "((1)";
  status = calculate(test2, &result);
  ck_assert_int_eq(status, FAIL);
  char *test3 = "((0";
  status = calculate(test3, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_sqrt_less_zero) {
  char *test = "sqrt(-1)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_div_zero) {
  char *test = "1/0";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_arc_more_than_one) {
  char *test = "asin(2)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
  char *test2 = "acos(2)";
  status = calculate(test2, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_log_less_zero) {
  char *test = "ln(-1)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
  char *test2 = "lg(-1)";
  status = calculate(test2, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_no_such_function) {
  char *test = "lypsafkjnsgljb";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
  char *test2 = "lf(10)";
  status = calculate(test2, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

START_TEST(error_blank_request) {
  char *test = "";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_int_eq(status, FAIL);
}
END_TEST

Suite *test_errors(void) {
  Suite *s = suite_create("\033[1;33m Error tests \033[0m");
  TCase *tc = tcase_create("tc_E");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, error_no_numbers);
  tcase_add_test(tc, error_extra_brackets);
  tcase_add_test(tc, error_sqrt_less_zero);
  tcase_add_test(tc, error_div_zero);
  tcase_add_test(tc, error_arc_more_than_one);
  tcase_add_test(tc, error_log_less_zero);
  tcase_add_test(tc, error_no_such_function);
  tcase_add_test(tc, error_blank_request);

  suite_add_tcase(s, tc);
  return s;
}
