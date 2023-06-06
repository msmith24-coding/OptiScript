#include "Token.h"

/* Initializes the Token struct. */
void initToken(Token* token, const char* type, const char* value)
{
    strcpy(token->type, type); 
    strcpy(token->value, value);
}

/* Used to output a formatted string. */
char* tokenAsString(Token* token)
{
    char* result; // <-- Result variable used for contatination.
    if(strlen(token->value) != 0) {
        /* Appends the type and value to the result. */
        result = token->type;
        result += ':';
        strcat(result, token->value);
        return result;
    }
    /* Appends the type to the result. */
    result = token->type;
    return result;
}
