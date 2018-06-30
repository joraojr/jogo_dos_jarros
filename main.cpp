#include <iostream>
#include "Estado.h"
#include "Buscas.h"
using namespace std;


int main() {
    //Estado *estado = new Estado(3);
    int tam = 2;
    int vol[tam] = {3,4};
    int obj[tam] = {0,2};
    Buscas *b = new Buscas(vol, obj, tam);
    // b->permutacao2a2();
    /*  b->addVolume(1);
      b->transferirVolume(1,0);
      imprime(b,tam);
      b->transferirVolume(0,2);
      imprime(b,tam);
      b->transferirVolume(2,0);
      imprime(b,tam);
      b->transferirVolume(0,1);
      imprime(b,tam);
  */
//    cout << b->profundidade();
   //cout << b->backtraking();

    cout << b->largura();





    return 0;
}