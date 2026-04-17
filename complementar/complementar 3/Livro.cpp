/*
Parte 1: Classe Base
Crie uma classe base chamada Livro, contendo os seguintes atributos:
• chave (int)
• titulo (string)
• autor (string)
• ano (int)
Requisitos:
• Implementar:
– Construtor com parˆametros (t´ıtulo, autor, ano, obs: a chave deve ser um
n´umero inteiro incremental, ou seja, se o ´ultimo livro cadastrado foi o 88,
o pr´oximo ser´a o 89- logo n˜ao precisa ser fornecida o pr´oprio sistema deve
controlar isso)
• Em C++:
– Implementar o destrutor (~Livro()) que imprime uma mensagem indicando que
o objeto foi desalocado
*/

/*
#include<iostream>
#include<string>
using namespace std;


class Livro
{
    private:
    string titulo;
    string autor;
    int ano;
    static int chave;

    public:

        Livro(){
            titulo = "desconhecido";
            autor = "desconhecido";
            ano = 0;
            chave++;
        };

        Livro(string titulo,string autor,int ano){
            this->titulo=titulo;
            this->autor=autor;
            this->ano=ano;
            chave++;
        };

        ~Livro(){
            cout <<"O objeto '" << chave << "' foi apagado" <<endl;
            chave--;
        };

        static int getChave(){return chave;}

};

int Livro::chave = 0;

int main()
{
    Livro livro;
    for (size_t i = 0; i < 5; i++)
    {
        livro = Livro();
    }
    return 0;
}

*/


/*
Parte 2: Heran¸ca
Crie duas classes derivadas da classe Livro:
a) Classe LivroFisico
Adicione o atributo:
• numeroPaginas (int)
Requisitos:
• Construtor que utilize o construtor da classe base
• M´etodo para exibir as informa¸c˜oes completas do livro
b) Classe LivroDigital
Adicione os atributos:
• tamanhoArquivo (float, em MB)
• formato (string, ex: PDF, EPUB)
Requisitos:
• Construtor utilizando heran¸ca
• M´etodo para exibir os dados completos
*/

#include<iostream>
#include<string>
using namespace std;


class Livro
{
    private:
    string titulo;
    string autor;
    int ano;
    static int chave;

    public:

        Livro(){
            titulo = "desconhecido";
            autor = "desconhecido";
            ano = 0;
            chave++;
        };

        Livro(string titulo,string autor,int ano){
            this->titulo=titulo;
            this->autor=autor;
            this->ano=ano;
            chave++;
        };

        ~Livro(){
            cout <<"O objeto '" << chave << "' foi apagado" <<endl;
            chave--;
        };

        static int getChave(){return chave;}

};

int Livro::chave = 0;

int main()
{
    Livro livro;
    for (size_t i = 0; i < 5; i++)
    {
        livro = Livro();
    }
    return 0;
}
