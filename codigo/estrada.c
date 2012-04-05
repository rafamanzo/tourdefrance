#include<stdlib.h>
#include<pthread.h>
#include "checkpoint.h"
#include "estrada.h"

int conta_cic_tempo(unsigned int tmp){
  int i, contagem;
  
  contagem = 0;
  
  for(i = 0; i < num_cic; i++)
    if(tempo[i] == tmp)
      contagem++;
      
  return contagem;    
}

int conta_cic_posicao(unsigned int pos){
  int i, contagem;
  
  contagem = 0;
  
  for(i = 0; i < num_cic; i++)
    if(estrada[pos][i] == 1)
      contagem++;
      
  return contagem;
}

void inic_estrada(int dist){
  int i, j;

  tempo = malloc(num_cic*sizeof(unsigned int));

  pthread_mutex_init(&temp_mutex, NULL);
  prox_sinc_temp = 0;
  max_dist = dist;

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
