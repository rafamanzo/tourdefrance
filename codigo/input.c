#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include "checkpoint.h"
#include "estrada.h"
#include "input.h"

void entrada(char *arquivo, int* m, int* n, char* c, int *d, char** tipo_trecho){
	FILE *f;
	char t;
	int i, k;
  	
	f = fopen("r",arquivo);
	fscanf(f, "%u", &num_cic);/* m: a quantidade de ciclistas */
	fscanf(f, "%hu", &largura); /* n: a largura da pista em número de ciclistas*/
	fscanf(f, "%c", c); /* velocidade uniforme ou arbitrária */
	fscanf(f, "%d", d); /*a distância da etapa em quilômetros*/

	tipo_trecho = malloc((*d)*sizeof(char));
	inic_estrada(num_cic, *d);

	for(i=0; i<=(*d); i++){
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
		while(i<=k){
			tipo_trecho[i] = (char) t;
			i++;
		}
	}
}
