#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcao;
    char nomeLivro[MAX_NOME];
    char nomePessoa[MAX_NOME];

    while (1) {
        printf("\n===== MENU BIBLIOTECA =====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Requisitar livro\n");
        printf("3. Devolver livro\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("Nome do livro: ");
                fgets(nomeLivro, MAX_NOME, stdin);
                nomeLivro[strcspn(nomeLivro, "\n")] = '\0'; // Remove \n
                cadastrarLivro(nomeLivro);
                break;

            case 2:
                printf("Nome do livro: ");
                fgets(nomeLivro, MAX_NOME, stdin);
                nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

                printf("Nome da pessoa: ");
                fgets(nomePessoa, MAX_NOME, stdin);
                nomePessoa[strcspn(nomePessoa, "\n")] = '\0';

                requisitarLivro(nomeLivro, nomePessoa);
                break;

            case 3:
                printf("Nome do livro a devolver: ");
                fgets(nomeLivro, MAX_NOME, stdin);
                nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

                devolverLivro(nomeLivro);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}