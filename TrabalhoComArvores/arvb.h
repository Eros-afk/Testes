typedef struct arvb ArvB;

/*Função que cria uma Árvore Binária Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que determina se um caractere pertence à Árvore.*/
int arvb_pertence(ArvB *a,int c);
/*Libera o espaço alocado para uma Árvore Binária.*/
void arvb_libera(ArvB *a);

/*Função para encontrar a altura de uma arvore*/
int arvb_altura(ArvB *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);

/////////FUNÇÕES NOVAS//////////////////////////////////////////////////

int eh_primo(int numero);
int contar_folhas_primos(ArvB* a);
int folhas_primos(ArvB* a);

int dois_filhos(ArvB* a);

int arvb_altura_igual(ArvB *a);
int nos_igual_altura(ArvB* a);

int iguais(ArvB* a, ArvB* b);