#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;
using namespace chrono;

class Cronometro {
private:

    steady_clock::time_point tempo_inicio;
    double tempo_total;   // segundos acumulados entre paradas
    bool rodando;

    // ── Métodos privados ──────────────────────────────────────────────────
    double tempo_decorrido() const {
        // Calcula o intervalo (em segundos) desde o último iniciar().
        duration<double> diff = steady_clock::now() - tempo_inicio;
        return diff.count();
    }

    void registrar_volta() const {
        // Exibe o tempo da volta atual sem parar a contagem.
        if (rodando) {
            cout << fixed << setprecision(2);
            cout << "Volta: " << tempo_decorrido() << "s" << endl;
        } else {
            cout << "Aviso: Cronômetro nao esta rodando." << endl;
        }
    }

public:
    Cronometro() : tempo_total(0.0), rodando(false) {}

    // ── Métodos públicos ──────────────────────────────────────────────────
    void iniciar() {
        if (rodando) {
            cout << "Aviso: Cronômetro ja esta rodando!" << endl;
            return;
        }
        tempo_inicio = steady_clock::now();
        rodando = true;
        cout << "Cronômetro iniciado." << endl;
    }

    void parar() {
        if (!rodando) {
            cout << "Aviso: Cronômetro ja esta parado!" << endl;
            return;
        }
        tempo_total += tempo_decorrido();
        rodando = false;
        cout << "Cronômetro parado." << endl;
    }

    void resetar() {
        tempo_total = 0.0;
        rodando = false;
        cout << "Cronômetro resetado." << endl;
    }

    void exibir_tempo() const {
        double total = rodando ? tempo_total + tempo_decorrido() : tempo_total;
        cout << fixed << setprecision(2);
        cout << "Tempo total: " << total << "s" << endl;
    }

    // Método público que aciona o registro de volta (acesso controlado).
    void volta() {
        registrar_volta();
    }
};

// Função auxiliar para sleep em milissegundos
void esperar(int ms) {
    this_thread::sleep_for(milliseconds(ms));
}

int main() {
    Cronometro c;

    c.iniciar();
    esperar(1500);
    c.volta();           // mostra tempo parcial sem parar
    esperar(1000);
    c.exibir_tempo();    // ~2.5s rodando
    c.parar();
    c.exibir_tempo();    // tempo acumulado

    cout << endl;
    c.iniciar();         // retoma contagem
    esperar(800);
    c.parar();
    c.exibir_tempo();    // ~3.3s no total

    cout << endl;
    c.parar();           // aviso: já está parado
    c.iniciar();
    c.iniciar();         // aviso: já está rodando
    c.parar();

    cout << endl;
    c.resetar();
    c.exibir_tempo();    // 0.00s após reset

    return 0;
}