#include "defs.h"
#include "data.h"
#include "decl.h"

int interpretAST(struct ASTNode *n) {
    int leftval, rightval;

    leftval = n->left ? interpretAST(n->left) : 0;
    rightval = n->right ? interpretAST(n->right) : 0;

    switch (n->operand)
    {
    case A_ADD:
        return leftval+rightval;
    case A_DIVIDE:
        return leftval/rightval;
    case A_MULTIPLY:
        return leftval*rightval;
    case A_SUBTRACT:
        return leftval-rightval;
    case A_INTLIT:
        return n->intvalue;
    
    default:
        printf("Unknown AST operator %d\n", n->operand);
        exit(1);
    }
}