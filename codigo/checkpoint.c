#include <stdlib.h>
#include "etapa.h"

void novo_checkpoint(int num_cic, char tipo, unsigned int posicao, checkpoint **pontos){
  checkpoint *novo, *atual;
  
  novo = malloc(sizeof(checkpoint));
  *novo.tempos = malloc(num_cic*sizeof(unsigned int));
  *novo.tipo = tipo;
  *novo.posicao = posicao;
  *novo.prox = NULL;
  
  if(*pontos == NULL){
    *pontos = novo;
  }else{
    atual = *pontos;
    
    while(atual.prox != NULL)
      atual = *atual.prox;
    
    atual.prox = novo;
  }
}

void checa_passagem(int id_cic, unsigned int tempo_cic, unsigned int posicao, checkpoint *pontos){
  checkpoint *atual;
  
  atual = pontos;
  
  while(atual != NULL){
    if(*atual.posicao == posicao)
      *atual.tempos[id_cic] = tempo_cic;
    atual = *atual.prox;  
  }
}
