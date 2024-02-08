#include "defs.h"
#include "data.h"

// Convert token into AST op
int arithop(int token)
{
    switch (token)
    {
    case T_PLUS:
        return A_ADD;
        break;
    case T_MINUS:
        return A_SUBTRACT;
        break;
    case T_STAR:
        return A_MULTIPLY;
        break;
    case T_SLASH:
        return A_DIVIDE;
        break;
    default:
        printf("Unknown token in arithop() on line %d\n", Line);
        exit(1);
    }
}