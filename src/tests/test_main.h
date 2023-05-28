#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../calculate.h"

Suite *test_calculations(void);
Suite *test_errors(void);

#endif  // SRC_TESTS_MAIN_H
