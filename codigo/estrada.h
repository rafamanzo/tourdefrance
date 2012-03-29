typedef struct et{
	char tipo;
	double dist;
	et* prox;
	et* ult;
} etapa;

unsigned int prox_sinc_temp;
unsigned int prox_sinc_dist;
unsigned short **estrada;

pthread_mutex_t temp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dist_mutex = PTHREAD_MUTEX_INITIALIZER;

void inic_estrada(int num_cic, int dist);
void insere(etapa* lst, char c, double k);
