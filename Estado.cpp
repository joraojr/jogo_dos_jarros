//
// Created by joraojr on 21/05/18.
//

#include "Estado.h"

Estado::Estado(int tam) {
    qntJarros = tam;
    (*jarros) = new int[tam];
    for(int i =0 ; i< qntJarros ; i ++){
        jarros[i][1] = 0 ;
    }
}

Estado::~Estado() {
    for (int i = 0; i < qntJarros; i++)
        delete[] jarros[i];
    delete[] jarros;
}

int *const *Estado::getJarro() const {
    return jarros;
}

void Estado::setQntJarros(int qntJarros) {
    Estado::qntJarros = qntJarros;
}

int Estado::getQntJarros() const {
    return qntJarros;
}

void Estado::setVolumeJarro(int jarro, int vol) {
    if(vol > jarros[jarro][0])
        jarros[jarro][1] = jarros[jarro][0];
    else
        jarros[jarro][1] = vol;
}

bool Estado::temEspaco(int jarro) {
    if(jarros[jarro][1] - jarros[jarro][0] > 0)
        return true;
    return false;
}