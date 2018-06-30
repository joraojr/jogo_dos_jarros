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
    int qntOperacoes;
    int numPermutacoes;
    bool enche(Estado *candidato, Estado* pai,Pilha* abertos);
    bool permutacao2a2(Estado *candidato, Estado* pai,Pilha* abertos);
    bool transferirVolumeAux(Estado * candidato,Pilha* abertos, int i, int j);
    void transferirVolume(Estado * candidato,int i, int j);
    Estado* criaCandidato(Estado* pai);
    bool ehSolucao(Estado *candidato);
    void imprime(Estado* pai);
    bool esvazia(Estado *candidato, Estado* pai, Pilha* abertos);

public:
    Buscas(int * volumes,int* objetivo, int tam);
    virtual ~Buscas();
    bool backtraking();


};



#endif //JOGO_DOS_JARROS_BUSCAS_H
