#include <iostream>
#include "classes.cpp"
using namespace std;

// PRECISO TIRAR OS WHILE DAS RESCURSÕES DOS MÉTODOS caminha_esq_dir() e caminhar pelas sub-árvores somente com a recursão.
// esses whiles estão fazendo a recursão se tornar infinita e o programa travar
int main(){
    int valor_no;
    Elemento arvoreAVL(24);
    while(valor_no != -1){
        cout << "Digite um número para adicionar na árvore: ";
        cin >> valor_no;
        if(valor_no != -1)
            arvoreAVL.inserir(valor_no);
            
    }
    arvoreAVL.imprime_arvore(&arvoreAVL);

    return 0;
}