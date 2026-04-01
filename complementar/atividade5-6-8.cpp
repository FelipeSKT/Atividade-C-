/*
5. Nosso design de Televisão (código da aula) é feito de maneira que a informação atual
é mantida, mesmo que o aparelho seja desligado. Assim, quando ela é ligado novamente,
as configurações de volume, canal, e mute continuam como estavam. Entretanto, muitas
televisões reais tem um comportamento diferente: mesmo que estivessem mutadas quando
foram desligadas, quando são ligadas novamente o volume não está mais mutado. Altere os
métodos e funções da implementação de Televisão para adotar esse comportamento. Obs:
Faça em ambas as linguagens (Python e C++).
*/

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
    int canaisFavoritos[10]={0};
    int favoritos;

    // --- Construtor ---
    TV(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        estaLigada = false;
        volume = 10;
        estaMutada = false;
        canal = 1;
        canalAnterior = 1;
        favoritos = 0;
    }

    // Liga a TV
    void ligar() {
        if (!estaLigada) {
            estaLigada = true;
            cout << "TV ligada." << endl;
            volume = 10;
            estaMutada = false;
            canal = 1;
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

    void resetFabrica(){
        volume = 10;
        estaMutada = false;
        canal = 1;
        cout <<"Configurações voltaram ao padrão de fabrica" <<endl;
    }

    void addFavorito(){
        if (favoritos == 10)
        {
            cout <<"Limite de canais favoritos alcançados, remover algum canal antes de proseguir" <<endl;
            return;
        }
        int posicao=0;
        for (size_t i = 10; i > 0; i--)
        {
             if (canaisFavoritos[i]==0)
             {
                posicao = i;
             }
        }

        canaisFavoritos[posicao] = canal;
        favoritos++;
        return;
    }

    void removeFavorito(){
        if (favoritos == 0){
            cout <<"não á canais favoritados"<<endl;
            return;
        }
        int posicao=0;
        for (size_t i = 10; i > 0; i--)
        {
             if (canal == canaisFavoritos[i])
             {
                posicao = i;
             }
        }
        if (posicao == 0)
        {
            cout <<"Esse canal não esta no seus favoritos"<<endl;
        }
        canaisFavoritos[posicao] = 0;
    }

    void jumpFavoritos(){
        if (favoritos == 0)
        {
            cout << "Não á canais favoritados" <<endl;
        }
        int candidato=0;
        for (size_t i = 0; i < 10; i++)
        {
             if (canaisFavoritos[i] > canal)
             {
                if (candidato == 0 || canaisFavoritos[i] < candidato)
                {
                    candidato = canaisFavoritos[i];
                }
                
             }
        }
        if (candidato == 0 )
        {
            candidato = canaisFavoritos[0];
            for (size_t i = 0; i < 10; i++)
            {
                if (canaisFavoritos[i] < candidato)
                {
                    candidato = canaisFavoritos[i];
                }
                
            }
            
        }
        canal = candidato;
        return;
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