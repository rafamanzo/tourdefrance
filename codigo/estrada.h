#define PLANO 'P'
#define SUBIDA 'S'
#define DESCIDA 'D'

unsigned int prox_sinc_temp;
unsigned short **estrada;
char *tipo_trecho;
unsigned int *tempo;
unsigned short largura;

pthread_mutex_t temp_mutex = PTHREAD_MUTEX_INITIALIZER;

void inic_estrada(int num_cic, int dist);
void set_prox_sinc_temp(unsigned int temp);
