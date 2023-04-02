#include "test_main.h"

START_TEST(simple_calculate1) {
  char *test = "3+1";
  double result = calculate(test);
  ck_assert_double_eq(result, 4);
}
END_TEST


START_TEST(simple_calculate2) {
  char *test = "3+2+10+800+90+78+83+93.3+211921.42";
  double result = calculate(test);
  ck_assert_double_eq(result, 213080.72);
}
END_TEST

Suite *test_lexeme(void) {
  Suite *s = suite_create("\033[1;33m + \033[0m");
  TCase *tc = tcase_create("tc_+");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, simple_calculate1);
  tcase_add_test(tc, simple_calculate2);

  suite_add_tcase(s, tc);
  return s;
}
