//
// Created by joraojr on 21/05/18.
//

#include "Estado.h"

Estado::Estado(int tam) {
    qntJarros = tam;
    (*jarros) = new int[tam];
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
