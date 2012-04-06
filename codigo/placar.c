#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <pthread.h>
#include "checkpoint.h"
#include "estrada.h"
#include "ciclista.h"
#include "placar.h"

void ordena_imprime(int *v){
	int i, aux, j;
	int *p;
  
  p = malloc(num_cic*sizeof(int));
  for(i=0; i < num_cic; i++)
		p[i] = i;

  for(i=0; i < num_cic; i++){
    for(j=0; j < num_cic-1; j++){
      if(v[p[j]] > v[p[j+1]]){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
      }
    }
  }
  for(j=1; j < num_cic; j++)
      printf("%dº) %d\n",j,p[num_cic-j]);
  free(p);
}

void placar_min_a_min(){
  int i;

  printf("\nCiclista km\n-----------\n");
  for(i=0; i < num_cic; i++)
    printf("%u\t %d\n", i, pos_ciclista(i));
}

void placar_checkpoint(unsigned int *v, int *pontos){
	int i, aux, j;
	int *p;
  
  p = malloc(num_cic*sizeof(int));
  for(i=0; i < num_cic; i++)
		p[i] = i;

  /* Bubble sort inverso com apenas 6 bolhas */
  for(i=0; i < 6; i++){
    for(j=0; j < num_cic-1; j++){
      if(v[p[j]] < v[p[j+1]]){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
      }
    }
  }

  if( num_cic < 6)
    aux = num_cic;
  else
    aux = 6;

  /* Imprime os 3 primeiros colocados e distribui as pontuações */
  for(j=1; j <= aux; j++){
    if( j < 4 )
      printf("%dº) %d\n",j,p[num_cic-j]);
    switch( j ){
      case 1:
        pontos[p[num_cic-j]] += 45;
        break;
      case 2:
        pontos[p[num_cic-j]] += 35;
        break;
      case 3:
        pontos[p[num_cic-j]] += 25;
        break;
      case 4:
        pontos[p[num_cic-j]] += 15;
        break;
      case 5:
        pontos[p[num_cic-j]] += 10;
        break;
      case 6:
        pontos[p[num_cic-j]] += 5;
        break;
    }
   }
  free(p);
}


void imprime_final(){
  checkpoint *aux = pontos;
  int *pontos_plano, *pontos_subida, *pontos_descida;
  int i;

	pontos_plano = malloc(num_cic*sizeof(int));
	pontos_subida = malloc(num_cic*sizeof(int));
	pontos_descida = malloc(num_cic*sizeof(int));

  for( i = 0; i < num_cic; i++)
    pontos_plano[i] = pontos_subida[i] = pontos_descida[i] = 0;

   while( aux != NULL){
    printf("\nCheckpoint -");
    if( (*aux).tipo == PLANO ){
      printf(" Trecho Plano - %u Km \n",(*aux).posicao*2);
  	  placar_checkpoint((*aux).tempos,pontos_plano);
    }
    else if( (*aux).tipo == SUBIDA ){
      printf(" Trecho de Subida - %u Km \n",(*aux).posicao);
   	  placar_checkpoint((*aux).tempos,pontos_subida);  
    }
    else{
      printf(" Trecho de Descida - %u Km \n",(*aux).posicao);
   	  placar_checkpoint((*aux).tempos,pontos_descida);  
    }
    aux = (*aux).prox;
  }

  printf("\nPlacar Trechos Planos\n");
  ordena_imprime(pontos_plano);

  printf("\nPlacar Trechos de Subida\n");
  ordena_imprime(pontos_subida);

  printf("\nPlacar Trechos de Descida\n");
  ordena_imprime(pontos_descida);
  
  free(pontos_plano);
  free(pontos_subida);
  free(pontos_descida);
}
