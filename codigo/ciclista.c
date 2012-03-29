#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include "estrada.h"
#include "ciclista.h"

void loop(ciclista c){
  while(floor(c.dist) < max_dist){
    
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
