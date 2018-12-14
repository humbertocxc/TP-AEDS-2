#include "funcao.h"

int main(int argc, char **argv){
  char ch, palavra[20];
  int i = 0, hash = 0, aux = 0, j, ct=0;

  FILE *IN;
  IN = fopen (argv[1],"r");
  if(IN == NULL){
    printf("Arquivo não foi aberto!\n");
    exit (1);
  }

  //zeramos as variáveis das structs
  for (i = 0; i < 256; i++){
    ht[i].repeticao = 0;
    ht[i].chave = 0;
  }

  fflush(stdout);

  //aqui todo o arquivo será rodado, separando por palavras, e criando uma heap em cada palavra
  while ((ch = getc(IN)) != EOF){
  	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
  	  palavra[ct] = ch;
  	  ct++;
  	}else{
    	palavra[ct] = '\0';	
      //if para aceitar apenas palavras de 2 letras ou mais
      if(strlen(palavra) > 1){
        //deixa todas as letras da palavra minúsculas
        for(i = 0; palavra[i]; i++) palavra[i] = tolower(palavra[i]);

        //chamando a função que cria a hash, e retorna uma variável do tipo hash
        hash = fHash(palavra, strlen(palavra));
        aux = hash;

        //se no lugar de inserção da palavra não houver nenhum índice de repetição, coloca ela no mesmo
        if(ht[hash].repeticao == 0){
          strcpy(ht[hash].palavra, palavra);
          ht[hash].repeticao ++;

        //se a palavra for igual, soma 1 na repetição
        }else if(strcmp(ht[hash].palavra,palavra) == 0){
          ht[hash].repeticao ++;

        //se a palavra for diferente, ele continua fazendo o mesmo até não encontrar um índice de repetição
        }else if (ht[hash].chave == 0){
          while (ht[hash].repeticao != 0){
            hash ++;
          }
          strcpy(ht[hash].palavra, palavra);
          ht[hash].repeticao ++;

        //somar +1 na chave do aux para ver se exise alguma colisão
          ht[aux].chave ++;
        }else if(ht[hash].chave != 0){

        //procurar alguma palavra igual no vetor
          for (i = 0;i < 256; i++){
            if (strcmp(ht[i].palavra,palavra) == 0){

              //quando for igual, soma 1 nas repetições e sai do loop
              ht[i].repeticao ++;
              break;
            }
          }

        //caso o valor seja o mesmo mas a palavra for diferente, ele procura uma nova posição
        }else{
          while (ht[hash].chave != 0){
            hash ++;
          }

          //quando encontrar uma posição vazia, adiciona a palavra e soma 1 nas repetições
          strcpy(ht[hash].palavra, palavra);
          ht[hash].chave ++;
        }
      }
      ct=0;
  	}
  }

  //Chama função ordena "funcoes.h"
  ordena();
  //Chama função imprime "funcoes.h"
	imprime();
  fclose (IN);
  return 0;
}
