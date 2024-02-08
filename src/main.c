#define extern_
#include "data.h"
#undef extern_
#include "defs.h"
#include "decl.h"


static void init()
{
    Line = 1;
    Putback = '\n';
}

static void usage(char *prog)
{
    printf("Usage: %s <infile>\n", prog);
    exit(1);
}

// List of printable tokens
char *tokstr[] = {"+", "-", "*", "/", "intlit"};

static void scanfile()
{
    struct token T;

    while (scan(&T))
    {
        printf("Token %s", tokstr[T.token]);
        if (T.token == T_INTLIT)
        {
            printf(", value %d", T.intvalue);
        }
        printf("\n");
    }
}

void main(int argc, char *argv[])
{
    struct ASTNode *n;
    init();

    if (argc != 2)
    {
        usage(argv[0]);
        exit(1);
    }

    if ((Infile = fopen(argv[1], "r")) == NULL)
    {
        printf("Couldn't open file %s\n", argv[1]);
        exit(1);
    }

    scan(&Token);
    n = binexpr();
    printf("%d\n", interpretAST(n));

    exit(0);
}