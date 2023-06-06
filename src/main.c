#include <stdio.h>
#include "./lexer/Lexer.h"

int main(int argc, char** argv)
{
    char src[100];
    printf("OptiScript > ");
    while (fgets(src, sizeof(src), stdin) != NULL && strcmp(src, "exit();\n") != 0) {
        src[strcspn(src, "\n")] = '\0'; // Remove trailing newline

        Lexer lex;
        Token* tokens;
        initLexer(&lex, src);
        tokens = makeTokens(&lex);
        for (int i = 0; i < lex.position; i++) {
            char* str = tokenAsString(&tokens[i]);
            printf("%s ", str);
            free(str);
        }
        printf("\n");
        printf("OptiScript > ");
    }

    return 0;
}