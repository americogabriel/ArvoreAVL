#include <iostream>
#include <algorithm>
using namespace std;

class Elemento{
    public:
        int valor; // valor guardado no nó
        Elemento * esq; // filho da esquerda
        Elemento * dir; // filho da direita
    private:
        int fator_balanceamento; // fator de balanceamento daquele nó
        public:
            Elemento(int valor){
                this->valor = valor;
                this->dir = NULL;
                this->esq = NULL;
                this->fator_balanceamento = 0;
            }

            void imprime_arvore(Elemento * arvore){
                if(arvore == NULL){
                    return; // se a árvore estiver vazia, a função é finalizada
                }
                cout << arvore->valor << endl; // printa o nó atual
                // se tiver nó à direita
                if(arvore->dir != NULL){
                    cout << "direita:"; // printa um ligamento só para melhorar a representação entre os nós
                    imprime_arvore(arvore->dir); // faz uma recurssão para printar o filho da direita e depois a sub-árvore do filho a direita até a folha da direita
                }
                // se tiver nó à esquerda
                if(arvore->esq != NULL){
                    cout << "esquerda: ";// printa um ligamento só para melhorar a representação entre os nós
                    imprime_arvore(arvore->esq); // faz uma recurssão para printar o filho da esquerda e depois a sub-árvore do filho a esquerda até a folha desta sub-árvore
                }
            }

            // método para caminhar sub-árvores da esquerda e direita para inserção de valores 
            void caminha_esq_dir(Elemento * no,int valor){

                // se o valor a ser adicionado for menor que o valor do nó
                if(valor < no->valor){ 
                    // verifica se o nó tem algum filho a esquerda, se tiver, roda o while até o nó folha
                    while(no->esq != NULL){
                        no = no->esq;
                        caminha_esq_dir(no,valor);
                    }
                    // após já estarmos no último nó da esquerda, verificamos se o valor a ser adicionado é maior ou menor que ele
                    if(valor >= no->valor){ // se maior
                        if(no->dir == NULL){ // se não tiver filho a direita
                            no->dir = new Elemento(valor);
                            return;
                        }
                        else{ // se tiver
                            caminha_esq_dir(no,valor); // caminha pela sub-árvore a direita até achar o lugar de adicionar o valor
                        }
                    }
                    else{ // se menor adiciona à esquerda
                        no->esq = new Elemento(valor);
                    }
                }
                //  se o valor a ser adicionado for maior ou igual ao valor do nó
                else{ 
                    while(no->dir != NULL){
                        no = no->dir;
                        caminha_esq_dir(no,valor);
                    }
                    // após já estarmos no último nó da direita, verificamos se o valor a ser adicionado é maior ou menor que ele 
                    if(valor >= no->valor){ // se maior adiciona a direita
                        no->dir = new Elemento(valor); 
                    }
                    else{ // se menor adiciona a esquerda
                        if(no->esq == NULL){ // se não tiver filho a esquerda
                            no->esq = new Elemento(valor);
                        }
                        else{ // se tiver
                            caminha_esq_dir(no,valor); // caminha a sub-árvora da esquerda até achar o lugar de adicionar o valor
                        }
                    }
                }
            }

            // método para inserir um Elemento(novo nó na árvore)
            void inserir(int valor){
                if(dir == NULL && esq == NULL){
                    if(valor < this->valor){ // se o valor a ser adicionado é menor que o valor da raiz
                        esq = new Elemento(valor); // aloca no ponteiro do filho à esquerda da raiz o valor digitado pelo usuário
                        
                    }
                    else{ // se o valor for maior ou igual a raiz
                        dir = new Elemento(valor); // aloca no ponteiro do filho à direita da raiz o valor digitado pelo usuário
                        
                    }
                }
                else if(dir != NULL || esq != NULL){
                    if(valor >= this->valor){ // se o valor a ser adicionado for maior ou igual ao valor da raiz
                        if(dir != NULL){// se existir um filho à direita da raiz
                            caminha_esq_dir(dir,valor); // chama o método, para percorrer a sub-árvore direita
                        }
                        else{ // se não existir filho à direita
                            dir = new Elemento(valor); //aloca no ponteiro do filho à direita da raiz o valor digitado pelo usuário
                        }
                    }
                    else{ // se o valor a ser adicionado for menor ou igual ao valor da raiz
                        if(esq != NULL){ // se existir um filho à esquerda da raiz
                            caminha_esq_dir(esq,valor); // chama o método, para percorrer a sub-árvore esquerda
                        }
                        else{ // se não existir filho à esquerda
                            esq = new Elemento(valor); //aloca no ponteiro do filho à esquerda da raiz o valor digitado pelo usuário
                        }
                    }
                    
                }
            }

};
