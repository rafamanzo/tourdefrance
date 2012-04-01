typedef struct pl{
	unsigned int id;
	double tempo;
} placar;

placar* inicia_placar(int);
void imprime_placar(placar*, int);
