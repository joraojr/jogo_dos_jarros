//
// Created by joraojr on 21/05/18.
//

#ifndef JOGO_DOS_JARROS_BUSCAS_H
#define JOGO_DOS_JARROS_BUSCAS_H

#include "Estado.h"


class Buscas {

private:
    int qntJarros;
    int * volumes;
    int * objetivo;
    Estado *estadoInicial, *estadoAtual;

public:
    Buscas(int * volumes,int* objetivo, int tam);
    virtual ~Buscas();
    int *getVolumes() const;
    int *getObjetivo() const;
    int getEstadoAtual(int i);
    int getVolume(int i);
    void addVolume(int i);
    void transferirVolume(int i, int j);

};


#endif //JOGO_DOS_JARROS_BUSCAS_H
