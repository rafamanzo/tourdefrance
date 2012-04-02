#include<stdlib.h>
#include<math.h>
#include<pthread.h>
#include<unistd.h>
#include "estrada.h"
#include "ciclista.h"

int avanca_tempo(int id){
  tempo[id]++;
  
  while(tempo[id] == prox_sinc_temp)
    if(conta_cic_tempo(prox_sinc_temp) == num_cic){
      pthread_mutex_lock( &temp_mutex );

      if(tempo[id] == prox_sinc_temp){
        printf("Imprime o placar aqui");
        prox_sinc_temp++;
      }
      
      pthread_mutex_unlock( &temp_mutex );
    }else{
      sleep(1);
    }
    
  return 1;
}

int avanca_espaco(ciclista c){
  int pos_atual, prox_pos;
  
  pos_atual = floor(c.dist);

  switch(tipo_trecho[pos_atual]){
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
  
  if(prox_pos > pos_atual){
    while(conta_cic_posicao(prox_pos) >= largura)
      sleep(1);
    
    estrada[pos_atual][c.id] = 0;
    estrada[prox_pos][c.id] = 1;
  }

}

void loop(ciclista c){  
  while(pos_atual < max_dist){
    avanca_espaco(c);
    avanca_tempo(c.id);
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
  /* Aleatório */
  else{
    *cic.vp = rand()%60 + 20;
	  *cic.vs = rand()%60 + 20;
    *cic.vd = rand()%60 + 20;
	}
  return cic;
}

void imprime_ciclista(ciclista c){
    printf("%u\t %lf\t %lf\t %lf \n",c.id,c.vp,c.vs,c.vd);
}





