#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "input.h"
#include "ciclista.h"
#include <pthread.h>
#include "checkpoint.h"
#include "estrada.h"

int main(int argc, char *argv[]){
  pthread_t *corredores;
  char *tipo_trecho;
  int i, d;
  char c;

	srand(time(NULL));

  entrada(argv[1], &c, &d, &tipo_trecho);
 
  /* Inicialização*/
  biker = malloc(num_cic*sizeof(ciclista));
  printf("Tour de France\n");
  printf("Nome\t Vel. Plano\t Vel. Subida\t Vel. Descida\n");
  for( i = 0; i < num_cic; i++){
    biker[i] = inicia_ciclista(c, i);
    imprime_ciclista(biker[i]);
  }
  printf("LARGADA\n");
  /* "Largada" */
  inic_estrada(d);
  corredores = malloc(num_cic*sizeof(pthread_t));
  for( i = 0; i < num_cic; i++)
    pthread_create( &(corredores[i]), NULL, loop, (void *) &(biker[i]));
  for( i = 0; i < num_cic; i++)
    pthread_join( corredores[i], NULL );

 return 0;
}
