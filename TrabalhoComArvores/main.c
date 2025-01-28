#include "arvb.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Criando uma árvore binária de exemplo
    ArvB* arvore = arvb_cria_vazia();
    arvore = arvb_insere(arvore, 10);
    arvore = arvb_insere(arvore, 7);
    arvore = arvb_insere(arvore, 15);
    arvore = arvb_insere(arvore, 3);
    arvore = arvb_insere(arvore, 8);
    arvore = arvb_insere(arvore, 20);

    // Contando as folhas primas
    int resultado = folhas_primos(arvore);
    printf("A árvore tem %d folhas primas, kawaii~!\n", resultado);

    // Liberando a memória da árvore
    arvb_libera(arvore);

    return 0;
}