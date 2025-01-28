typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Função que cria um nó em uma Árvore Binária.*/
ArvB* arv_cria_no(char c, ArvB *sae, ArvB *sad);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que imprime os elementos de uma Árvore Binária.*/
void arvb_imprime(ArvB *a);
/*Função que determina se um caractere pertence à Árvore.*/
int arvb_pertence(ArvB *a,char c);
/*Libera o espaço alocado para uma Árvore Binária.*/
void arvb_libera(ArvB *a);

int arvb_altura(ArvB *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);