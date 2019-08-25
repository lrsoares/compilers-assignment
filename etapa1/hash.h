/*
 *		INF01147 - Compiladores - 2019/2 - Practical Assignment
 *      Professor Marcelo Johann
 *      Laura Rodrigues Soares - 00245174
 *      Rodrigo Daltoé Madruga - 00180669
 *
 *      This code was elaborated in class as a demonstration by prof. Johann.
 */

#include <stdio.h>

#define HASH_SIZE 997

typedef struct hash_node
{
	int type;
	char *text;
	struct hash_node *next;
} HASH_NODE;

void hashInit(void);
int hashAddress(char *text);
HASH_NODE *hashFind(char *text);
HASH_NODE *hashInsert(char *text);
void hashPrint(void);

//END
