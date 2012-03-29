typedef struct cic{
	unsigned int id;
	double pos;
	double vp; /* Velocidade no plano em km/s */
	double vs; /* Velocidade na subida em km/s*/
	double vd; /* Velocidade na descida km/s*/
} ciclista;

ciclista* inicia_ciclista(char, unsigned int);

