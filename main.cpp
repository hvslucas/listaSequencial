#include "ListaSequencial.cpp"
#include <fstream>

int main(int argc, char* argv[]) {
    
    // 1. Criação da lista vazia
    ListaSequencial lista;

    cout << "1. Lista criada." << endl;

    string nomeArquivo;

    if (argc > 1) {
        nomeArquivo = argv[1];
    } else {
        nomeArquivo = "dados.txt"; // padrão
    }

    // Tenta abrir o arquivo "dados.txt"
    ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        cout << "Arquivo dados.txt encontrado. Carregando lista a partir do arquivo..." << endl;
        int valor, pos = 1;
        while (arquivo >> valor) {
            lista.inserirValor(pos, valor);
            pos++;
        }
        arquivo.close();
        cout << "Lista carregada do arquivo: ";
        lista.imprimir();
    } else {
        cout << "Arquivo dados.txt NAO encontrado. Continuando com insercoes manuais..." << endl;

        // 2. Verificar se está vazia
        cout << "2. Lista esta vazia? " << (lista.estaVazia() ? "Sim" : "Nao") << endl;

        // 3. Verificar se está cheia
        cout << "3. Lista esta cheia? " << (lista.estaCheia() ? "Sim" : "Nao") << endl;

        // 6. Inserir elementos em posições diferentes
        lista.inserirValor(1, 10); // inserir no início
        lista.inserirValor(2, 20); // inserir no fim (posição 2)
        lista.inserirValor(2, 15); // inserir no meio (posição 2 agora)

        cout << "6. Elementos inseridos: ";
        lista.imprimir(); // Esperado: 10 15 20

        // 4. Obter o tamanho da lista
        cout << "4. Tamanho atual da lista: " << lista.obterTamanho() << endl;

        // 5. Obter e modificar valor de uma posição
        int valor = lista.obterValor(2); // Esperado: 15
        cout << "5. Valor na posicao 2: " << valor << endl;
        
        lista.modificarValor(2, 99);
        cout << "5. Valor na posicao 2 apos modificacao: " << lista.obterValor(2) << endl;
        
        // 7. Retirar um elemento de uma posicao
        int removido = lista.retirarValor(2); // Remove o 99
        cout << "7. Valor removido da posicao 2: " << removido << endl;
        
        cout << "Lista: ";
        lista.imprimir(); 
        
        lista.inserirValor(1, 5);    
        lista.inserirValor(4, 30);   
        lista.inserirValor(2, 7);    
        lista.inserirValor(3, 8);    
        lista.inserirValor(5, 25);  
        lista.inserirValor(6, 28); 
        lista.inserirValor(8, 35);   
        lista.inserirValor(9, 40);   

        cout << "Insercoes adicionais feitas." << endl;
        cout << "Lista final: ";
        lista.imprimir();

        cout << "Tamanho final: " << lista.obterTamanho() << endl;

        cout << "Tentando inserir na posicao 0 (invalida)..." << endl;
        lista.inserirValor(0, 999); // Deve exibir erro

        cout << "Lista final com operacao invalida ignorada: ";
        lista.imprimir(); // Lista permanece inalterada

        cout << "Tamanho final: " << lista.obterTamanho() << endl;
        return 0;
    }
}
