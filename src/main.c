#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"
#include "calculate.h"

int main() {
  int result = SUCCESS;
  char *example = "20-1+1+1.4";
  calculate(example);
  return !result;
}