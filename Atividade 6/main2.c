#include <stdio.h>
#include "pilha.h"

// Função recursiva da Torre de Hanói
void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar) {
    if (n == 1) {
        int disco;
        if(pop(origem,&disco)) {
           push(destino, disco);
           printf("Mover disco %d de %c -> %c\n", disco, origem->letra, destino->letra);
        return;
    }
}
    // Move n-1 discos da origem para a auxiliar
    torreDeHanoi(n - 1, origem, auxiliar, destino);

    // Move o último disco da origem para o destino
    int disco;
    if(pop(origem,&disco)) {
    push(destino, disco);
    printf("Mover disco %d de %c -> %c\n", disco, origem->letra, destino->letra);
}
    // Move n-1 discos da auxiliar para o destino
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    Pilha origem, destino, auxiliar;
    int n;

    inicializarPilha(&origem, 'A');
    inicializarPilha(&auxiliar, 'B');
    inicializarPilha(&destino, 'C');

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    // Preenche a pilha origem (disco maior embaixo)
    for (int i = n; i >= 1; i--) {
        push(&origem, i);
    }

    printf("\n--- Movimentos ---\n");
    torreDeHanoi(n, &origem, &destino, &auxiliar);

    printf("\n--- Resultado final ---\n");
    imprimirPilha(&origem);
    imprimirPilha(&auxiliar);
    imprimirPilha(&destino);

    return 0;
}