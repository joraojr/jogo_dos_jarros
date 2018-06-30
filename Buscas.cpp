//
// Created by joraojr on 21/06/18.
//

#include "Buscas.h"

Buscas::Buscas(int *volumes, int *objetivo, int tam) {
    Buscas::qntJarros = tam;
    Buscas::volumes = volumes;
    Buscas::objetivo = objetivo;
    Buscas::numPermutacoes = (qntJarros * (qntJarros - 1)) / 2;
    Buscas::qntOperacoes = (2 * qntJarros + numPermutacoes);

}

Buscas::~Buscas() {

}

void Buscas::imprime(Estado *pai) {
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


bool Buscas::backtraking() {
    bool fracasso = false, sucesso = false;
    Pilha *abertos = new Pilha;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    Estado *candidato;
    abertos->empilha(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getTopo();
        candidato = criaCandidato(pai);
        //imprime(candidato);
        if (pai->getOperacao() < qntOperacoes) {
            //  cout <<"aqui||- "<<pai->getOperacao()<<endl;
            if (enche(candidato, pai, abertos) || permutacao2a2(candidato, pai, abertos) ||
                esvazia(candidato, pai, abertos)) {
                if (ehSolucao(candidato)) {
                    sucesso = true;
                }
                //aumenta altura
                abertos->empilha(candidato);
            }

        } else {
            //diminui altura
            abertos->desempilha();
            fechados->insere(candidato);
        }

    }
   // fechados->imprime();
    return sucesso;
}

Estado *Buscas::criaCandidato(Estado *pai) {
    Estado *candidato = new Estado(qntJarros);
    for (int i = 0; i < qntJarros; i++) {
        candidato->setVolumeJarro(i, pai->getVolumeJarro(i));
    }

    return candidato;

}


bool Buscas::enche(Estado *candidato, Estado *pai, Pilha *abertos) {

    for (int i = pai->getOperacao(); i < qntJarros; i++) {
        pai->addOperacao();
        if (pai->getVolumeJarro(i) < volumes[i]) {
            int aux = candidato->getVolumeJarro(i);
            candidato->setVolumeJarro(i, volumes[i]);
            if (!abertos->existe(candidato))
                return true;
            candidato->setVolumeJarro(i, aux);
        }
    }
    return false;
}


bool Buscas::permutacao2a2(Estado *candidato, Estado *pai, Pilha *abertos) {

    std::vector<bool> v(qntJarros);
    std::fill(v.end() - 2, v.end(), true);
/*
    cout << "aqui||- " << pai->getOperacao() << endl;
*/

    int i, j, count = 1;
    do {
        i = 0, j = 0;
        for (int k = 0; k < qntJarros; ++k) {
            if (v[k]) {
                i += k;
                j = k;
            }
        }
        if (count > (pai->getOperacao() - qntJarros)) {
            pai->addOperacao();
            if (transferirVolumeAux(candidato, abertos, i - j, j))
                return true;
            if (transferirVolumeAux(candidato, abertos, j, i - j))
                return true;
        }
        count++;
    } while (next_permutation(v.begin(), v.end()));


    return false;

}

bool Buscas::esvazia(Estado *candidato, Estado *pai, Pilha *abertos) {
    for (int i = pai->getOperacao() - (qntJarros + numPermutacoes); i < qntJarros; i++) {
        pai->addOperacao();
        if (pai->getVolumeJarro(i) > 0) {
            int aux = candidato->getVolumeJarro(i);
            candidato->setVolumeJarro(i, 0);
            if (!abertos->existe(candidato))
                return true;
            candidato->setVolumeJarro(i, aux);
        }
    }
    return false;


}

bool Buscas::transferirVolumeAux(Estado *candidato, Pilha *abertos, int i, int j) {
    int auxI = candidato->getVolumeJarro(i);
    int auxJ = candidato->getVolumeJarro(j);
    transferirVolume(candidato, i, j);

    if (abertos->existe(candidato) || (candidato->getVolumeJarro(i) == auxI && candidato->getVolumeJarro(j) == auxJ)) {
        candidato->setVolumeJarro(i, auxI);
        candidato->setVolumeJarro(j, auxJ);
        return false;
    };
    return true;

}

void Buscas::transferirVolume(Estado *candidato, int i, int j) {

    if (i != j) {
        int atualI = candidato->getVolumeJarro(i);
        int atualJ = candidato->getVolumeJarro(j);
        if (atualI > 0 && atualJ == 0) {
            if (atualI >= volumes[j]) {
                candidato->setVolumeJarro(j, volumes[j]);
                candidato->setVolumeJarro(i, atualI - volumes[j]);
            } else if (atualI < volumes[j]) {
                candidato->setVolumeJarro(j, atualI);
                candidato->setVolumeJarro(i, 0);
            }
        } else if (atualI > 0 && atualJ > 0) {
            if (volumes[j] - atualJ >= atualI) {
                candidato->setVolumeJarro(j, atualJ + atualI);
                candidato->setVolumeJarro(i, 0);
            } else if (volumes[j] - atualJ < atualI && volumes[j] - atualJ > 0) {
                int aux = volumes[j] - atualJ;
                candidato->setVolumeJarro(j, volumes[j]);
                candidato->setVolumeJarro(i, atualI - aux);
            }

        }
    }
/*    cout << "I--"<<i<<"J--"<<j;
    imprime(candidato);*/


}

bool Buscas::ehSolucao(Estado *candidato) {

    for (int i = 0; i < qntJarros; i++) {
        if (candidato->getVolumeJarro(i) != objetivo[i])
            return false;
    }
    return true;
}


/*bool Buscas::existeCandidato(Estado *filho) {

    Estado *aux = estadoAtual;
    Estado *aux2 = criaFilho();
    int i;
*//*
       cout << "NO: ";
        imprime(filho);
        cout<<endl;
*//*

    for (i = 0; i < qntJarros; i++) {
        if (aux2->getVolumeJarro(i) != filho->getVolumeJarro(i)) {
            break;
        }
    }
    if (i == qntJarros) return true;

    while (aux->getPai() != NULL) {
        aux = aux->getPai();
        for (i = 0; i < qntJarros; i++) {
            if (aux->getVolumeJarro(i) != aux2->getVolumeJarro(i)) {
                break;
            }
        }
        if (i == qntJarros) return true;
//            imprime(aux);


    }
    return false;


}*/