#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//struct para geração da tabela hash
typedef struct{
  int chave;
  char palavra [20];
  int repeticao;
}tabelaHash;
tabelaHash ht[256], htaux[256];

unsigned int fHash(char* str, unsigned int len);

void separa_palavras(FILE *IN);

void teste_colisao();

void ordena();

void imprime();