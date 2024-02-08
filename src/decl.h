int scan(struct token *t);
struct ASTNode *mkASTNode(int op, struct ASTNode *left,
			  struct ASTNode *right, int intvalue);
struct ASTNode *mkastleaf(int op, int intvalue);
struct ASTNode *mkastunary(int op, struct ASTNode *left, int intvalue);
struct ASTNode *binexpr(void);
int interpretAST(struct ASTNode *n);