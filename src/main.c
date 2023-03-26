#include "leksem_creator.h"
#include "helper.h"
#include "to_postfix_notation.h"

int main() {
  int result = SUCCESS;
  char *example = "12+14-14*3";
  struct lexeme lexems[255];
  if (converter_to_lexeme(&example, lexems)) {
    lexeme_print(lexems);
    result = to_postfix_notation(lexems);
  } else result = FAIL;
  return !result;
}