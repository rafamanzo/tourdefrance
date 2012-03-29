#include<stdlib.h>
#include "estrada.h"

void inic_estrada(int num_cic, int dist){
  int i, j;

  prox_sinc_temp = prox_sinc_dist = 0;

  estrada = malloc(dist*sizeof(short *));
  for(i = 0; i < dist; i++)
    estrada[i] = malloc(num_cic*sizeof(short));
    
  for(i = 0; i < dist; i++)
    for(j = 0; j < num_cic; j++)
      if( i == 0 )
        estrada[i][j] = 1;
      else
        estrada[i][j] = 0;
}

void insere(etapa* lst, char c, double k){
	etapa* new;
	new = malloc(sizeof(etapa));	
	new.type = c;
	new.dist = k;
	new.prox = NULL;
	new.ult = NULL;	

	if( lst->ult == NULL)
		lst->ult = new;
	else{
		lst->ult->prox = new;
		lst->ult = lst->ult->prox;
	}
}
