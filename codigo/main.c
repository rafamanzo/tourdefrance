#include <stlib.h>
#include <time.h>
#include "input.h"
#include "ciclista.h"

int main(int argc, char *argv[])
  char *arquivo, *tipo_trecho;
  int m, n;
  char c;
  double d;
  ciclista* biker;

	srand(time(NULL));

  entrada(argv[1], &m, &n, &c, &d, &tipo_trecho);
 
  /* Inicialização*/
  biker = malloc(m*sizeof(ciclista));
  printf("Tour de France\n");
  printf("Nome\t Vel. Plano\t Vel. Subida\t Vel. Descida\n");
  for( i = 0; i < m; i++){
    biker[i] = inicia_ciclista(c, i);
    imprime_ciclista(biker[i]);
  }
  /* "Largada" */
  for( i = 0; i < m; i++)
    loop(biker[i]);
    



 
 return 0;
}
