#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcao.h"

unsigned int fHash(char* str, unsigned int len){
  const unsigned int resp = 2;
  unsigned int hash = 0;
  unsigned int i = 0;
  for (int i = 0; i < len; i++){
    hash *= resp;
    hash ^= (*str);
  }
  return hash%256;
}

void separa_palavras(FILE *IN){
  char ch, palavra[20];
  int i = 0, hash = 0, ct=0;
  //aqui todo o arquivo será rodado, criando strings de letras maiusculas e minúsculas
  while ((ch = getc(IN)) != EOF){
  	if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
  	  palavra[ct] = ch;
  	  ct++;
  	}else{
    	palavra[ct] = '\0';	
      //testa tamanho pois a ideia é aceitar apenas palavras de 2 letras ou mais
      if(strlen(palavra) > 1){
        //deixa todas as letras da palavra minúsculas
        for(i = 0; palavra[i]; i++) palavra[i] = tolower(palavra[i]);
        //chamando a função que retorna uma posição na tabela hash
        hash = fHash(palavra, strlen(palavra));
        //usa a posição na tabela recebida para testar se há colisões, e se há palavras repetidas
        teste_colisao(palavra, hash);
      }
      ct=0;
  	}
  }
}

void teste_colisao(char palavra[], int hash){
  int aux = hash, i;
  //testa se a posição na tabela está vazia, para introduzir a palavra
  if(ht[hash].repeticao == 0){
    strcpy(ht[hash].palavra, palavra);
    ht[hash].repeticao ++;
  //se houver colisão e a palavra for igual, soma 1 no nmr de repetições
  }else if(strcmp(ht[hash].palavra,palavra) == 0){
    ht[hash].repeticao ++;
  //caso a chave seja 0, procura uma posição vazia na tabela e coloca a palavra e depois soma 1 na posição onde a chave era 0
  }else if (ht[hash].chave == 0){
    while (ht[hash].repeticao != 0){
      hash ++;
    }
    strcpy(ht[hash].palavra, palavra);
    ht[hash].repeticao ++;
    ht[aux].chave ++;
  //caso a chave seja diferente de 0, ele procura uma posição com a palavra igual
  }else if(ht[hash].chave != 0){
    for (i = 0;i < 256; i++){
      if (strcmp(ht[i].palavra,palavra) == 0){
        ht[i].repeticao ++;
        break;
      }
    }
  }
}

void ordena(){
  //ordena por quantidade
  for (int i = 0; i < 255; i++){
    int max = i;
    for (int j = (i+1); j < 256; j++){
      if(ht[j].repeticao > ht[max].repeticao)
        max = j;
    }
    if (i != max){
      strcpy(htaux[i].palavra, ht[i].palavra);
      int flag = ht[i].repeticao;
      strcpy(ht[i].palavra, ht[max].palavra);
      ht[i].repeticao = ht[max].repeticao;
      strcpy(ht[max].palavra,htaux[i].palavra);
      ht[max].repeticao = flag;
    }
  }
    //ordena por ordem alfabetica
    for (int i = 0; i < 256; i++){
      for (int j = 0; j < 256; j++){
      //Seleciona apenas as de mesma quantidade
      if (ht[i].repeticao == ht[j].repeticao){
        //A função strcoll compara letra por letra em uma string, até que uma delas seja menor
        if(strcoll(ht[i].palavra,ht[j].palavra) < 0){
          strcpy(htaux[j].palavra, ht[j].palavra);
          strcpy(ht[j].palavra, ht[i].palavra);
          strcpy(ht[i].palavra,htaux[j].palavra);
        }
      }
    }
  }
}

void imprime(){
  //imprime todas as palavras com mais de 2 repetições
  for (int i = 0; i < 256; i++){
    if (ht[i].repeticao >= 2){
      printf ("%d ", ht[i].repeticao);
      printf ("%s\n", ht[i].palavra);
    }
  }
}
