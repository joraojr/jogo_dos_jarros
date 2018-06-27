//
// Created by joraojr on 11/06/18.
//

#ifndef JOGO_DOS_JARROS_LISTA_H
#define JOGO_DOS_JARROS_LISTA_H

#include "Estado.h"

struct No {
    Estado *estadoAtual;
    No *prox;
};


class Lista {
public:
    Lista();

    virtual ~Lista();

    void Insere(Estado *estado);

    void Remove();


private:
    No *raiz;

};


#endif //JOGO_DOS_JARROS_LISTA_H
