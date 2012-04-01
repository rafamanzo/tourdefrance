#include<stdlib.h>
#include<pthread.h>
#include "estrada.h"

int conta_cic_tempo(unsigned int tmp){
  int i, contagem;
  
  contagem = 0;
  
  for(i = 0; i < num_cic)
    if(tempo[i] == tmp)
      contagem++;
      
  return contagem;    
}

void inic_estrada(int num_cic, int dist){
  int i, j;

  tempo = malloc(num_cic*sizeof(unsigned int));

  prox_sinc_temp = 0;

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
