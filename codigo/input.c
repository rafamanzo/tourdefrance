#include<stdlib.h>
#include<stdio.h>
#include "checkpoint.h"
#include "estrada.h"

void entrada(char *arquivo, int* m, int* n, char* c, double *d, char* tipo_trecho){
	FILE *f;
	char t;
	double k;
	int i, j;
  etapa *nova;
  	
	f = fopen("r",arquivo);
	fscanf(f,"%d",&num_cic);/* m: a quantidade de ciclistas */
	fscanf(f,"%d",&largura); /* n: a largura da pista em número de ciclistas*/
	fscanf(f,"%c",&c); /* velocidade uniforme ou arbitrária */
	fscanf(f,"%lf",&d); /*a distância da etapa em quilômetros*/

	tipo_trecho = malloc(d*sizeof(char));
	inic_estrada(m, d);

	for(i=0; i<=d;){
		fscanf(f,"%c",&t);
		if( t == EOF )
			break;

		fscanf(f,"%lf",&k);
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
			tipo_trecho[i] = t;
			i++;
		}

		/* Sinaliza o fim de uma etapa na estrada */
		for(j=0; j < m; j++)
			estrada[j][k] = 2;
	}
}
