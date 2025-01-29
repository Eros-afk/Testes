#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb{
    int info;
    ArvB *esq;
    ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
    return NULL;
}

ArvB* arvb_cria_no(int c, ArvB *sae, ArvB *sad){
    ArvB* a = (ArvB*)malloc(sizeof(ArvB));
    a->info = c;
    a->esq = sae;
    a->dir = sad;
    return a;
}

int arvb_vazia(ArvB *a){
    return a==NULL;
}

int arvb_pertence(ArvB *a,int c){
    if(arvb_vazia(a))
        return 0;
    else
        return a->info ==c || arvb_pertence(a->esq,c)
    || arvb_pertence(a->dir,c);
}

void arvb_libera(ArvB *a){
    if(!arvb_vazia(a)){
        arvb_libera(a->esq);
        arvb_libera(a->dir);
        free(a);
    }
}


int arvb_altura(ArvB *a){
    if(arvb_vazia(a))
        return -1;
    else{
        int hSAE = arvb_altura(a->esq);
        int hSAD = arvb_altura(a->dir);
        if(hSAE > hSAD)
            return 1+hSAE;
        else
        return 1+hSAD;
 }
}


ArvB* arvb_busca(ArvB *a, int c){
    if(arvb_vazia(a))
        return NULL;
    else if(a->info < c)
        return arvb_busca(a->dir,c);
    else if(a->info > c)
        return arvb_busca(a->esq,c);
    else //(a->info == c)
        return a;
}

void arvb_imprime(ArvB *a){
    if(!arvb_vazia(a)){
        arvb_imprime(a->esq);
        printf("%d ",a->info);
        arvb_imprime(a->dir);
    }
}

ArvB* arvb_insere(ArvB *a, int c){
    if(arvb_vazia(a)){
        a = (ArvB*)malloc(sizeof(ArvB));
        a->info = c;
        a->esq = NULL;
        a->dir = NULL;
    }else if(a->info > c)
        a->esq = arvb_insere(a->esq,c);
        else if (a->info < c)
        a->dir = arvb_insere(a->dir,c);
    else
        printf("\nElemento Ja Pertence a Arvore");
    return a;
}

ArvB* arvb_remove(ArvB *a, int c){
if(!arvb_vazia(a)){
    if(a->info > c)
        a->esq = arvb_remove(a->esq,c);
    else if (a->info < c)
        a->dir = arvb_remove(a->dir,c);
    else{
        ArvB* t;
    if (a->esq == NULL){
        t = a; a = a->dir;
        free(t);
    }else if (a->dir == NULL){
        t = a; a = a->esq;
        free(t);
    }else{
        t = a->esq;
        while(t->dir!=NULL)
        t = t->dir;
        a->info = t->info; t->info = c;
        a->esq = arvb_remove(a->esq,c);
            }
        }
    }
    return a;
}

/////////////////FUNÇÕES NOVAS////////////////////////////////////////////////////////////////////////////

// Função para verificar se um número é primo
int eh_primo(int numero) {
    if (numero < 2) return 0; // Números menores que 2 não são primos
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return 0; // Se for divisível por algum número, não é primo
    }
    return 1; // É primo
}

// Função recursiva para contar folhas primos
int contar_folhas_primos(ArvB* a) {
    if (arvb_vazia(a)) return 0; // Se a árvore estiver vazia, retorna 0

    // Se for uma folha e o valor for primo, retorna 1
    if (a->esq == NULL && a->dir == NULL && eh_primo(a->info)) {
        return 1;
    }

    // Soma as folhas primos da subárvore esquerda e direita
    return contar_folhas_primos(a->esq) + contar_folhas_primos(a->dir);
}

// Função principal que inicia a contagem
int folhas_primos(ArvB* a) {
    if (arvb_vazia(a)) return 0; // Árvore vazia
    return contar_folhas_primos(a);
}


int dois_filhos(ArvB* a) {
    if (arvb_vazia(a))
        return 0;
    if (a->esq != NULL && a->dir != NULL) //Verifica se o nó atual tem dois filhos
        return 1 + dois_filhos(a->esq) + dois_filhos(a->dir);
    else
        return dois_filhos(a->esq) + dois_filhos(a->dir);
}


int arvb_altura_igual(ArvB *a){
    if(arvb_vazia(a))
        return 0; //Arvore vazia não tem subárvore
    else{
        int hSAE = arvb_altura(a->esq); //Altura subárvore esq
        int hSAD = arvb_altura(a->dir); //Altura subárvore dir
        //Verifica se as alturas são iguais e se ambas as subárvores não são vazias
        if(hSAE == hSAD && !arvb_vazia(a->esq) && !arvb_vazia(a->dir))
            return 1; //Nó atual valido
        else
            return 0; //Nó atual !valido
 }
}

int nos_igual_altura(ArvB* a){
    if (arvb_vazia(a))
        return 0; //Árvore vazia não tem nós
    //Verifica se o atual nó atende à condição
    int count = arvb_altura_igual(a);
    
    //Soma os nós que atendem à condição nas subárvores esq e dir
    return count + nos_igual_altura(a->esq) + nos_igual_altura(a->dir);
}


int iguais(ArvB* a, ArvB* b){
    //Caso base: ambas as árvores são vazias
    if(arvb_vazia(a) && arvb_vazia(b))
        return 1; //Ávores vazias iguais
    //Caso base: uma das árvores é vazia e outra não
    if(arvb_vazia(a) || arvb_vazia(b))
        return 0; //Árvore diferentes
    //Verifica se os valores valores dos nós atuais são iguais
    if (a->info != b->info)
        return 0; //Valores diferentes
    //Verifica recursivamnete as subárvores esq e dir
    return iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
}