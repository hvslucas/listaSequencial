#include <iostream>
using namespace std;

const int MAX = 5000;


class ListaSequencial{
    private:
        int tamanho;
        int array[MAX];
        
    public:

    // 1
        ListaSequencial() {
            this->tamanho = 0;
        };

    // 2
        bool estaVazia(){
            return tamanho == 0;
        };
    // 3
        bool estaCheia(){
            return tamanho == MAX;
        };

    // 4
        int obterTamanho(){
            return tamanho;
        };
    // 5
        int obterValor(int indice){
            if(indice < 1 || indice > tamanho) {
                cout << "Indice invalido" << endl;
                return -1;
            }
            return array[indice - 1];
        };

        void modificarValor(int indice, int valor) {
            if(indice < 1 || indice > tamanho) {
                cout << "Indice invalido" << endl;
                return;
            }
            array[indice - 1] = valor;
        };
    // 6
        void inserirValor(int indice, int valor){
            if(indice < 1 || indice > tamanho + 1 || estaCheia()) {
                cout << "Operacao invalida" << endl;
                return;
            }

            for(int i = tamanho; i >= indice; i--){
                array[i] = array[i-1];
            }
            tamanho++;
            modificarValor(indice, valor);
        };
    // 7
        int retirarValor(int indice) {
            if(indice < 1 || indice > tamanho) {
                cout << "Operacao invalida" << endl;
                return -1;
            }

            int valor = array[indice-1];
            for(int i = indice - 1; i < tamanho; i++){
                array[i] = array[i + 1];
            }
            tamanho--;
            return valor;
        };

    // imprimir lista

        void imprimir(){
            for(int i = 0; i < tamanho; i++)
                cout << array[i] << " ";
            cout << endl;
        };

};