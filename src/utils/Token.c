#include "Token.h"

/* Initializes the Token struct. */
void initToken(Token* token, const char* type, const char* value)
{
    token->type = (char*)malloc((strlen(type) + 1) * sizeof(char));
    strcpy(token->type, type); 
    token->value = (char*)malloc((strlen(value) + 1) * sizeof(char));
    strcpy(token->value, value);
}
 
/* Used to output a formatted string. */
char* tokenAsString(Token* token)
{
    size_t length = strlen(token->type) + strlen(token->value) + 2;
    char* result = (char*)malloc(length * sizeof(char));

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    if (strlen(token->value) > 0) {
        /* Appends the type and value to the result. */
        snprintf(result, length, "%s:%s", token->type, token->value);
    } else {
        /* Appends only the type to the result. */
        snprintf(result, length, "%s", token->type);
    }
    return result;
}
