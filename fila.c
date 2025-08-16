#include <string.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

void enfileirar(Fila *f, const char *nomePessoa) {
    if (f->tras < MAX_FILA - 1) {
        f->tras++;
        strcpy(f->pessoas[f->tras], nomePessoa);
    }
}

int desenfileirar(Fila *f, char *nomePessoa) {
    if (f->frente <= f->tras) {
        strcpy(nomePessoa, f->pessoas[f->frente]);
        f->frente++;
        return 1;
    }
    return 0;
}

int filaVazia(Fila *f) {
    return f->frente > f->tras;
}
