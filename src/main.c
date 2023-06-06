#include <stdio.h>
#include "./lexer/Lexer.h"

int main(int argc, char** argv)
{
    char* src;
    printf("OptiScript > ");
    scanf("%s", src);

    while(src != "exit();") {
        Lexer lex;
        Token* tokens;
        initLexer(&lex, src);
        tokens = makeTokens(&lex);
        for(int i = 0; i < strlen(src); i++) {
            printf("%s:%s ", tokens[i].type, tokens[i].value);
        }
        printf("\n");
        printf("OptiScript > ");
        scanf("%s", src);

    }
    
    return 0;
}