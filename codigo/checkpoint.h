typedef struct chkpt{
  char tipo;
  unsigned int *tempos;
  unsigned int posicao;
  struct chkpt *prox;
} checkpoint;

void novo_checkpoint(int num_cic, char tipo, unsigned int posicao, checkpoint **pontos);
void checa_passagem(int id_cic, unsigned int tempo_cic, unsigned int posicao, checkpoint *pontos);
