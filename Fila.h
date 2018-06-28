//
// Created by joraojr on 11/06/18.
//

#ifndef JOGO_DOS_JARROS_FILA_H
#define JOGO_DOS_JARROS_FILA_H

#include "Estado.h"
#include "Lista.h"


class Fila{
private:
    No *primeiro;
    No *ultimo;
public:
    Fila();
    virtual ~Fila();
    Estado* getPrimeiro();
    void insere(Estado * filho);
    void remove();
    bool ehVazio();

};


#endif //JOGO_DOS_JARROS_FILA_H
