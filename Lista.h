//
// Created by joraojr on 27/06/18.
//

#ifndef JOGO_DOS_JARROS_LISTA_H
#define JOGO_DOS_JARROS_LISTA_H

#include "Estado.h"


using namespace std;
struct No {
    Estado *estadoAtual;
    No *prox;
};


class Lista {
private:
    No *primeiro;
    int tam;
public:
    Lista();
    virtual ~Lista();
    Estado* getPrimeiro();
    int getTam();
    void insere(Estado * filho);
    void insereOrdenadoCusto(Estado * filho);
    void insereOrdenadoHeuristica(Estado * filho);
    void insereOrdenadoFuncao(Estado *filho);
    void remove();
    int getMenorFuncao();
    bool ehVazio();
    void imprime();
    void imprimeEstado(Estado *estado);
    void limpa();
};


#endif //JOGO_DOS_JARROS_LISTA_H
