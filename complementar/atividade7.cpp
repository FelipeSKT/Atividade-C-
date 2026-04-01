/*
7. Defina uma classe Conjunto, que mantém o controle de uma coleção de objetos distintos. Internamente, use uma lista como uma variável de controle, mas sem permitir valores
duplicados em seu conteúdo. A seguinte sugestão de design pode ser adotada:
O método para adicionar elementos deve inserir o elemento no conjunto se ele não existir.
O método para remover deve remover um elemento apenas se ele existir no conjunto. O
2
método pesquisar retorna True/False se o elemento existe ou não dentro do conjunto. Obs:
Faça em ambas as linguagens (Python e C++).

*/

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>

class Conjunto {
    private:
        list<T> elementos;

    public:
        // Insere o elemento apenas se não existir no conjunto
        void adicionar(const T& elemento) {
            if (!pesquisar(elemento)) {
                elementos.push_back(elemento);
                cout << "[+] Elemento adicionado ao conjunto.\n";
            } else {
                cout << "[!] Elemento ja existe. Duplicata ignorada.\n";
            }
        }

        // Remove o elemento apenas se existir no conjunto
        void remover(const T& elemento) {
            if (pesquisar(elemento)) {
                elementos.remove(elemento);
                cout << "[-] Elemento removido do conjunto.\n";
            } else {
                cout << "[!] Elemento nao encontrado no conjunto.\n";
            }
        }

        // Retorna true se o elemento existir, false caso contrário
        bool pesquisar(const T& elemento) const {
            return find(elementos.begin(), elementos.end(), elemento)
                != elementos.end();
        }

        // Retorna a quantidade de elementos
        size_t tamanho() const {
            return elementos.size();
        }

        // Exibe todos os elementos
        void exibir() const {
            cout << "Conjunto { ";
            for (const auto& e : elementos)
                cout << e << " ";
            cout << "}\n";
        }
};

// ── Demonstração ──────────────────────────────────────────────
int main() {
    Conjunto<int> c;

    c.adicionar(10);
    c.adicionar(20);
    c.adicionar(30);
    c.adicionar(20);           // duplicata → ignorada

    c.exibir();                // Conjunto { 10 20 30 }
    cout << "Tamanho: " << c.tamanho() << "\n";

    cout << "Pesquisar 20: " << (c.pesquisar(20) ? "true" : "false") << "\n"; // true
    cout << "Pesquisar 99: " << (c.pesquisar(99) ? "true" : "false") << "\n"; // false

    c.remover(20);
    c.remover(99);             // não existe → aviso

    c.exibir();                // Conjunto { 10 30 }

    // Testando com strings
    cout << "\n--- Conjunto de strings ---\n";
    Conjunto<string> cs;
    cs.adicionar("alpha");
    cs.adicionar("beta");
    cs.adicionar("alpha");     // duplicata
    cs.exibir();

    return 0;
}