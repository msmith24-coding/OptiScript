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

Token* makeNumber(Lexer *lexer)
{
    Token* result = (Token*)malloc(sizeof(Token));
    char* numString = NULL;
    bool hasDecimal = false;
    bool isValid = true;
    int position = 0;

    while (isValid && (lexer->currentChar != 0 && (lexer->currentChar == '.' || isdigit(lexer->currentChar)))) {
        if (lexer->currentChar == '.') {
            if (hasDecimal) {
                isValid = false;
            } else {
                hasDecimal = true;
                numString[position++] = '.';
            }
        } else {
            numString[position++] = lexer->currentChar;
        }
        advanceLexer(lexer);
    }

    numString[position] = '\0';

    if (!hasDecimal) {
        result->type = TT_INT;
    } else {
        result->type = TT_FLOAT;
    }
    result->value = numString;

    free(numString);

    return result;
}

Token* makeTokens(Lexer *lexer)
{
    int size = strlen(lexer->src);
    Token* tokensArray = (Token*)malloc((size + 1) * sizeof(Token)); // +1 for termination token

    if(tokensArray == NULL) {
        printf("[ERR] Memory allocation failed.");
        exit(1);
    }

    int position = 0;

    while (lexer->position < size) {
        lexer->position = position; // Update lexer position
        if(lexer->currentChar == ' ' || lexer ->currentChar == '\t') {
            advanceLexer(lexer);
        }
        else if(isdigit(lexer->currentChar)) {
            Token* resultToken = makeNumber(lexer);
            tokensArray[position] = *resultToken;
            position++;
            free(resultToken->value);
            free(resultToken);
        }
        else if(lexer->currentChar == '+') {
            tokensArray[position].type = TT_PLUS;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        }
        else if(lexer->currentChar == '-') {
            tokensArray[position].type = TT_MINUS;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        }
        else if(lexer->currentChar == '*') {
            tokensArray[position].type = TT_MULTIPLY;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        }
        else if(lexer->currentChar == '/') {
            tokensArray[position].type = TT_DIVIDE;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        }
        else if(lexer->currentChar == '(') {
            tokensArray[position].type = TT_LPAREN;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        }
        else if(lexer->currentChar == ')') {
            tokensArray[position].type = TT_RPAREN;
            tokensArray[position].value = "";
            advanceLexer(lexer);
            position++;
        } else {
            exit(1);
        }
        // position++;
    }

    return tokensArray;
    
}