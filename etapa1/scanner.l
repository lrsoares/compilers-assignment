%{
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


//comments in // and /* ... */ are ok inside a .c code block.
//outside it, comments must be in /* ... */ format preceeded by a tab,
    /* like this. */

#include "hash.c"
#include "tokens.h"

int lineNumber = 1;

%}

DIGIT [0-9]
SPECIAL [,;\:\(\)\{\}\[\]\+\-\*\/<>=\.~&$#]

%x COMMENT

%%

"v"             {return yytext[0];}
    /* this rule must be before TK_IDENTIFIER, otherwise 'v' will be considered an identifier */

"byte"          {return KW_BYTE;}
"int"           {return KW_INT;}
"long"          {return KW_LONG;}
"float"         {return KW_FLOAT;}
"bool"          {return KW_BOOL;}

"if"            {return KW_IF;}
"then"          {return KW_THEN;}
"else"          {return KW_ELSE;}
"while"         {return KW_WHILE;}
"for"           {return KW_FOR;}
"read"          {return KW_READ;}
"print"         {return KW_PRINT;}
"return"        {return KW_RETURN;}
"break"         {return KW_BREAK;}

"<="            {return OPERATOR_LE;}
">="            {return OPERATOR_GE;}
"=="            {return OPERATOR_EQ;}
"!="            {return OPERATOR_DIF;}

"TRUE"          {return LIT_TRUE;}
"FALSE"         {return LIT_FALSE;}


[A-Za-z_][A-Za-z_0-9]*  {hashInsert(yytext);
                            return TK_IDENTIFIER;}
{DIGIT}+                {hashInsert(yytext);
                            return LIT_INTEGER;}

    /* literal float must be inserted in hash as well? */
{DIGIT}+"."{DIGIT}+     {hashInsert(yytext);
                            return LIT_FLOAT;}
{DIGIT}*"."{DIGIT}+     {hashInsert(yytext);
                            return LIT_FLOAT;}
{DIGIT}+"."{DIGIT}*     {hashInsert(yytext);
                            return LIT_FLOAT;}


"'"."'"                 {yytext[2] = 0;
                        hashInsert(&yytext[1]);
                            return LIT_CHAR;}

"\""[^\"]+"\""          {yytext[strlen(yytext)-1] = 0;
                        hashInsert(&yytext[1]);
                            return LIT_STRING;}

    /* this rule is used to process a \" inside a string */
[\"].*"\\\"".*[\"]      {yytext[strlen(yytext)-1] = 0;
                        hashInsert(&yytext[1]);
                            return LIT_STRING;}

    /* the multiple lines comment rule must be before the ascii token rule, otherwise ### will be considered as three '#' tokens */
"###"            BEGIN(COMMENT);
<COMMENT>"###"   BEGIN(INITIAL);
<COMMENT>"\n"   ++lineNumber;
<COMMENT>.      {}

{SPECIAL}       {return yytext[0];}


[ \t]           {}
"\n"            ++lineNumber;
"//".*          {}
.               {return TOKEN_ERROR;}

%%

int running = 1;

void initMe(void)
{
    hashInit();
}

int getLineNumber(void)
{
    return lineNumber;
}

int isRunning(void)
{
    return running;
}

int yywrap(void)
{
    running = 0;
    return 1;
}

#include "main.c"
