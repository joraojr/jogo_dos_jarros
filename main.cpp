#include <iostream>
#include "Estado.h"
#include "Buscas.h"
using namespace std;


int main() {
    //Estado *estado = new Estado(3);
    int tam = 3;
    int vol[tam] = {3,6,4};
    int obj[tam] = {0,3,1};
    Buscas *b = new Buscas(vol, obj, tam);
    clock_t Ticks[2];

    Ticks[0] = clock();
     cout << b->backtraking();
//     cout << b->profundidade();
//     cout << b->largura();
//     cout <<b->ordenada();
//     cout << b->gulosa();
//    cout<<b->A();
    Ticks[1] = clock();

    double tempo = (Ticks[1] -Ticks[0])/CLOCKS_PER_SEC;
    cout<<endl<< "Tempo: "<<tempo<<" ms";



    return 0;
}