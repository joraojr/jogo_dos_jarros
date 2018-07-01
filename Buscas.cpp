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
        //   imprime(candidato);
        if (pai->getOperacao() < qntOperacoes) {
            //  cout <<"aqui||- "<<pai->getOperacao()<<endl;
            if (enche(candidato, pai, abertos) || permutacao2a2(candidato, pai, abertos) ||
                esvazia(candidato, pai, abertos)) {
                if (ehSolucao(candidato)) {
                    fechados->insere(candidato);
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
    fechados->imprime();
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return sucesso;
}

bool Buscas::profundidade() {
    bool fracasso = false, sucesso = false;
    Pilha *abertos = new Pilha;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    Estado *candidato;
    abertos->empilha(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getTopo();
        candidato = criaCandidato(pai);
        // imprime(candidato);
        abertos->desempilha();
        fechados->insere(pai);
        while (pai->getOperacao() < qntOperacoes) {
            //  cout <<"aqui||- "<<pai->getOperacao()<<endl;
            if (enche(candidato, pai) || permutacao2a2(candidato, pai) ||
                esvazia(candidato, pai)) {
                if (ehSolucao(candidato)) {
                    sucesso = true;
                }
                candidato->setPai(pai);
                abertos->empilha(candidato);
                candidato = criaCandidato(pai);
            }

        }
    }
    fechados->imprime();
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return sucesso;

}

bool Buscas::largura() {
    bool sucesso = false;
    Fila *abertos = new Fila;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    Estado *candidato;
    abertos->insere(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getPrimeiro();
        candidato = criaCandidato(pai);
        // imprime(candidato);
        abertos->remove();
        fechados->insere(pai);
        while (pai->getOperacao() < qntOperacoes) {
            //  cout <<"aqui||- "<<pai->getOperacao()<<endl;
            if (enche(candidato, pai) || permutacao2a2(candidato, pai) ||
                esvazia(candidato, pai)) {
                if (ehSolucao(candidato)) {
                    sucesso = true;
                }
                candidato->setPai(pai);
                abertos->insere(candidato);
                candidato = criaCandidato(pai);
            }

        }
    }
    fechados->imprime();
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return sucesso;

}

bool Buscas::ordenada() {
    int custo = -1;
    bool sucesso = false;
    Lista *abertos = new Lista;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    Estado *candidato;
    abertos->insereOrdenadoCusto(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getPrimeiro();
        candidato = criaCandidato(pai);
        abertos->remove();
        fechados->insere(pai);
/*        imprime(pai);
        cout << "Custo :::" << candidato->getCusto()<<endl;*/
        if (ehSolucao(candidato)) {
            sucesso = true;
            custo = candidato->getCusto();
        } else {
            while (pai->getOperacao() < qntOperacoes) {
                if (enche(candidato, pai) || permutacao2a2(candidato, pai) ||
                    esvazia(candidato, pai)){
                    candidato->setPai(pai);
/*                    imprime(candidato);
                    cout << "Custo :::" << candidato->getCusto()<<endl;*/
                    abertos->insereOrdenadoCusto(candidato);
                    candidato = criaCandidato(pai);
                }
            }
        }
    }
    fechados->imprime();
    cout<<"Custo da solução: "<<custo;
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return sucesso;
}

void Buscas::imprimeHeuristica(Estado* solucao){
    int heuristica= 0;
    Estado* p = solucao;

    while (p != NULL) {
            heuristica += p->getHeuristica();
        p= p->getPai();
    }

    cout<< "Custo da Heuristica: "<<heuristica<<endl;
}

void Buscas::calculaHeuristica(Estado *candidato) {
    for(int i = 0 ;i <qntJarros; i ++){
        candidato->addHeuristica(abs(candidato->getVolumeJarro(i) - objetivo[i]));
    }
//    cout << "VALOR:"<<candidato->getHeuristica()<<endl;
}

bool Buscas::gulosa() {
    bool sucesso = false;
    Lista *abertos = new Lista;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    calculaHeuristica(pai);
    Estado *candidato;
    abertos->insereOrdenadoHeuristica(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getPrimeiro();
        candidato = criaCandidato(pai);
        abertos->remove();
        fechados->insere(pai);
        if (ehSolucao(candidato)) {
            sucesso = true;
            imprimeHeuristica(pai);
        } else {
            while (pai->getOperacao() < qntOperacoes) {
                if (enche(candidato, pai) || permutacao2a2(candidato, pai) ||
                    esvazia(candidato, pai)) {
                    candidato->setPai(pai);
/*                    imprime(candidato);
                    cout << "Custo :::" << candidato->getCusto()<<endl;*/
                    calculaHeuristica(candidato);
                    abertos->insereOrdenadoHeuristica(candidato);
                    candidato = criaCandidato(pai);
                }
            }

        }
    }
    fechados->imprime();
    cout<<"Heurística: -1";
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return  sucesso;
}

void Buscas::imprimeFuncao(Estado* solucao){
    int funcao= 0;
    Estado* p = solucao;

    while (p != NULL) {
        funcao += p->getFuncao();
        p= p->getPai();
    }

    cout<< "Custo da Funcao: "<<funcao<<endl;
}

void Buscas::calculaFuncao(Estado *candidato) {
    candidato->setFuncao(candidato->getCusto() + candidato->getHeuristica());
}

bool Buscas:: A() {
    bool sucesso = false;
    Lista *abertos = new Lista;
    Lista *fechados = new Lista;
    Estado *pai = new Estado(qntJarros);
    calculaHeuristica(pai);
    Estado *candidato;
    abertos->insereOrdenadoFuncao(pai);
    while (!sucesso && !abertos->ehVazio()) {
        pai = abertos->getPrimeiro();
        candidato = criaCandidato(pai);
        abertos->remove();
        fechados->insere(pai);
        if (ehSolucao(candidato)) {
            sucesso = true;
        } else {
            while (pai->getOperacao() < qntOperacoes) {
                if (enche(candidato, pai) || permutacao2a2(candidato, pai) ||
                    esvazia(candidato, pai)) {
                    candidato->setPai(pai);
                    calculaHeuristica(candidato);
                    calculaFuncao(candidato);
                    abertos->insereOrdenadoFuncao(candidato);
                    candidato = criaCandidato(pai);
                }
            }
        }

    }
    fechados->imprime();
    imprimeFuncao(pai);
    cout << "Abertos: " <<abertos->getTam()<<endl;
    cout << "Fechado: " << fechados->getTam()<<endl;
    return  sucesso;
}


Estado *Buscas::criaCandidato(Estado *pai) {
    Estado *candidato = new Estado(qntJarros);
    for (int i = 0; i < qntJarros; i++) {
        candidato->setVolumeJarro(i, pai->getVolumeJarro(i));
    }
    candidato->setCusto(pai->getCusto());
    return candidato;

}

void Buscas::criaCandidatos(Estado **candidatos) {
    for (int i = 0; i < qntOperacoes; i++) {
        candidatos[i] = NULL;
    }

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

bool Buscas::enche(Estado *candidato, Estado *pai) {

    for (int i = pai->getOperacao(); i < qntJarros; i++) {
        pai->addOperacao();
        if (pai->getVolumeJarro(i) < volumes[i]) {
            int aux = candidato->getVolumeJarro(i);
            candidato->setVolumeJarro(i, volumes[i]);
            if (!existeCandidato(candidato, pai)) {
                candidato->addCusto(pai->getOperacao());
                return true;
            }
            candidato->setVolumeJarro(i, aux);
        }
    }
    return false;
}


bool Buscas::permutacao2a2(Estado *candidato, Estado *pai) {

    std::vector<bool> v(qntJarros);
    std::fill(v.end() - 2, v.end(), true);

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
            if (transferirVolumeAux(candidato, pai, i - j, j)) {
                candidato->addCusto(pai->getOperacao());
                return true;
            }
            if (transferirVolumeAux(candidato, pai, j, i - j)) {
                candidato->addCusto(pai->getOperacao() + 1 );
                return true;
            }
        }
        count++;
    } while (next_permutation(v.begin(), v.end()));


    return false;

}

bool Buscas::esvazia(Estado *candidato, Estado *pai) {
    for (int i = pai->getOperacao() - (qntJarros + numPermutacoes); i < qntJarros; i++) {
        pai->addOperacao();
        if (pai->getVolumeJarro(i) > 0) {
            int aux = candidato->getVolumeJarro(i);
            candidato->setVolumeJarro(i, 0);
            if (!existeCandidato(candidato, pai)) {
                candidato->addCusto(pai->getOperacao());
                return true;
            }
            candidato->setVolumeJarro(i, aux);
        }
    }
    return false;


}

bool Buscas::transferirVolumeAux(Estado *candidato, Estado *pai, int i, int j) {
    int auxI = candidato->getVolumeJarro(i);
    int auxJ = candidato->getVolumeJarro(j);
    transferirVolume(candidato, i, j);

    if (existeCandidato(candidato, pai) ||
        (candidato->getVolumeJarro(i) == auxI && candidato->getVolumeJarro(j) == auxJ)) {
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


bool Buscas::existeCandidato(Estado *candidato, Estado *pai) {

    Estado *aux = pai;
    int i;
    while (aux != NULL) {
        for (i = 0; i < qntJarros; i++) {
            if (aux->getVolumeJarro(i) != candidato->getVolumeJarro(i)) {
                break;
            }
        }
        if (i == qntJarros) return true;
        aux = aux->getPai();
    }
    return false;


}