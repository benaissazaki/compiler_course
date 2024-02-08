#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct token {
	int token;
	int intvalue;
};

enum {
	T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT, T_EOF
};

// AST node types
enum {
	A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

// Abstract Syntax Tree structure
struct ASTNode {
	int operand;
	struct ASTNode *left;
	struct ASTNode *right;
	int intvalue;
};