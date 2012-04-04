#define PLANO 'P'
#define SUBIDA 'S'
#define DESCIDA 'D'

unsigned int prox_sinc_temp;
unsigned short **estrada;
char *tipo_trecho;
unsigned int *tempo;
unsigned short largura;
unsigned int num_cic;
unsigned int max_dist;
checkpoint *pontos;

pthread_mutex_t temp_mutex;

void inic_estrada(int dist);
void set_prox_sinc_temp(unsigned int temp);
int conta_cic_tempo(unsigned int tmp);
int conta_cic_posicao(unsigned int pos);
