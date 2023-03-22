#include "leksem_creator.h"
#include "helper.h"

int main() {
  char *example = "1+sin(cos(tan(asin(acos(atan(ln(lg(sqrt(x+2*4^3.424323)))))))))\0";
  struct lexeme lexems[255];
  int result = converter_to_lexeme(&example, lexems);
  lexeme_print(lexems);
  return !result;
}