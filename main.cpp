#include <iostream>
#include "Estado.h"
#include "Buscas.h"

using namespace std;


int main() {
    //Estado *estado = new Estado(3);
    int tam = 2;
    int vol[tam] = {1, 3};
    int obj[tam] = {0, 1};

    Buscas *b = new Buscas(vol, obj, tam);
    clock_t Ticks[2];
    cout << "Backtraking" << endl;
    Ticks[0] = clock();
    cout <<"Sucesso: "<< b->backtraking();
    Ticks[1] = clock();
    double tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "Profundidade" << endl;
    cout <<"Sucesso: "<<b->profundidade();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "Largura" << endl;
    cout <<"Sucesso: "<< b->largura();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "Ordenada" << endl;
    cout <<"Sucesso: "<< b->ordenada();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "Gulosa" << endl;
    cout <<"Sucesso: "<< b->gulosa();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "A*" << endl;
    cout <<"Sucesso: "<< b->A();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl<<endl;

    Ticks[0] = clock();
    cout << "IDA*" << endl;
    cout <<"Sucesso: "<< b->IDA();
    Ticks[1] = clock();
    tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";
    cout << endl;



    return 0;
}