// main1.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

bool Palindromo(char *palavra) {
    Pilha p;
    inicializarPilha(&p, 'b'); 

    int len = strlen(palavra);
    int meio = len / 2;

    // Empilha a primeira metade
    for (int i = 0; i < meio; i++) {
        push(&p, palavra[i]);
    }

    // Se for ímpar, ignora o caractere do meio
    int inicioSegundaMetade = (len % 2 == 0) ? meio : meio + 1;

    // Compara a segunda metade 
    for (int i = inicioSegundaMetade; i < len; i++) {
        int c;
        if(!pop(&p, &c) || c != palavra[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char palavra[MAX_SIZE];

    printf("Digite uma palavra: ");
    fflush(stdout); 
    scanf("%s", palavra);

    if (Palindromo(palavra))
        printf("\"%s\" E um palindromo!\n", palavra);
    else
        printf("\"%s\" Nao e um palindromo!\n", palavra);

    return 0;
}
