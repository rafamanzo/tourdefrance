#include "placar.h"

placar* inicia_placar(int cics){
	placar* p;
	
  *p = malloc(cics*sizeof(placar));
  
  for(i=0; i < cics; i++){
    *p[i].id = 0;
    *p[i].tempo = 0.0;
  }
  return *p;
}

void insertion_sort(placar *p, int cics){               
  int i, j;
  placar aux;
 
  for(i=1; i < cics; i++){
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

void imprime_placar(placar *p, int cics){
  int i;

  insertion_sort(&p,cics);
  printf("Placar\n");
  for(i=0; i < cics; i++)
    printf("%3d %.6lf\n",p[i].id, p[i].tempo);
}
  




