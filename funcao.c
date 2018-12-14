#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcao.h"

/*função que cria a hash recebendo a palavra e o tamanho, e retorna a posição na tabela, que é equivalente
ao resto da divisão do valor inteiro da palavra por 256(tamanho de um char)*/
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
