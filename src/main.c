#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"
#include "calculate.h"

int main() {
  int result = SUCCESS;
  char *example = "3*(-2+1)";
  calculate(example);
  return !result;
}