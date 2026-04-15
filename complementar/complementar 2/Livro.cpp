/*
Crie uma classe Livro com atributos título, autor e ano. Implemente construtores que
aceitem diferentes combinações de parâmetros (com e sem ano). Em C++, use o destrutor
para exibir uma mensagem de desalocação.
O que deve ser feito:

• Construtor padrão e construtor com parâmetros
• Em C++: destrutor que imprime mensagem ao sair de escopo
• Criar um vetor/lista de livros e observar a ordem de destruição
*/

#include <iostream>
#include <string>
using namespace std;

class Livro {
    private:
        string titulo;
        string autor;
        int ano;

    public:
        // Construtor Padrão
        Livro() {
            this->titulo = "Sem Titulo";
            this->autor = "Desconhecido";
            this->ano = 0;
        }

        // Construtor com 3 parâmetros
        Livro(string titulo, string autor, int ano) {
            this->titulo = titulo;
            this->autor = autor;
            this->ano = ano;
        }

        // Construtor com 2 parâmetros (sem ano)
        Livro(string titulo, string autor) {
            this->titulo = titulo;
            this->autor = autor;
            this->ano = 0; // Ano padrão quando não informado
        }

        // Getters
        string getTitulo() { return titulo; }
        string getAutor() { return autor; }
        int getAno() { return ano; }

        // Setters
        void setTitulo(string titulo) {
            this->titulo = titulo;
        }

        void setAutor(string autor) {
            this->autor = autor;
        }

        void setAno(int ano) {
            this->ano = ano;
        }

        // Destrutor
        ~Livro() {
            cout << "Livro '" << titulo << "' foi apagado!" << endl;
        }
}; 

int main() {  
    cout << "Criando a lista de livros...\n" << endl;
    
    // Criando um vetor de livros
    Livro lista_livros[5] = {
        {"Magia Negra", "Julio", 1500},
        {"Obras Arcanas", "Turquia", 1600},
        {"Abra Cadabra", "Pedro", 1800},
        {}, // Chama o construtor padrão
        {"Magia Fundamental", "Artus"} // Chama o construtor sem ano
    };
    
    cout << "\nSaindo da main. Os destrutores serao chamados agora:\n" << endl;
    
    return 0;
}