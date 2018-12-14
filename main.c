#include "funcao.h"

int main(int argc, char **argv){
  FILE *IN;
  IN = fopen (argv[1],"r");
  if(IN == NULL){
    printf("Arquivo não foi aberto!\n");
    exit (1);
  }
  //zera as variáveis das structs
  for (int i = 0; i < 256; i++){
    ht[i].repeticao = 0;
    ht[i].chave = 0;
  }
  fflush(stdout);
  separa_palavras(IN);
  ordena();
	imprime();
  fclose (IN);
  return 0;
}
