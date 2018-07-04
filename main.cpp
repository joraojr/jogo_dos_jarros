#include <iostream>
#include "Estado.h"
#include "Buscas.h"
using namespace std;


int main() {
    //Estado *estado = new Estado(3);
    int tam = 2;
    int vol[tam] = {3,4};
    int obj[tam] = {2,0};

    Buscas *b = new Buscas(vol, obj, tam);
    clock_t Ticks[2];

//     cout << b->backtraking();
//     cout << b->profundidade();
//     cout << b->largura();
/*
    cout << "Sucesso: " <<b->ordenada();
*/
    double tempo = (Ticks[1] -Ticks[0])/CLOCKS_PER_SEC;
    Ticks[0] = clock();

    //    cout << "Sucesso: " <<b->gulosa();
    cout<<b->IDA();
    Ticks[1] = clock();

     tempo = (Ticks[1] -Ticks[0])/CLOCKS_PER_SEC;
    cout<<endl<< "Tempo: "<<tempo<<" ms";



    return 0;
}