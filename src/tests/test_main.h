#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../leksem_creator.h"
#include "../static_stack.h"
#include "../to_postfix_notation.h"
#include "../calculate.h"

Suite *test_calculations(void);
Suite *test_errors(void);

#endif  // SRC_TESTS_MAIN_H
