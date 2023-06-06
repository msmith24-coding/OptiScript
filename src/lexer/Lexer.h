#ifndef LEXER_H_
#define LEXER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../utils/Token.h"
#include "../utils/TokenType.h"

typedef struct /* Lexer Class */
{
    char *src;
    int position;
    char currentChar;
} Lexer;

void initLexer(Lexer *lexer, char* src);
void advanceLexer(Lexer *lexer);
Token* makeTokens(Lexer *lexer);
Token makeNumber(Lexer *lexer);

#endif