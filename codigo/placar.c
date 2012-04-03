#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <pthread.h>
#include "checkpoint.h"
#include "estrada.h"
#include "ciclista.h"
#include "placar.h"

void ordena_imprime(int *v, int ncics){
	int i, aux, j;
	int *p;
  
  p = malloc(ncics*sizeof(int));
  for(i=0; i < ncics; i++)
		p[i] = i;

  for(i=0; i < ncics; i++){
    for(j=0; j < ncics-1; j++){
      if(v[p[j]] > v[p[j+1]]){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
      }
    }
  }
  for(j=1; j < ncics; j++)
      printf("%dº) %d\n",j,v[p[ncics-j]]);
}

void placar_min_a_min(int ncics){
  int i;

  printf("Ciclista\t km da etapa\n");
  for(i=0; i < ncics; i++)
    printf("%u %d\n", biker[i].id, (int) floor(biker[i].pos));
}

void placar_checkpoint(unsigned int *v, int *pontos, int ncics){
	int i, aux, j;
	int *p;
  
  p = malloc(ncics*sizeof(int));
  for(i=0; i < ncics; i++)
		p[i] = i;

  /* Bubble sort inverso com apenas 6 bolhas */
  for(i=0; i < 6; i++){
    for(j=0; j < ncics-1; j++){
      if(v[p[j]] < v[p[j+1]]){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
      }
    }
  }
  /* Imprime os 3 primeiros colocados e distribui as pontuações */
  for(j=1; j < 7; j++){
    if( j < 4 )
      printf("%dº) %d\n",j,v[p[ncics-j]]);
    switch( j ){
      case 1:
        pontos[p[ncics-j]] += 45;
        break;
      case 2:
        pontos[p[ncics-j]] += 35;
        break;
      case 3:
        pontos[p[ncics-j]] += 25;
        break;
      case 4:
        pontos[p[ncics-j]] += 15;
        break;
      case 5:
        pontos[p[ncics-j]] += 10;
        break;
      case 6:
        pontos[p[ncics-j]] += 5;
        break;
    }
   }
  free(p);
}


void imprime_final(checkpoint* c, int ncics){
  checkpoint *aux = c;
  int *pontos_plano, *pontos_subida, *pontos_descida;
  int i;

	pontos_plano = malloc(ncics*sizeof(int));
	pontos_subida = malloc(ncics*sizeof(int));
	pontos_descida = malloc(ncics*sizeof(int));

  for( i = 0; i < ncics; i++)
    pontos_plano[i] = pontos_subida[i] = pontos_descida[i] = 0;

   while( aux != NULL){
    printf("\nCheckpoint -");
    if( (*aux).tipo == PLANO ){
      printf(" Trecho Plano - %u Km \n",(*aux).posicao*2);
  	  placar_checkpoint((*aux).tempos,pontos_plano, ncics);
    }
    else if( (*aux).tipo == SUBIDA ){
      printf(" Trecho de Subida - %u Km \n",(*aux).posicao);
   	  placar_checkpoint((*aux).tempos,pontos_subida, ncics);  
    }
    else{
      printf(" Trecho de Descida - %u Km \n",(*aux).posicao);
   	  placar_checkpoint((*aux).tempos,pontos_descida, ncics);  
    }
    aux = (*aux).prox;
  }

  printf("Placar Trechos Planos\n");
  ordena_imprime(pontos_plano,ncics);

  printf("\nPlacar Trechos de Subida\n");
  ordena_imprime(pontos_subida,ncics);

  printf("\nPlacar Trechos de Descida\n");
  ordena_imprime(pontos_descida,ncics);
  
  free(pontos_plano);
  free(pontos_subida);
  free(pontos_descida);
}
