#include "defs.h"
#include "data.h"
#include "decl.h"


static int next(void)
{
	int c;

	if (Putback)
	{
		c = Putback;
		Putback = 0;
		return c;
	}

	c = fgetc(Infile);

	if ('\n' == c)
		Line++;

	return c;
}

// Put back an unwanted character
static void putback(int c)
{
	Putback = c;
}

// Skip past input we don't need to deal with,
// i.e. whitespace, newlines. Return the first
// character we do need.
static int skip(void)
{
	int c;

	c = next();
	while (' ' == c || '\n' == c || '\t' == c || '\r' == c || '\f' == c)
	{
		c = next();
	}

	return c;
}

static int chrpos(char *s, int c)
{
	char *p;

	p = strchr(s, c);
	return (p ? p - s : -1);
}

static int scanint(int c)
{
	int k, val = 0;

	while ((k = chrpos("0123456789", c)) >= 0)
	{
		val = val * 10 + k;
		c = next();
	}

	putback(c);
	return val;
}



int scan(struct token *t)
{
	int c;

	c = skip();

	switch (c)
	{
	case EOF:
		t->token = T_EOF;
		return 0;
		break;
	case '+':
		t->token = T_PLUS;
		break;
	case '-':
		t->token = T_MINUS;
		break;
	case '*':
		t->token = T_STAR;
		break;
	case '/':
		t->token = T_SLASH;
		break;
	default:

		if (isdigit(c))
		{
			t->token = T_INTLIT;
			t->intvalue = scanint(c);
			break;
		}

		printf("Unrecognized character %c on line %d\n", c, Line);
		exit(1);
	}

	return 1;
}
