#include <iostream>
#include <string>
using namespace std;

class TV {

public:
    // --- Atributos ---
    string marca;
    string modelo;
    bool estaLigada;
    int volume;
    bool estaMutada;
    int canal;
    int canalAnterior;

    // --- Construtor ---
    TV(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        estaLigada = false;
        volume = 10;
        estaMutada = false;
        canal = 1;
        canalAnterior = 1;
    }

    // Liga a TV
    void ligar() {
        if (!estaLigada) {
            estaLigada = true;
            cout << "TV ligada." << endl;
        } else {
            cout << "TV já está ligada." << endl;
        }
    }

    // Desliga a TV
    void desligar() {
        if (estaLigada) {
            estaLigada = false;
            cout << "TV desligada." << endl;
        } else {
            cout << "TV já está desligada." << endl;
        }
    }

    // Aumenta o volume (máximo 100)
    void aumentarVolume() {
        if (volume < 100) {
            volume++;
            cout << "Volume: " << volume << endl;
        } else {
            cout << "Volume já está no máximo." << endl;
        }
    }

    // Diminui o volume (mínimo 0)
    void diminuirVolume() {
        if (volume > 0) {
            volume--;
            cout << "Volume: " << volume << endl;
        } else {
            cout << "Volume já está no mínimo." << endl;
        }
    }

    // Muta o som
    void mutar() {
        estaMutada = true;
        cout << "TV mutada." << endl;
    }

    // Desmuta o som
    void desmutar() {
        estaMutada = false;
        cout << "TV desmutada." << endl;
    }

    // Vai para o próximo canal
    void proximoCanal() {
        canalAnterior = canal;
        canal++;
        cout << "Canal: " << canal << endl;
    }

    // Volta para o canal anterior
    void voltarCanal() {
        int temp = canal;
        canal = canalAnterior;
        canalAnterior = temp;
        cout << "Canal: " << canal << endl;
    }

    // Acessa um canal específico
    void acessarCanal(int numeroCanal) {
        if (numeroCanal >= 1) {
            canalAnterior = canal;
            canal = numeroCanal;
            cout << "Canal: " << canal << endl;
        } else {
            cout << "Canal inválido." << endl;
        }
    }

    // Exibe o status atual da TV
    void exibirStatus() {
        cout << "--- Status da TV ---" << endl;
        cout << "Marca   : " << marca << endl;
        cout << "Modelo  : " << modelo << endl;
        cout << "Ligada  : " << (estaLigada ? "Sim" : "Não") << endl;
        cout << "Canal   : " << canal << endl;
        cout << "Volume  : " << volume << endl;
        cout << "Mutada  : " << (estaMutada ? "Sim" : "Não") << endl;
    }
};

int main() {
    TV tv("Samsung", "Crystal 4K");

    tv.ligar();
    tv.exibirStatus();

    cout << endl;
    tv.acessarCanal(5);
    tv.aumentarVolume();
    tv.aumentarVolume();
    tv.mutar();
    tv.desmutar();
    tv.proximoCanal();
    tv.voltarCanal();

    cout << endl;
    tv.exibirStatus();

    tv.desligar();
    return 0;
}