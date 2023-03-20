#include "leksem_creator.h"

int main() {
  char *example = "2+sin3-3.45*(2+14)\0";
  struct lexeme lexems[255];
  int result = converter_to_lexeme(&example, lexems);
  for (int i = 0; i < 255 && lexems[i].value_type != END; i++) {
    if (lexems[i].value_type == INT_NUMBER)
      printf(" [%d] ", lexems[i].value);
    else if (lexems[i].value_type == FLOAT_NUMBER)
      printf(" [%lf] ", lexems[i].double_num);
    else if (lexems[i].value_type == OPERATOR)
      printf(" [%c] ", lexems[i].value);
  }
  return !result;
  // free(lexems);
}