typedef struct chkpt{
  char tipo;
  unsigned int *tempos;
  unsigned int posicao;
  struct chkpt *prox;
} checkpoint;


