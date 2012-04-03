#include "placar.h"
#include <math.h>

placar* inicia_placar(int cics){
	placar* p;
	
  *p = malloc(cics*sizeof(placar));
  
  for(i=0; i < cics; i++){
    *p[i].id = 0;
    *p[i].tempo = 0.0;
  }
  return *p;
}


void insertion_sort(placar *p, int ncics){               
  int i, j;
  placar aux;
 
  for(i=1; i < ncics; i++){
    j = i;
    while(p[j].tempo < p[j-1].tempo){
      aux = p[j];
      p[j] = p[j-1];
      p[j-1] = aux;
      j--;    
      if(j == 0)
        break;
    }               
  }
}

void imprime_placar(placar *p, int ncics){
  int i;

  insertion_sort(&p,cics);
  printf("Placar\n");
  for(i=0; i < ncics; i++)
    printf("%3d %.6lf\n",p[i].id, p[i].tempo);
}



void placar_min_a_min(int ncics){
  printf("Ciclista\t km da etapa\n")
  for(i=0; i < ncics; i++)
    print("%u %d\n",biker[i].id, floor(biker[i].dist));
}

void placar_checkpoint(int *v, int ncics){
	int i, aux, j;
	int *p;
  
  p = malloc(ncics*sizeof(int));
  for(i=0; i < ncics; i++)
		p[i] = i;

  /* Bubble sort inverso com apenas 3 bolhas */
  for(i=0; i < 3; i++){
    for(j=0; j < ncics-1; j++){
      if(v[p[j]] < v[p[j+1]]){
				aux = p[j];
				p[j] = p[j+1];
				p[j+1] = aux;
      }
    }
  }
  for(j=1; j < 4; j++)
    printf("%dº) %d\n",j,v[p[ncics-j]]);
}
