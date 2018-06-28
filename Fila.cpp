//
// Created by joraojr on 11/06/18.
//

#include "Fila.h"

Fila::Fila() {
    Fila::primeiro = NULL;
    Fila::ultimo = NULL;
}

Fila::~Fila() {
    No *p =primeiro;

    while (primeiro != NULL){
        primeiro = p->prox;
        delete p;
        p = primeiro;
    }

    ultimo =  NULL;
}

Estado * Fila::getPrimeiro() {
    if(primeiro != NULL)
        return primeiro->estadoAtual;
    return NULL;
}

bool  Fila::ehVazio() {
    if(ultimo == NULL)
        return true;
    return false;

}

void Fila::insere(Estado *filho) {
    No * p = new No();
    p->estadoAtual = filho;
    p->prox = NULL;

    if(ultimo == NULL)
        primeiro = p;
    else
        ultimo->prox = p;

    ultimo = p;
}

void Fila::remove() {
    No * p;

    if(primeiro != NULL){
        p = primeiro;
        primeiro = primeiro->prox;

        if(primeiro == NULL )
            ultimo = NULL;

        delete p;
    }

}