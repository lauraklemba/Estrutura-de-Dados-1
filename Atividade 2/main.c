#include <stdio.h> 
#include "lista_estatica.h" 
  
int main(void) { 

    Playlist playlist;

    criarPlaylist(&playlist); 
    int opcao, id, posicao;

do {
        printf("\n=== MINHA PLAYLIST ===\n");
        printf("1. Adicionar musica\n");
        printf("2. Remover musica\n");
        printf("3. Buscar musica\n");
        printf("4. Mostrar playlist\n");
        printf("5. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: 
            printf("Digite o ID da musica: ");
            scanf("%d", &id);
                 if (adicionarMusica(&playlist, id))
                    printf("Sua Musica %d foi adicionada com sucesso\n", id);
                else
                    printf("A playlist já esta cheia!\n");
                break;
            break;
        
        case 2:  
            printf("Digite a posicao para remover  a musica: ");
            scanf("%d", &posicao);
            if (removerMusica(&playlist, posicao))
                printf("A musica foi removida da %d posiçao\n", posicao);
            else
                printf("Posicao invalida!\n");
                break;

        case 3: 
            printf("Para buscar, digite o ID da musica: ");
            scanf("%d", &id);
            posicao = buscarMusica(&playlist, id);
            if (posicao != -1)
                printf("A musica %d foi encontrada na posicao %d! (1)\n", id, posicao);
            else
                printf("Musica %d nao encontrada (-1) \n", id);
            break;

        case 4: 
            printf("=== PLAYLIST ===\n");
            mostrarPlaylist(&playlist);
            printf("Total: %d musica(s)\n", playlist.total);
            break;

        case 5: 
            printf("Saindo da playlist\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

   } while (opcao != 5);
   
    return 0;
}