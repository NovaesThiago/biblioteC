#include <stdio.h>
#include "livro.h"

int main() {
    cadastrarLivro("Dom Casmurro");
    cadastrarLivro("O Pequeno Príncipe");

    requisitarLivro("Dom Casmurro", "Ana");
    requisitarLivro("Dom Casmurro", "Bruno");
    requisitarLivro("Dom Casmurro", "Carlos");

    devolverLivro("Dom Casmurro");
    devolverLivro("Dom Casmurro");
    devolverLivro("Dom Casmurro");

    return 0;
}
