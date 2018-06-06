//
// Created by joraojr on 21/05/18.
//

#include "Buscas.h"


Buscas::Buscas(int *volumes, int *objetivo, int tam) {
    Buscas::qntJarros = tam;
    Buscas::volumes = volumes;
    Buscas::objetivo = objetivo;
    Buscas::estadoInicial = new Estado(qntJarros);
    Buscas::estadoAtual = new Estado(qntJarros);

}


Buscas::~Buscas() {

}

int *Buscas::getVolumes() const {
    return volumes;
}

int *Buscas::getObjetivo() const {
    return objetivo;
}

void Buscas::addVolume(int i) {
    estadoAtual->setVolumeJarro(i, volumes[i]);
}

int Buscas::getVolume(int i) {
    return estadoAtual->getVolumeJarro(i);
}

int Buscas::getEstadoAtual(int i ) {
    return estadoAtual->getVolumeJarro(i);
}

void Buscas::transferirVolume(int i, int j) {

    if (i != j) {
        int atualI = estadoAtual->getVolumeJarro(i);
        int atualJ = estadoAtual->getVolumeJarro(j);
        if (atualI > 0 && atualJ == 0) {
            if (atualI >= volumes[j]) {
                estadoAtual->setVolumeJarro(j, volumes[j]);
                estadoAtual->setVolumeJarro(i, atualI - volumes[j]);
            } else if (atualI < volumes[j]) {
                estadoAtual->setVolumeJarro(j, atualI);
                estadoAtual->setVolumeJarro(i, 0);
            }
        } else if (atualI > 0 && atualJ > 0) {
            if (volumes[j] - atualJ >= atualI) {
                estadoAtual->setVolumeJarro(j, atualJ + atualI);
                estadoAtual->setVolumeJarro(i, 0);
            } else if (volumes[j] - atualJ < atualI && volumes[j] - atualJ > 0) {
                int aux = volumes[j] - atualJ;
                estadoAtual->setVolumeJarro(j, volumes[j]);
                estadoAtual->setVolumeJarro(i, atualI - aux);
            }

        }

    }
}
