//
// Created by joraojr on 21/05/18.
//

#include "Estado.h"

Estado::Estado(int tam) {
    qntJarros = tam;
    jarros= new int[tam];
    for(int i =0 ; i< qntJarros ; i ++){
        jarros[i] = 0 ;
    }
}

Estado::~Estado() {
/*    for (int i = 0; i < qntJarros; i++)
        delete jarros[i];*/
}

int  *Estado::getJarro() const {
    return jarros;
}

void Estado::setQntJarros(int qntJarros) {
    Estado::qntJarros = qntJarros;
}

int Estado::getQntJarros() const {
    return qntJarros;
}

void Estado::setVolumeJarro(int i, int vol) {
        jarros[i] = vol;
}

void Estado::dimVolumeJarro(int i, int vol) {
    jarros[i] -= vol;
}

int Estado::getVolumeJarro(int i) {
    return jarros[i];
}
