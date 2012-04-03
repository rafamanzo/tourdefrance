typedef struct pt{
	unsigned int plano;
	unsigned int subida;
	unsigned int decida;
} ponto;

placar* inicia_placar(int);
void imprime_placar(placar*, int);
void placar_min_a_min(int);
