#include "test_main.h"

START_TEST(sum) {
  char *test = "3+1";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq(result, 4);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(multi_sum) {
  char *test = "10+800+90+78+83+93.3+211921.42";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 213075.72, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(one_number) {
  char *test = "211921.42";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 211921.42, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(lg_ln_sin_cos_tan_sqrt) {
  char *test = "lg(-ln(sin(cos(tan(sqrt(1))))))";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 0.6348208, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(arcsin) {
  char *test = "asin(0.0)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
  char *test2 = "asin(0.3)";
  status = calculate(test2, &result);
  ck_assert_double_eq_tol(result, 0.304693, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(arccos) {
  char *test = "acos(1)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
  char *test2 = "acos(0.3)";
  status = calculate(test2, &result);
  ck_assert_double_eq_tol(result, 1.266104, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(arctan) {
  char *test = "atan(1)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 0.785398, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
  char *test2 = "atan(0.3)";
  status = calculate(test2, &result);
  ck_assert_double_eq_tol(result, 0.291457, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(dificult_calculation) {
  char *test = "cos(ln(45)-12)";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, -0.3328797, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
  char *test2 = "lg(sin(8*16)/sqrt(256))";
  status = calculate(test2, &result);
  ck_assert_double_eq_tol(result, -1.34616200, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(great_number) {
  char *test = "1000000000000";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 1000000000000, 1);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

START_TEST(mod) {
  char *test = "6mod2";
  double result = 0;
  int status = calculate(test, &result);
  ck_assert_double_eq_tol(result, 0, 1e-6);
  ck_assert_int_eq(status, SUCCESS);
}
END_TEST

Suite *test_calculations(void) {
  Suite *s = suite_create("\033[1;33m Calculating tests \033[0m");
  TCase *tc = tcase_create("tc_C");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sum);
  tcase_add_test(tc, multi_sum);
  tcase_add_test(tc, one_number);
  tcase_add_test(tc, lg_ln_sin_cos_tan_sqrt);
  tcase_add_test(tc, arcsin);
  tcase_add_test(tc, arccos);
  tcase_add_test(tc, arctan);
  tcase_add_test(tc, dificult_calculation);
  tcase_add_test(tc, great_number);
  tcase_add_test(tc, mod);

  suite_add_tcase(s, tc);
  return s;
}
