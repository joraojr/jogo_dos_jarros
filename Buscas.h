//
// Created by joraojr on 21/05/18.
//

#ifndef JOGO_DOS_JARROS_BUSCAS_H
#define JOGO_DOS_JARROS_BUSCAS_H

#include "Estado.h"
#include "Fila.h"
#include "Pilha.h"
#include "Lista.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Buscas {

private:
    int qntJarros;
    int * volumes;
    int * objetivo;
    Estado *estadoInicial, *estadoAtual;
    int qntOperacoes;
    int numPermutacoes;

public:
    Buscas(int * volumes,int* objetivo, int tam);
    virtual ~Buscas();
    int *getVolumes() const;
    int *getObjetivo() const;
    int getEstadoAtual(int i);
    int getVolume(int i);
    void addVolume(int i);
    void transferirVolume(int i, int j);

    bool transferirVolumeAux(Estado *filho, int i, int j);

    bool profundidade();

    bool backtraking();

    bool maxToMin(Estado *filho);

    bool encher(Estado *filho);

    bool ehSolucao(Estado *filho);

    bool ehEstadoInicial();

    bool existeFilho(Estado *filho);

    Estado *criaFilho();

    void troca(Estado *filho);

    bool ehIgual(Estado *filho);

    bool permutacao2a2(Estado *filho);

    bool esvazia(Estado *filho);

    void imprime(Estado *filho);


};


#endif //JOGO_DOS_JARROS_BUSCAS_H
