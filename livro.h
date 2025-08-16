#ifndef LIVRO_H
#define LIVRO_H

#include "fila.h"

#define MAX_LIVROS 50

typedef struct {
    char nome[MAX_NOME];
    int disponivel;
    Fila espera;
} Livro;

void cadastrarLivro(const char *nomeLivro);
void requisitarLivro(const char *nomeLivro, const char *nomePessoa);
void devolverLivro(const char *nomeLivro);

#endif
