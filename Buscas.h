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
#include <cmath>

using namespace std;



class Buscas {
private:
    int qntJarros;
    int * volumes;
    int * objetivo;
    int qntOperacoes;
    int numPermutacoes;
    bool enche(Estado *candidato, Estado* pai,Pilha* abertos);
    bool enche(Estado *candidato, Estado* pai);
    bool permutacao2a2(Estado *candidato, Estado* pai,Pilha* abertos);
    bool permutacao2a2(Estado *candidato, Estado* pai);
    bool transferirVolumeAux(Estado * candidato,Pilha* abertos, int i, int j);
    bool transferirVolumeAux(Estado * candidato,Estado* pai, int i, int j);
    void transferirVolume(Estado * candidato,int i, int j);
    bool esvazia(Estado *candidato, Estado* pai, Pilha* abertos);
    bool esvazia(Estado *candidato, Estado* pai);
    bool existeCandidato(Estado *candidato,Estado * pai);
    Estado* criaCandidato(Estado* pai);
    bool ehSolucao(Estado *candidato);
    void calculaHeuristica(Estado * candidato,int i);
    void imprimeHeuristica(Estado* solucao);
    void calculaFuncao(Estado *candidato);
    void imprimeFuncao(Estado* solucao);
    int calculaAltura(Estado* solucao);
    bool ehConsiste(Estado* solucao);
    bool ehRaiz(Estado * candidato);

public:
    Buscas(int * volumes,int* objetivo, int tam);
    virtual ~Buscas();
    bool backtraking();
    bool profundidade();
    bool largura();
    bool ordenada();
    bool gulosa(int i);
    bool A(int i);
    bool IDA(int i);


};



#endif //JOGO_DOS_JARROS_BUSCAS_H