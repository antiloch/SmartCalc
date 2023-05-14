#include "test_main.h"

START_TEST(sum) {
  char *test = "3+1";
  double result = calculate(test);
  ck_assert_double_eq(result, 4);
}
END_TEST

START_TEST(multi_sum) {
  char *test = "10+800+90+78+83+93.3+211921.42";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 213075.72, 1e-6);
}
END_TEST

START_TEST(one_number) {
  char *test = "211921.42";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 211921.42, 1e-6);
}
END_TEST

START_TEST(lg_ln_sin_cos_tan_sqrt) {
  char *test = "lg(-ln(sin(cos(tan(sqrt(1))))))";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 0.6348208, 1e-6);
}
END_TEST

START_TEST(arcsin) {
  char *test = "asin(0.0)";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  char *test2 = "asin(0.3)";
  result = calculate(test2);
  ck_assert_double_eq_tol(result, 0.304693, 1e-6);
}
END_TEST

START_TEST(arccos) {
  char *test = "acos(1)";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  char *test2 = "acos(0.3)";
  result = calculate(test2);
  ck_assert_double_eq_tol(result, 1.266104, 1e-6);
}
END_TEST

START_TEST(arctan) {
  char *test = "atan(1)";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 0.785398, 1e-6);
  char *test2 = "atan(0.3)";
  result = calculate(test2);
  ck_assert_double_eq_tol(result, 0.291457, 1e-6);
}
END_TEST

START_TEST(nan_calculations) {
  char *test = "0";
  double result = calculate(test);
  ck_assert_double_eq_tol(result, 0, 1e-6);
}
END_TEST

Suite *test_lexeme(void) {
  Suite *s = suite_create("\033[1;33m Calculating tests \033[0m");
  TCase *tc = tcase_create("tc_+");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sum);
  tcase_add_test(tc, multi_sum);
  tcase_add_test(tc, one_number);
  tcase_add_test(tc, lg_ln_sin_cos_tan_sqrt);
  tcase_add_test(tc, arcsin);
  tcase_add_test(tc, arccos);
  tcase_add_test(tc, arctan);
  tcase_add_test(tc, nan_calculations);

  suite_add_tcase(s, tc);
  return s;
}
