/*
 *      INF01147 - Compiladores - 2019/2 - Practical Assignment
 *      Professor Marcelo Johann
 *      Laura Rodrigues Soares - 00245174
 *      Rodrigo Daltoé Madruga - 00180669
 *
 *      The full specification for this assignment can be found at:
 *      http://www.inf.ufrgs.br/~johann/comp/spect1.pdf
 *
 *      Or on GitHub at:
 *      ~link~
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    initMe();
    int tok, lines;
    while (isRunning())
    {
        tok = yylex();
        switch (tok)
        {
            case LIT_INTEGER: fprintf(stderr, "Literal Integer\n"); break;
            case LIT_FLOAT: fprintf(stderr, "Literal Float\n"); break;
            case LIT_CHAR: fprintf(stderr, "Literal char\n"); break;
            case LIT_TRUE: fprintf(stderr, "Literal true\n"); break;
            case LIT_FALSE: fprintf(stderr, "Literal false\n"); break;
            case LIT_STRING: fprintf(stderr, "Literal string\n"); break;

            case TK_IDENTIFIER: fprintf(stderr, "Identifier\n"); break;


            case KW_BYTE: fprintf(stderr, "Keyword byte\n"); break;
            case KW_INT: fprintf(stderr, "Keyword int\n"); break;
            case KW_LONG: fprintf(stderr, "Keyword long\n"); break;
            case KW_FLOAT: fprintf(stderr, "Keyword float\n"); break;
            case KW_BOOL: fprintf(stderr, "Keyword bool\n"); break;

            case KW_IF: fprintf(stderr, "Keyword if\n"); break;
            case KW_THEN: fprintf(stderr, "Keyword then\n"); break;
            case KW_ELSE: fprintf(stderr, "Keyword else\n"); break;
            case KW_WHILE: fprintf(stderr, "Keyword while\n"); break;
            case KW_FOR: fprintf(stderr, "Keyword for\n"); break;
            case KW_READ: fprintf(stderr, "Keyword read\n"); break;
            case KW_PRINT: fprintf(stderr, "Keyword print\n"); break;
            case KW_RETURN: fprintf(stderr, "Keyword return\n"); break;
            case KW_BREAK: fprintf(stderr, "Keyword break\n"); break;

            case OPERATOR_LE: fprintf(stderr, "Operator '<='\n"); break;
            case OPERATOR_GE: fprintf(stderr, "Operator '>='\n"); break;
            case OPERATOR_EQ: fprintf(stderr, "Operator '=='\n"); break;
            case OPERATOR_DIF: fprintf(stderr, "Operator '!='\n"); break;

            case TOKEN_ERROR: fprintf(stderr, "Unrecognized token: %s\n", yytext); break;

            default: fprintf(stderr, "Unknown error at token: %s\n", yytext); break;
            //i don't know if we should be using yytext at this point of the code??

        }
    }
    hashPrint();
    lines = getLineNumber();
    fprintf(stderr, "Number of lines in file: %d.\n", lines);
}
