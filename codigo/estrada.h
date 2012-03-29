#define PLANO 'P'
#define SUBIDA 'S'
#define DESCIDA 'D'

unsigned int prox_sinc_temp;
unsigned int prox_sinc_dist;
unsigned short **estrada;
char *tipo_trecho;

pthread_mutex_t temp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dist_mutex = PTHREAD_MUTEX_INITIALIZER;

void inic_estrada(int num_cic, int dist);
void insere(etapa* lst, char c, double k);
