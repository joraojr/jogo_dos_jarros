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
    int vol[3] = {2,3,1};
    Buscas *b = new Buscas(vol,vol,tam);

    b->addVolume(1);
    b->transferirVolume(1,0);
    imprime(b,tam);
    b->transferirVolume(0,2);
    imprime(b,tam);
    b->transferirVolume(2,0);
    imprime(b,tam);
    b->transferirVolume(0,1);
    imprime(b,tam);




    return 0;
}