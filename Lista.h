//
// Created by joraojr on 27/06/18.
//

#ifndef JOGO_DOS_JARROS_LISTA_H
#define JOGO_DOS_JARROS_LISTA_H

#include "Estado.h"


struct No {
    Estado *estadoAtual;
    No *prox;
};


class Lista {
private:
    No *primeiro;
public:
    Lista();
    virtual ~Lista();
    Estado* getPrimeiro();
    void insere(Estado * filho);
    void remove();
    bool ehVazio();
};


#endif //JOGO_DOS_JARROS_LISTA_H
