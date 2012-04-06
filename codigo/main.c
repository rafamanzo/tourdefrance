#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "input.h"
#include "ciclista.h"
#include <pthread.h>
#include "checkpoint.h"
#include "estrada.h"
#include "placar.h"

int main(int argc, char *argv[]){
  pthread_t *corredores;
  int i, d;
  char c;

  srand(time(NULL));

  entrada(argv[1], &c, &d);
  
  /* Inicialização*/
  biker = malloc(num_cic*sizeof(ciclista));
  printf("Tour de France\n");
  printf("Nome\t Vel. Plano\t Vel. Subida\t Vel. Descida\n");
  for( i = 0; i < num_cic; i++){
    biker[i] = inicia_ciclista(c, i);
    imprime_ciclista(biker[i]);
  }

  /* "Largada" */
  corredores = malloc(num_cic*sizeof(pthread_t));
  correndo = num_cic;
  for( i = 0; i < num_cic; i++)
    pthread_create( &(corredores[i]), NULL, loop, (void *) &(biker[i]));
  for( i = 0; i < num_cic; i++)
    pthread_join( corredores[i], NULL );

  /* Chegada */
  imprime_final();

 return 0;
}
