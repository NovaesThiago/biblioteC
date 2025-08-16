#include <stdio.h>
#include <string.h>
#include "livro.h"

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void cadastrarLivro(const char *nomeLivro) {
    strcpy(biblioteca[totalLivros].nome, nomeLivro);
    biblioteca[totalLivros].disponivel = 1;
    inicializarFila(&biblioteca[totalLivros].espera);
    totalLivros++;
}

int buscarLivro(const char *nomeLivro) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(biblioteca[i].nome, nomeLivro) == 0)
            return i;
    }
    return -1;
}

void requisitarLivro(const char *nomeLivro, const char *nomePessoa) {
    int idx = buscarLivro(nomeLivro);
    if (idx == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (biblioteca[idx].disponivel) {
        biblioteca[idx].disponivel = 0;
        printf("%s recebeu o livro \"%s\".\n", nomePessoa, nomeLivro);
    } else {
        enfileirar(&biblioteca[idx].espera, nomePessoa);
        printf("%s entrou na fila de espera para \"%s\".\n", nomePessoa, nomeLivro);
    }
}

void devolverLivro(const char *nomeLivro) {
    int idx = buscarLivro(nomeLivro);
    if (idx == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    char proximo[MAX_NOME];
    if (desenfileirar(&biblioteca[idx].espera, proximo)) {
        printf("%s recebeu o livro \"%s\" da fila de espera.\n", proximo, nomeLivro);
    } else {
        biblioteca[idx].disponivel = 1;
        printf("Livro \"%s\" está agora disponível na biblioteca.\n", nomeLivro);
    }
}
