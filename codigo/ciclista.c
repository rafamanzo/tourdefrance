#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include "checkpoint.h"
#include "estrada.h"
#include "ciclista.h"
#include "placar.h"

int avanca_tempo(int id){
  tempo[id]++;
  
  while(tempo[id] == prox_sinc_temp)
    if(conta_cic_tempo(prox_sinc_temp) == correndo){
      pthread_mutex_lock( &temp_mutex );

      if(tempo[id] == prox_sinc_temp){
        if(prox_sinc_temp%60 == 0)
          placar_min_a_min(num_cic);
        prox_sinc_temp++;
      }
      
      pthread_mutex_unlock( &temp_mutex );
    }else{
      sleep(0.01);
    }
    
  return 1;
}

int avanca_espaco(ciclista *c){
  int pos_atual, prox_pos;
  
  pos_atual = floor((*c).pos);

  switch(tipo_trecho[pos_atual]){
    case SUBIDA:
      (*c).pos += (*c).vp;
      break;
    case DESCIDA:
      (*c).pos += (*c).vd;
      break;
    case PLANO:
      (*c).pos += (*c).vp;
      break;
  }
  
  prox_pos = floor((*c).pos);
  
  if(prox_pos > pos_atual && prox_pos < max_dist){
    while(conta_cic_posicao(prox_pos, tempo[(*c).id]) >= largura){
      if(conta_cic_tempo(prox_sinc_temp) == correndo - 1){
        pthread_mutex_lock( &temp_mutex );
        prox_sinc_temp++;
        pthread_mutex_unlock( &temp_mutex );
      }
      sleep(0.01);
    }
    
    estrada[pos_atual][(*c).id] = 0;
    estrada[prox_pos][(*c).id] = 1;
    
    checa_passagem((*c).id, tempo[(*c).id], prox_pos, pontos);
  }

  return 1;
}

void * loop(void *c){
  ciclista *c_aux, cic;
  
  c_aux = (ciclista *) c;
  cic = *c_aux;
  
  while(cic.pos <= (max_dist - 1)){
    avanca_espaco(&cic);
    avanca_tempo(cic.id);
  }
  
  estrada[max_dist - 1][cic.id] = 0;
  correndo--;
  
  pthread_exit(0);
}

ciclista inicia_ciclista(char tipo, unsigned int id){
  ciclista cic;
 
  cic.id = id;
  cic.pos = 0.0;
  tempo[id] = 0;
  if( tipo == 'U' ){
    cic.vp = 50.0/3600.0;
	  cic.vs = 50.0/3600.0;
    cic.vd = 50.0/3600.0;
	}
  /* Aleatório */
  else{
    cic.vp = (rand()%60 + 20)/3600.0;
	  cic.vs = (rand()%60 + 20)/3600.0;
    cic.vd = (rand()%60 + 20)/3600.0;
	}
  return cic;
}

void imprime_ciclista(ciclista c){
    printf("%u\t %f\t %f\t %f \n",c.id,c.vp*3600.0,c.vs*3600.0,c.vd*3600.0);
}





