//
// Created by joraojr on 21/05/18.
//

#include "Buscas.h"


Buscas::Buscas(int *volumes, int *objetivo, int tam) {
    Buscas::qntJarros = tam;
    Buscas::volumes = volumes;
    Buscas::objetivo = objetivo;
    Buscas::estadoInicial = new Estado(qntJarros);
    Buscas::estadoAtual = new Estado(qntJarros);
    Buscas::numPermutacoes = (qntJarros * (qntJarros - 1)) / 2;
    Buscas::qntOperacoes = (qntJarros + numPermutacoes);

}


Buscas::~Buscas() {

}

int *Buscas::getVolumes() const {
    return volumes;
}

int *Buscas::getObjetivo() const {
    return objetivo;
}

void Buscas::addVolume(int i) {
    estadoAtual->setVolumeJarro(i, volumes[i]);
}

int Buscas::getVolume(int i) {
    return estadoAtual->getVolumeJarro(i);
}

int Buscas::getEstadoAtual(int i) {
    return estadoAtual->getVolumeJarro(i);
}

bool Buscas::transferirVolumeAux(Estado *filho, int i, int j) {
    int auxI = estadoAtual->getVolumeJarro(i);
    int auxJ = estadoAtual->getVolumeJarro(j);
    transferirVolume(i, j);

    if (ehIgual(filho) || existeFilho(filho) ||
        (estadoAtual->getVolumeJarro(i) == auxI && estadoAtual->getVolumeJarro(j) == auxJ)) {
        estadoAtual->setVolumeJarro(i, auxI);
        estadoAtual->setVolumeJarro(j, auxJ);
        return false;
    }
    troca(filho);
    estadoAtual->setVolumeJarro(i, auxI);
    estadoAtual->setVolumeJarro(j, auxJ);
    return true;

}

void Buscas::transferirVolume(int i, int j) {

    if (i != j) {
        int atualI = estadoAtual->getVolumeJarro(i);
        int atualJ = estadoAtual->getVolumeJarro(j);
        if (atualI > 0 && atualJ == 0) {
            if (atualI >= volumes[j]) {
                estadoAtual->setVolumeJarro(j, volumes[j]);
                estadoAtual->setVolumeJarro(i, atualI - volumes[j]);
            } else if (atualI < volumes[j]) {
                estadoAtual->setVolumeJarro(j, atualI);
                estadoAtual->setVolumeJarro(i, 0);
            }
        } else if (atualI > 0 && atualJ > 0) {
            if (volumes[j] - atualJ >= atualI) {
                estadoAtual->setVolumeJarro(j, atualJ + atualI);
                estadoAtual->setVolumeJarro(i, 0);
            } else if (volumes[j] - atualJ < atualI && volumes[j] - atualJ > 0) {
                int aux = volumes[j] - atualJ;
                estadoAtual->setVolumeJarro(j, volumes[j]);
                estadoAtual->setVolumeJarro(i, atualI - aux);
            }

        }
    }
}

void Buscas::imprime(Estado *filho) {
    for (int i = 0; i < qntJarros; i++) {
        cout << "-" << estadoAtual->getVolumeJarro(i) << "-";
    }
    cout << "F: ";
    for (int i = 0; i < qntJarros; i++) {
        cout << "-" << filho->getVolumeJarro(i) << "-";
    }
    cout << endl;

}


bool Buscas::backtraking() {
    bool fracasso = false, sucesso = false;
    Estado *filho = criaFilho();
    //int count = 0;
    if (ehSolucao(filho))
        return true;
    while (!(fracasso || sucesso)) {
        imprime(filho);
        if (estadoAtual->getOperacao() < qntOperacoes) {
            if (encher(filho)) {
                filho->setPai(estadoAtual);
                if (ehSolucao(filho))
                    sucesso = true;
                estadoAtual = filho;
                filho = criaFilho();
            } else if (permutacao2a2(filho)) {
                filho->setPai(estadoAtual);
                if (ehSolucao(filho))
                    sucesso = true;
                estadoAtual = filho;
                filho = criaFilho();
            } /*else if (esvazia(filho) && !existeFilho(filho)) {
                filho->setPai(estadoAtual);
                if (ehSolucao(filho))
                    sucesso = true;
                estadoAtual = filho;
                filho = criaFilho();
            }*/

        } else {
            if (ehEstadoInicial()) {
                fracasso = true;
            } else {
/*
                cout<< ++count;
*/
                delete filho;
                filho = estadoAtual;
                filho->setOperacao(0);
                estadoAtual = estadoAtual->getPai();

            }
        }

    }

    return sucesso;
}

bool Buscas::ehIgual(Estado *filho) {

    for (int i = 0; i < qntJarros; i++) {
        if (estadoAtual->getVolumeJarro(i) != filho->getVolumeJarro(i))
            return false;

    }
    return true;
}

bool Buscas::encher(Estado *filho) {

    for (int i = estadoAtual->getOperacao(); i < qntJarros; i++) {
        estadoAtual->addOperacao();
        if (estadoAtual->getVolumeJarro(i) < volumes[i]) {
            int aux = estadoAtual->getVolumeJarro(i);
            estadoAtual->setVolumeJarro(i, volumes[i]);
            if (!ehIgual(filho) && !existeFilho(filho)) {
                troca(filho);
                estadoAtual->setVolumeJarro(i, aux);
                filho->setVolumeJarro(i, volumes[i]);
                return true;

            }
            estadoAtual->setVolumeJarro(i, aux);
        }

    }
    return false;

}

void Buscas::troca(Estado *filho) {
    for (int i = 0; i < qntJarros; i++) {
        filho->setVolumeJarro(i, estadoAtual->getVolumeJarro(i));

    }
}

bool Buscas::esvazia(Estado *filho) {

    for (int i = estadoAtual->getOperacao() - (qntJarros + numPermutacoes); i < qntJarros; i++) {
        estadoAtual->addOperacao();
        if (estadoAtual->getVolumeJarro(i) > 0) {
            int aux = estadoAtual->getVolumeJarro(i);
            estadoAtual->setVolumeJarro(i, 0);
            if (!ehIgual(filho) && !existeFilho(filho)) {
                troca(filho);
                estadoAtual->setVolumeJarro(i, aux);
                filho->setVolumeJarro(i, 0);
                return true;

            }
            estadoAtual->setVolumeJarro(i, aux);
        }
    }
    return false;


}

bool Buscas::ehSolucao(Estado *filho) {

    for (int i = 0; i < qntJarros; i++) {
        if (filho->getVolumeJarro(i) != objetivo[i])
            return false;
    }
    return true;
}

/*
bool Buscas::maxToMin(Estado *filho) {

    int max, min = filho->getVolumeJarro(0);
    int posMax, posMin = 0;
    for (int i = 0; i < qntJarros; i++) {
        if (filho->getVolumeJarro(i) > max) {
            max = filho->getVolumeJarro(i);
            posMax = i;
        }
        if (filho->getVolumeJarro(i) < min) {
            min = filho->getVolumeJarro(i);
            posMin = i;
        }
    }

    return transferirVolumeAux(filho, posMax, posMin);

}
*/

Estado *Buscas::criaFilho() {
    Estado *filho = new Estado(qntJarros);
    for (int i = 0; i < qntJarros; i++) {
        filho->setVolumeJarro(i, estadoAtual->getVolumeJarro(i));
    }

    return filho;

}

bool Buscas::ehEstadoInicial() {

    for (int i = 0; i < qntJarros; i++) {
        if (estadoAtual->getVolumeJarro(i) != 0)
            return false;
    }
    return true;

}

bool Buscas::existeFilho(Estado *filho) {

    Estado *aux = estadoAtual;
    int count = 0;
    while (aux->getPai() != NULL) {
        for (int i = 0; i < qntJarros; i++) {
            if (aux->getVolumeJarro(i) == filho->getVolumeJarro(i)) {
                count++;
            }
        }
        if (count == qntJarros) return true;
        aux = aux->getPai();
        count = 0;
    }
    return false;


}

bool Buscas::permutacao2a2(Estado *filho) {
    std::vector<bool> v(qntJarros);
    std::fill(v.end() - 2, v.end(), true);
    //cout <<"|"<<estadoAtual->getOperacao()<<endl;
    int i, j, count = 1;
    do {
        i = 0, j = 0;
        for (int k = 0; k < qntJarros; ++k) {
            if (v[k]) {
                i += k;
                j = k;
            }
        }
        int aux = estadoAtual->getOperacao();
        if (count > (estadoAtual->getOperacao() - qntJarros)) {
            estadoAtual->addOperacao();
            if (transferirVolumeAux(filho, i - j, j) || (transferirVolumeAux(filho, j, i - j))) {
                return true;
            }
        }
        count++;
    } while (next_permutation(v.begin(), v.end()));

    return false;

}