//
// Created by joraojr on 11/06/18.
//

#ifndef JOGO_DOS_JARROS_PILHA_H
#define JOGO_DOS_JARROS_PILHA_H

#include "Estado.h"
#include "Lista.h"


class Pilha {
private:
    No *topo;
    int n;
public:
    Pilha();
    virtual ~Pilha();
    Estado* getTopo();
    void empilha(Estado * filho);
    void desempilha();
    bool ehVazio();
    bool existe(Estado * filho);
};


#endif //JOGO_DOS_JARROS_PILHA_H
