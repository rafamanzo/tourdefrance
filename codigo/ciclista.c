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
    if(conta_cic_tempo(prox_sinc_temp) == num_cic){
      pthread_mutex_lock( &temp_mutex );

      if(tempo[id] == prox_sinc_temp){
        placar_min_a_min(num_cic);
        prox_sinc_temp++;
      }
      
      pthread_mutex_unlock( &temp_mutex );
    }else{
      sleep(1);
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
  
  if(prox_pos > pos_atual){
    while(conta_cic_posicao(prox_pos) >= largura)
      sleep(1);
    
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
  
  while(cic.pos < max_dist){
    avanca_espaco(&cic);
    avanca_tempo(cic.id);
  }
  
  pthread_exit(0);
}

ciclista inicia_ciclista(char tipo, unsigned int id){
  ciclista cic;
 
  cic.id = id;
  cic.pos = 0.0;
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





