//
// Created by joraojr on 21/05/18.
//

#ifndef JOGO_DOS_JARROS_ESTADO_H
#define JOGO_DOS_JARROS_ESTADO_H


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


    private:

    int *jarros;
    int qntJarros;

};


#endif //JOGO_DOS_JARROS_ESTADO_H
