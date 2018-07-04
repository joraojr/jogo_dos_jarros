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
    cout << "Back" << endl;
    cout << b->backtraking();
    cout << endl;
    cout << "Prof" << endl;
    cout << b->profundidade();
    cout << endl;
    cout << "Larg" << endl;
    cout << b->largura();
    cout << endl;
    cout << "Ordenada" << endl;
    cout << b->ordenada();
    cout << endl;
    cout << "Gulosa" << endl;
    cout << b->gulosa();
    cout << endl;
    cout << "A*" << endl;
    cout << b->A();
    cout << endl;
    cout << "IDA*" << endl;
    cout << b->IDA();
    cout<<endl;
/*
    cout << "Sucesso: " <<b->ordenada();
*/
    Ticks[0] = clock();

    //    cout << "Sucesso: " <<b->gulosa();
    //   cout<<b->backtraking()
    Ticks[1] = clock();

    double tempo = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    cout << endl << "Tempo: " << tempo << " ms";


    return 0;
}