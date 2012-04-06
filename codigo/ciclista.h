typedef struct cic{
  unsigned int id;
  double pos;
  double vp; /* Velocidade no plano em km/s */
  double vs; /* Velocidade na subida em km/s*/
  double vd; /* Velocidade na descida km/s*/
} ciclista;

ciclista *biker;

ciclista inicia_ciclista(char, unsigned int);
void * loop(void *c);
void imprime_ciclista(ciclista);
