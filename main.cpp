#include <iostream>
#include "Estado.h"
#include "Buscas.h"
using namespace std;

void imprime(Buscas *b, int tam){
    for(int i = 0 ; i< tam ; i ++){
        cout << "-" << b->getEstadoAtual(i) << "-";
    }
    cout<<endl;

}
int main() {
    //Estado *estado = new Estado(3);
    int tam = 3;
    int vol[tam] = {1,2,1};
    int obj[tam] = {0,2,1};
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
//   cout << b->profundidade();
 //  cout << b->backtraking();

    cout << b->largura();





    return 0;
}