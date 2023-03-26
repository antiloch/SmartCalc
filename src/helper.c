#include "helper.h"

void lexeme_print(lexeme *lexemes)
{
    for (struct lexeme lexem = *lexemes; lexem.value_type != END; lexemes++, lexem = *lexemes) {
        if (lexem.value_type == INT_NUMBER)
            printf(" [%d] ", lexem.value);
        else if (lexem.value_type == FLOAT_NUMBER)
            printf(" [%lf] ", lexem.double_num);
        else if (lexem.value_type == OPERATOR) {
            if (lexem.value == LN) printf(" [LN] ");
            else if (lexem.value == LG) printf(" [LG] ");
            else if (lexem.value == SIN) printf(" [SIN] ");
            else if (lexem.value == COS) printf(" [COS] ");
            else if (lexem.value == TAN) printf(" [TAN] ");
            else if (lexem.value == ASIN) printf(" [ASIN] ");
            else if (lexem.value == ACOS) printf(" [ACOS] ");
            else if (lexem.value == ATAN) printf(" [ATAN] ");
            else if (lexem.value == SQRT) printf(" [SQRT] ");
            else printf(" [%c] ", lexem.value);
        }
        else if (lexem.value_type == VARIABLE) {
            printf(" [x] ");
        }
    }
    printf("\n");
}
