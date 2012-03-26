
void insere(etapa* lst, char c, double k){
	etapa* new;
	new = malloc(sizeof(etapa));	
	new.tipo = c;
	new.dist = k;
	new.prox = NULL;
	new.ult = NULL;	

	if( lst->ult == NULL)
		lst->ult = new;
	else{
		lst->ult->prox = new;
		lst->ult = lst->ult->prox;
	}
}
