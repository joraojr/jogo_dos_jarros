//
// Created by joraojr on 21/05/18.
//

#ifndef JOGO_DOS_JARROS_ESTADO_H
#define JOGO_DOS_JARROS_ESTADO_H


class Estado {

    public:

    Estado(int tam);

    virtual ~Estado();

    int *const *getJarro() const;

    int getQntJarros() const;

    void setQntJarros(int qntJarros);

private:
        int *jarros[2];
        int qntJarros;

};


#endif //JOGO_DOS_JARROS_ESTADO_H
