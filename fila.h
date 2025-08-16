#ifndef FILA_H
#define FILA_H

#define MAX_NOME 100
#define MAX_FILA 10

typedef struct {
    char pessoas[MAX_FILA][MAX_NOME];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *f);
void enfileirar(Fila *f, const char *nomePessoa);
int desenfileirar(Fila *f, char *nomePessoa);
int filaVazia(Fila *f);

#endif
