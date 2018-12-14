#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//LIMITADOR servirá para indicar o início e o fim de cada palavra
#define LIMITADOR "!? .,-\n"

//struct para geração da tabela hash
typedef struct{
  int chave;
  char palavra [20];
  int repeticao;
}tabelaHash;
tabelaHash ht [256],htaux[256];

unsigned int fHash(char* str, unsigned int len);

void ordena();

void imprime();
