#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

// Inicializa a pilha (topo = -1 indica pilha vazia)
void inicializarPilha(Pilha *p, char letra) {
    p->topo = -1;
    p->letra = letra;
}

// Verifica se a pilha está vazia
bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
bool pilhaCheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

// Insere um elemento no topo da pilha
bool push(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia! Não é possível inserir %d\n", valor);
        return false;
    }

    p->topo++;
    p->items[p->topo] = valor;
    printf("Elemento %d inserido com sucesso!\n", valor);
    return true;
}

// Remove e retorna o elemento do topo
bool pop(Pilha *p, int *valor) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia! Não é possível remover\n");
        return false;
    }

    *valor = p->items[p->topo];
    p->topo--;
    return true;
}

// Consulta o elemento sem remover
bool top(Pilha *p, int *valor) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return false;
    }

    *valor = p->items[p->topo];
    return true;
}

// Retorna o número de elementos na pilha
int tamanho(Pilha *p) {
    return p->topo + 1;
}

// Imprime todos os elementos da pilha
void imprimirPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return;
    }
    
    printf("\n=== ESTADO DA PILHA===\n");
    printf("Tamanho: %d elementos\n", tamanho(p));
    printf("Topo -> ");

    for (int i = p->topo; i >= 0; i--) {
        printf("[%d] ", p->items[i]);
    }

    printf("<- Base\n");
    printf("===================\n\n");
}

// Limpa todos os elementos da pilha
void limparPilha(Pilha *p) {
    p->topo = -1;
    printf("Pilha limpa com sucesso!\n");
}