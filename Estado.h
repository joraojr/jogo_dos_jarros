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
    void setVolumeJarro(int jarro, int vol);
    bool temEspaco(int jarro);


private:
        /*
         * jarro = jarro[i]
         * volume total do jarro => j = 0
         * volume ocupado do jarro => j = 1
         */
        int *jarros[2];
        int qntJarros;

};


#endif //JOGO_DOS_JARROS_ESTADO_H
