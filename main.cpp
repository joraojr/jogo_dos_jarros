#include <iostream>
#include <time.h>
#include "Estado.h"
#include "Buscas.h"
using namespace std;





void telaEscolha()
{
    cout << "---------------------TELA INICIAL----------------------"<<endl;
    cout <<"1)Backtraking"<<endl;
    cout <<"2)Busca Largura"<<endl;
    cout <<"3)Busca Profundidade"<<endl;
    cout <<"4)Busca Ordenada"<<endl;
    cout <<"5)Busca Gulosa"<<endl;
    cout <<"6)Busca A*"<<endl;
    cout <<"7)Busca IDA*"<<endl;
    //cout <<"8)Alterar valores"<< endl;
    cout <<"8)SAIR"<<endl;
}


void backtraking(Buscas *b)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->backtraking();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}

void profundidade(Buscas *b)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->profundidade();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}

void largura(Buscas *b)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->largura();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}


void ordenada(Buscas *b)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->ordenada();
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}


void gulosa(Buscas *b, int valor)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->gulosa(valor);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}


void A(Buscas *b, int valor)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->A(valor);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}


void IDA(Buscas *b, int i)
{
    int voltar;
    clock_t Ticks[2];
    Ticks[0] = clock();
    bool encontrado = b->IDA(i);
    Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Tempode de execução: " << Tempo <<"ms"<< endl;
    if(encontrado)
    {
        cout << "Objetivo encontrado" << endl;
    }
    else
    {
        cout << "Objetivo não encontrado" << endl;
    }

    cout << "1)Voltar menu inivial"<<endl;

    cin >> voltar;
    switch ( voltar )
    {
        case 1:
            system("clear");
    }
}



void alterarValores(int *tam,int *volume,int *objetivo)
{






}
int main() {


    int tam, sair = 0, esco, euristica;


    cout << "DIgite 1 para usar a primeira heuristica e 2 para usar a segunda: ";

    cin >> euristica;


    cout << "Informa a quantidade de jarros: ";

    cin >> tam;
    //cout << string(50, '\n');

    int vol[tam];
    cout << "Informe o volume máximo dos jarros" << endl;
    for (int i = 0; i < tam; i++) {
        cout << i << ": ";
        cin >> vol[i];
    }
    system("clear");
    int obj[tam];
    cout << "Informe o objetivo" << endl;
    for (int i = 0; i < tam; i++) {
        cout << i << ": ";
        cin >> obj[i];
    }
    system("clear");





    telaEscolha();
    while (sair == 0) {
        cin >> esco;
        switch (esco) {
            case 1: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                backtraking(b);
                telaEscolha();
                break;
            }
            case 2: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                profundidade(b);
                telaEscolha();
                break;
            }
            case 3: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                largura(b);
                telaEscolha();
                break;
            }
            case 4: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                ordenada(b);
                telaEscolha();
                break;
            }
            case 5: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                gulosa(b, euristica);
                telaEscolha();
                break;
            }
            case 6: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                A(b, euristica);
                telaEscolha();
                break;
            }
            case 7: {
                Buscas *b = new Buscas(vol, obj, tam);
                system("clear");
                IDA(b, euristica);
                telaEscolha();
                break;
            }

            case 8:
                sair = 1;
                break;
        }
    }

    return 0;
}

