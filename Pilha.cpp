//
// Created by joraojr on 11/06/18.
//

#include "Pilha.h"

Pilha::Pilha() {
    Pilha::topo = NULL;
}

Pilha::~Pilha() {
    No *p = topo;
    while (topo != NULL){
        topo = p->prox;
        delete p;
        p = topo;
    }
}

Estado* Pilha::getTopo() {
    if(topo != NULL)
        return topo->estadoAtual;
    else
        return NULL;
}

void Pilha::empilha(Estado *filho) {

    No *p = new No;
    p->estadoAtual = filho;
    p->prox = topo;
    topo = p;

}

void Pilha::desempilha() {
    No *p;
    if(topo != NULL){
        p= topo;
        topo= p->prox;
        delete p; // VERIFICAR
    }
}

bool Pilha::ehVazio() {
    return (topo == NULL);
}

bool Pilha::existe(Estado * filho){
    No *p = topo;
    int i;
    while(p!= NULL){
        for(i = 0; i < filho->getQntJarros(); i++ ){
            if(p->estadoAtual->getVolumeJarro(i) != filho->getVolumeJarro(i))
                break;
        }
        if(i == p->estadoAtual->getQntJarros())
            return true;
        p = p->prox;
    }
    return false;

}