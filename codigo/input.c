
void entrada(char *arquivo, int* m, int* n, char* c, double *d, etapa* lst){
	FILE *f;
	char t;
	double k;
	
	f = fopen("r",arquivo);
	fscanf(f,"%d",&m);/* m: a quantidade de ciclistas */
	fscanf(f,"%d",&n); /* n: a largura da pista em número de ciclistas*/
	fscanf(f,"%c",&c); /* velocidade uniforme ou arbitrária */
	fscanf(f,"%lf",&d); /*a distância da etapa em quilômetros*/

	while(1){
		fscanf(f,"%c",&t);
		if( t == EOF )
			break;
		fscanf(f,"%lf",&k);
		lst = insere(t,k);
	}
}
