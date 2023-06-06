#include "Lexer.h"

void initLexer(Lexer *lexer, char* src)
{
    lexer->src = src; 
    lexer->position = -1;
    lexer->currentChar = 0;
    advanceLexer(lexer);
}

void advanceLexer(Lexer *lexer)
{
    lexer->position++;
    if(lexer->position < strlen(lexer->src)) {
        lexer->currentChar = lexer->src[lexer->position];
    } else {
        lexer->currentChar = 0;
    }
}

Token makeNumber(Lexer *lexer)
{
    Token result;
    char* numString;
    bool hasDecimal = false;
    bool isValid = true;

    while(isValid && (lexer->currentChar != 0 && (lexer->currentChar == '.' || isdigit(lexer->currentChar)))) {
        if(lexer->currentChar == '.') {
            if(hasDecimal) {
                isValid = false;
            } else {
                hasDecimal = true;
                numString += '.';
            }
        } else {
            numString += lexer->currentChar;
        }
        advanceLexer(lexer);
    }

    if(!hasDecimal) {
        result.type = TT_INT;
        result.value = numString;
        return result;
    } 
    result.type = TT_FLOAT;
    result.value = numString;
    return result;

}

Token* makeTokens(Lexer *lexer)
{
    int size = strlen(lexer->src);
    Token* tokensArray = (Token*)malloc(size * sizeof(Token));

    if(tokensArray == NULL) {
        printf("[ERR] Memory allocation failed.");
        exit(1);
    }


    while(lexer->position < size) {
        if(lexer->currentChar == ' ' || lexer ->currentChar == '\t') {
            advanceLexer(lexer);
        }
        else if(isdigit(lexer->currentChar)) {
            Token resultToken = makeNumber(lexer);
            tokensArray[lexer->position].type = resultToken.type;
            tokensArray[lexer->position].value = resultToken.value;
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == '+') {
            tokensArray[lexer->position].type = TT_PLUS;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == '-') {
            tokensArray[lexer->position].type = TT_MINUS;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == '*') {
            tokensArray[lexer->position].type = TT_MULTIPLY;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == '/') {
            tokensArray[lexer->position].type = TT_DIVIDE;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == '(') {
            tokensArray[lexer->position].type = TT_LPAREN;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        }
        else if(lexer->currentChar == ')') {
            tokensArray[lexer->position].type = TT_RPAREN;
            tokensArray[lexer->position].value = "";
            advanceLexer(lexer);
        } else {
            exit(1);
        }
    }

    return tokensArray;
    
}