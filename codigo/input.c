#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include "checkpoint.h"
#include "estrada.h"
#include "input.h"

void entrada(char *arquivo, char* c, int *d){
	FILE *f;
	char t;
	int i, k, fim_trecho;
  	
	if((f = fopen(arquivo,"r")) == NULL){
		printf("Erro ao abrir o arquivo %s.\n",arquivo);
		exit(-1);
	}
	fscanf(f, "%u", &num_cic);/* m: a quantidade de ciclistas */
	fscanf(f, "%hu", &largura); /* n: a largura da pista em número de ciclistas*/
	*c = 10;
	while(*c == 10){
	  fscanf(f, "%c", c); /* velocidade uniforme ou arbitrária */
	}
	fscanf(f, "%d", d); /*a distância da etapa em quilômetros*/
	
	tipo_trecho = malloc((*d)*sizeof(char));
	inic_estrada(*d);

	for(i=0; i<=(*d); i++){
	  t = 10;
	  while(t == 10)
		  fscanf(f,"%c",&t);
		
		if( t == EOF )
			break;

		fscanf(f,"%d",&k);
		switch(t){
		  case SUBIDA:
        novo_checkpoint(num_cic, SUBIDA, k, &pontos);
        break;
      case DESCIDA:
        novo_checkpoint(num_cic, DESCIDA, k, &pontos);
        break;
      case PLANO:
        novo_checkpoint(num_cic, PLANO, k/2, &pontos);
        break;
		}
		
		fim_trecho = (i+k);
		while(i<fim_trecho){
			tipo_trecho[i] = (char) t;
			i++;
		}
		tipo_trecho[i] = (char) t;
	}
}
