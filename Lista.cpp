//
// Created by joraojr on 27/06/18.
//

#include "Lista.h"

Lista::Lista() {
    Lista::primeiro = NULL;
}

Lista::~Lista() {
    No *p =primeiro;

    while (primeiro != NULL){
        primeiro = p->prox;
        delete p;
        p = primeiro;
    }

}

Estado * Lista::getPrimeiro() {
    if(primeiro != NULL)
        return primeiro->estadoAtual;
    return NULL;
}

bool  Lista::ehVazio() {
    if(primeiro == NULL)
        return true;
    return false;

}

void Lista::insere(Estado *filho) {
    No * p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = aux;
    primeiro= p;
}


void Lista::insereOrdenado(Estado *filho) {
    No * p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = NULL;
    if(primeiro == NULL){
        primeiro = p;
    }
    else {
        while(aux->prox != NULL && aux->estadoAtual->getCusto() <= p->estadoAtual->getCusto()){
            if(aux->prox->estadoAtual->getCusto() > p->estadoAtual->getCusto()){
                No* p1 = aux->prox;
                aux->prox = p;
                p->prox = p1;
                break;
            }
            aux = aux->prox;
        }
        aux->prox = p;
    }
}


void Lista::imprimeEstado(Estado *pai) {
    int qntJarros = pai->getQntJarros();
    for (int i = 0; i < qntJarros; i++) {
        cout << "-" << pai->getVolumeJarro(i) << "-";
    }
    cout << "Pai: ";
    if (pai->getPai() != NULL) {
        for (int i = 0; i < qntJarros; i++) {
            cout << "-" << pai->getPai()->getVolumeJarro(i) << "-";
        }
    }
    cout << endl;

}


void Lista::imprime() {
    No* p = primeiro;

    while (p!= NULL){
        imprimeEstado(p->estadoAtual);
        p = p->prox;
    }
}


Estado * Lista::getMenorCusto() {
    No*p = primeiro;
    No*estadoMenorCusto = primeiro;
    int menorCusto = primeiro->estadoAtual->getOperacao();
    while (p != NULL){
        if(p->estadoAtual->getOperacao()< menorCusto){
            menorCusto = p->estadoAtual->getOperacao();
            estadoMenorCusto = p;
        }
        p = p->prox;
    }

    return estadoMenorCusto->estadoAtual;

}
void Lista::remove() {

    No * p = primeiro;
    primeiro = p->prox;
    delete p;

}
