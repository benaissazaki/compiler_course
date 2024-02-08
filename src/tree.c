#include "defs.h"
#include "data.h"
#include "decl.h"

struct ASTNode *mkastnode(int op, struct ASTNode *left, struct ASTNode *right, int intvalue)
{
    struct ASTNode *newNode;

    newNode = (struct ASTNode *)malloc(sizeof(struct ASTNode));

    if (newNode == NULL)
    {
        printf("Failed to allocate memory for AST Node\n");
        exit(1);
    }

    newNode->operand = op;
    newNode->left = left;
    newNode->right = right;
    newNode->intvalue = intvalue;

    return newNode;
}

struct ASTNode *mkastleaf(int op, int intvalue)
{
    return mkastnode(op, NULL, NULL, intvalue);
}

struct ASTNode *mkastunary(int op, struct ASTNode *left, int intvalue)
{
    return mkastnode(op, left, NULL, intvalue);
}

static struct ASTNode *primary(void)
{
    struct ASTNode *n;

    switch (Token.token)
    {
    case T_INTLIT:
        n = mkastleaf(A_INTLIT, Token.intvalue);
        scan(&Token);
        return n;

    default:
        printf("Syntax error on line %d\n", Line);
        exit(1);
    }
}

struct ASTNode *binexpr()
{
    struct ASTNode *n, *left, *right;
    int op;

    left = primary();

    if (Token.token == T_EOF)
    {
        return left;
    }

    op = arithop(Token.token);

    scan(&Token);

    right = binexpr();

    n = mkastnode(op, left, right, 0);

    return n;
}