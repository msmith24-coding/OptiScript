#ifndef TOKEN_H_
#define TOKEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct /* Token Class */
{
    char* type;
    char* value;
} Token;

void initToken(Token* token, const char* type, const char* value);
char* tokenAsString(Token* token);

#endif