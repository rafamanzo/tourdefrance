#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "input.h"
#include "ciclista.h"
#include <pthread.h>
#include "checkpoint.h"
#include "estrada.h"

int main(int argc, char *argv[]){
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
  for( i = 0; i < num_cic; i++)
    loop(biker[i]);

 return 0;
}
