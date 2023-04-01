#include "test_main.h"

START_TEST(simple_calculate) {
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *test_lexeme(void) {
  Suite *s = suite_create("\033[1;33m  LEXEME  \033[0m");
  TCase *tc = tcase_create("tc_lexeme");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, simple_calculate);

  suite_add_tcase(s, tc);
  return s;
}
