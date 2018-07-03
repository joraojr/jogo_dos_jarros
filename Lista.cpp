//
// Created by joraojr on 27/06/18.
//

#include "Lista.h"

Lista::Lista() {
    Lista::primeiro = NULL;
    Lista::tam = 0;
}

Lista::~Lista() {
    No *p = primeiro;

    while (primeiro != NULL) {
        primeiro = p->prox;
        delete p;
        p = primeiro;
    }

}

Estado *Lista::getPrimeiro() {
    if (primeiro != NULL)
        return primeiro->estadoAtual;
    return NULL;
}

bool Lista::ehVazio() {
    if (primeiro == NULL)
        return true;
    return false;

}

void Lista::insere(Estado *filho) {
    No *p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = aux;
    primeiro = p;
    tam ++;
}


void Lista::insereOrdenadoCusto(Estado *filho) {
    tam ++;
    bool ok = false;
    No *p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = NULL;
    if (primeiro == NULL) {
        primeiro = p;
    } else if (aux->prox == NULL) {
        if (aux->estadoAtual->getCusto() <= p->estadoAtual->getCusto()) {
            aux->prox = p;
        } else {
            p->prox = aux;
            primeiro = p;
        }
    } else {
        No *aux2 = aux;
        while (aux->prox != NULL && aux->estadoAtual->getCusto() <= p->estadoAtual->getCusto()) {
            if (aux->prox->estadoAtual->getCusto() > p->estadoAtual->getCusto()) {
                No *p1 = aux->prox;
                aux->prox = p;
                p->prox = p1;
                ok = true;
                break;
            }
            aux2 = aux;
            aux = aux->prox;
        }
        if (!ok) {
            if (aux->prox == NULL && aux->estadoAtual->getCusto() <= p->estadoAtual->getCusto()) {
                aux->prox = p;
            } else {
                p->prox = aux;
                primeiro = p;
            }
        }
    }
}

void Lista::insereOrdenadoHeuristica(Estado *filho) {
    tam ++;
    bool ok = false;
    No *p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = NULL;
    if (primeiro == NULL) {
        primeiro = p;
    } else if (aux->prox == NULL) {
        if (aux->estadoAtual->getHeuristica() <= p->estadoAtual->getHeuristica()) {
            aux->prox = p;
        } else {
            p->prox = aux;
            primeiro = p;
        }
    } else {
        No* aux2 = aux;
        while (aux->prox != NULL && aux->estadoAtual->getHeuristica() <= p->estadoAtual->getHeuristica()) {
            if (aux->prox->estadoAtual->getHeuristica() > p->estadoAtual->getHeuristica()) {
                No *p1 = aux->prox;
                aux->prox = p;
                p->prox = p1;
                ok = true;
                break;
            }
            aux2 = aux;
            aux = aux->prox;
        }
        if(!ok) {
            if (aux->prox == NULL && aux->estadoAtual->getHeuristica() <= p->estadoAtual->getHeuristica()) {
                aux->prox = p;
            } else {
                p->prox = aux;
                primeiro = p;
            }
        }
    }
}

void Lista::insereOrdenadoFuncao(Estado *filho) {
    tam ++;
    bool ok = false;
    No *p = new No, *aux = primeiro;
    p->estadoAtual = filho;
    p->prox = NULL;
    if (primeiro == NULL) {
        primeiro = p;
    } else if (aux->prox == NULL) {
        if (aux->estadoAtual->getFuncao() <= p->estadoAtual->getFuncao()) {
            aux->prox = p;
        } else {
            p->prox = aux;
            primeiro = p;
        }
    } else {
        No* aux2 = aux;
        while (aux->prox != NULL && aux->estadoAtual->getFuncao() <= p->estadoAtual->getFuncao()) {
            if (aux->prox->estadoAtual->getFuncao() > p->estadoAtual->getFuncao()) {
                No *p1 = aux->prox;
                aux->prox = p;
                p->prox = p1;
                ok = true;
                break;
            }
            aux2 = aux;
            aux = aux->prox;
        }
        if(!ok) {
            if (aux->prox == NULL && aux->estadoAtual->getFuncao() <= p->estadoAtual->getFuncao()) {
                aux->prox = p;
            } else {
                p->prox = aux;
                primeiro = p;
            }
        }
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
    No *p = primeiro;

    while (p != NULL) {
        imprimeEstado(p->estadoAtual);
        p = p->prox;
    }
    cout << endl;
}


int Lista::getMenorFuncao() {
    No *p = primeiro;
    int menorCusto = primeiro->estadoAtual->getCusto();
    while (p != NULL) {
        if (p->estadoAtual->getOperacao() < menorCusto) {
            menorCusto = p->estadoAtual->getOperacao();
        }
        p = p->prox;
    }

    return menorCusto;

}

void Lista::remove() {

    No *p = primeiro;
    primeiro = p->prox;
    delete p;
    tam --;

}

int Lista::getTam(){
    return Lista::tam;
}

