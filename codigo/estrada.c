#include<stdlib.h>
#include<pthread.h>
#include "estrada.h"

void set_prox_sinc_temp(unsigned int temp){
  pthread_mutex_lock( &temp_mutex );
  prox_sinc_dist = temp;
  pthread_mutex_unlock( &temp_mutex );
}

void inic_estrada(int num_cic, int dist){
  int i, j;

  tempo = malloc(num_cic*sizeof(unsigned int));

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
