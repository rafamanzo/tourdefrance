#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include "estrada.h"
#include "ciclista.h"

void loop(ciclista c){
  int pos_atual, prox_pos;

  pos_atual = floor(c.dist);
  
  while(pos_atual < max_dist){
    switch(tipo_trecho[pos_atual] == PLANO){
      case SUBIDA:
        c.dist += c.vp;
        break;
      case DESCIDA:
        c.dist += c.vd;
        break;
      case PLANO:
        c.dist += c.vp;
        break;
    }
    
    prox_pos = floor(c.dist);
    tempo[cic.id]++;
    
    if(prox_pos > pos_atual){
      estrada[pos_atual][c.id] = 0;
      estrada[prox_pos][c.id] = 1;
    }
  }
  
  pthread_exit();
}

ciclista* inicia_ciclista(char tipo, unsigned int id){
  ciclista* cic;
 
  cic = malloc(sizeof(ciclista)); 
  *cic.id = id;
  *cic.pos = 0.0;
  if( tipo == "U" ){
    *cic.vp = 50.0;
	  *cic.vs = 50.0;
    *cic.vd = 50.0;
	}
  else if( tipo == "A" ){
    *cic.vp = rand()%60 + 20;
	  *cic.vs = rand()%60 + 20;
    *cic.vd = rand()%60 + 20;
	}
  return cic;
}
