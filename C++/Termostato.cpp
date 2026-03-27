#include <iostream>
using namespace std; // estava faltando isso

class Termostato
{
private:
    int temperatura;
    bool ligado;
    const int MAX = 40;
    const int MIN = 0;

    // CORREÇÃO: a lógica estava invertida
    // retorna true se for VÁLIDO, false se estiver fora dos limites
    bool validar_Temperatura(int valor){
        if (valor < MIN || valor > MAX)
        {
            cout << "Aviso: Temperatura fora dos limites permitidos (0 a 40)!" << endl;
            return false; // inválido
        }
        return true; // válido
    }

public:

    // CORREÇÃO: construtor ignorava os parâmetros e usava os nomes errados
    // this-> é necessário para diferenciar atributo do parâmetro
    Termostato(){
        this->temperatura = 20; // inicia em 20 conforme o enunciado
        this->ligado = false;
    }

    // CORREÇÃO: destrutor não precisa de ponto e vírgula e pode ficar vazio
    ~Termostato(){}

    void ligar(){
        ligado = true;
    }

    void desligar(){
        ligado = false;
    }

    // CORREÇÃO: aumentar/diminuir recebem graus como parâmetro, conforme o enunciado
    void aumentar(int graus){
        if (!ligado){
            cout << "Aviso: Termostato desligado!" << endl;
            return;
        }

        int nova_temp = temperatura + graus;

        // CORREÇÃO: valida a nova temperatura ANTES de aplicar
        if (validar_Temperatura(nova_temp)){
            temperatura = nova_temp;
        }
    }

    void diminuir(int graus){
        if (!ligado){
            cout << "Aviso: Termostato desligado!" << endl;
            return;
        }

        int nova_temp = temperatura - graus;

        // CORREÇÃO: valida a nova temperatura ANTES de aplicar
        if (validar_Temperatura(nova_temp)){
            temperatura = nova_temp;
        }
    }

    void exibir_estado(){
        cout << "Ligado: " << (ligado ? "Sim" : "Nao") << endl;
        cout << "Temperatura: " << temperatura << "°C" << endl;
    }
};

int main()
{
    Termostato ar; // CORREÇÃO: construtor sem argumentos, não precisa passar nada

    // CORREÇÃO: faltavam os () em todas as chamadas de método
    ar.ligar();
    ar.exibir_estado();
    ar.aumentar(5);
    ar.aumentar(5);
    ar.exibir_estado();
    ar.diminuir(3);
    ar.exibir_estado();
    ar.desligar();
    ar.diminuir(3); // deve exibir aviso pois está desligado
    ar.exibir_estado();

    return 0;
}