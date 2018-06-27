//
// Created by joraojr on 21/05/18.
//

#ifndef JOGO_DOS_JARROS_ESTADO_H
#define JOGO_DOS_JARROS_ESTADO_H

#include <iostream>

class Estado {


    public:

    Estado(int tam);
    virtual ~Estado();
    int  *getJarro() const;
    int getQntJarros() const;
    void setQntJarros(int qntJarros);
    void setVolumeJarro(int i, int vol);
    void dimVolumeJarro(int i, int vol);
    int getVolumeJarro(int i);

    int getOperacao() const;

    void setOperacao(int i);

    Estado *getPai() const;

    void setPai(Estado *pai);

    void addOperacao();


private:

    int *jarros;
    int qntJarros;
    int operacao;
    Estado *pai;


};


#endif //JOGO_DOS_JARROS_ESTADO_H
