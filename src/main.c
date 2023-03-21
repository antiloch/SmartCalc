#include "leksem_creator.h"
#include "printer.h"

int main() {
  char *example = "sin(cos(tan(asin(acos(atan(ln(lg(sqrt(x+2*4)))))))))\0";
  struct lexeme lexems[255];
  int result = converter_to_lexeme(&example, lexems);
  lexeme_print(lexems);
  return !result;
}