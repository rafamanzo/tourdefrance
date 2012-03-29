#include "estrada.h"

void entrada(char *arquivo, int* m, int* n, char* c, double *d, char* etapa){
	FILE *f;
	char t;
	double k;
	int i, j;
	
	f = fopen("r",arquivo);
	fscanf(f,"%d",&m);/* m: a quantidade de ciclistas */
	fscanf(f,"%d",&n); /* n: a largura da pista em número de ciclistas*/
	fscanf(f,"%c",&c); /* velocidade uniforme ou arbitrária */
	fscanf(f,"%lf",&d); /*a distância da etapa em quilômetros*/

	etapa = malloc(d*sizeof(char));
	inic_estrada(m, d);

	for(i=0; i<=d;){
		fscanf(f,"%c",&t);
		if( t == EOF )
			break;

		fscanf(f,"%lf",&k);
		while(i<=k){
			etapa[i] = t;
			i++;
		}

		/* Sinaliza o fim de uma etapa na estrada */
		for(j=0; j < m; j++)
			estrada[j][k] = 2;
	}
}
