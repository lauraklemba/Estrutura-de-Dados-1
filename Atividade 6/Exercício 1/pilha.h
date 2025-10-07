#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX_SIZE 100

// Estrutura da pilha
typedef struct {
    int items[MAX_SIZE];
    int topo;
    char letra;
} Pilha;

// Protótipos das funções
void inicializarPilha(Pilha *p, char letra);
bool pilhaVazia(Pilha *p);
bool pilhaCheia(Pilha *p);
bool push(Pilha *p, int valor);
bool pop(Pilha *p, int *valor);
bool top(Pilha *p, int *valor);
int tamanho(Pilha *p);
void imprimirPilha(Pilha *p);
void limparPilha(Pilha *p);

#endif