typedef struct pl{
	unsigned int id;
	double tempo;
	double dist;
} placar;

placar* inicia_placar(int);
void imprime_placar(placar*, int);
void placar_min_a_min(int);
