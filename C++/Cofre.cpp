#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Cofre {
private:
    const string CODIGO_MASTER = "MASTER2024";

    string combinacao;
    vector<string> conteudo;
    bool aberto;
    int tentativas_erradas;
    bool bloqueado;

    // ── Métodos privados ──────────────────────────────────────────────────
    bool verificar_acesso() const {
        if (bloqueado) {
            cout << "Acesso negado: cofre bloqueado permanentemente. Chame um tecnico." << endl;
            return false;
        }
        if (!aberto) {
            cout << "Acesso negado: o cofre esta fechado." << endl;
            return false;
        }
        return true;
    }

public:
    Cofre(const string& combinacao)
        : combinacao(combinacao), aberto(false),
          tentativas_erradas(0), bloqueado(false) {}

    // ── Métodos públicos ──────────────────────────────────────────────────
    void abrir(const string& comb) {
        if (bloqueado) {
            cout << "Cofre bloqueado! Intervencao tecnica necessaria." << endl;
            return;
        }
        if (aberto) {
            cout << "O cofre ja esta aberto." << endl;
            return;
        }
        if (comb == combinacao) {
            aberto = true;
            tentativas_erradas = 0;
            cout << "Cofre aberto com sucesso." << endl;
        } else {
            tentativas_erradas++;
            int restantes = 3 - tentativas_erradas;
            cout << "Combinacao incorreta! Tentativas restantes: " << restantes << "." << endl;
            if (tentativas_erradas >= 3) {
                bloqueado = true;
                cout << "ALERTA: Cofre bloqueado apos 3 tentativas erradas!" << endl;
            }
        }
    }

    void fechar() {
        if (!aberto) {
            cout << "O cofre ja esta fechado." << endl;
            return;
        }
        aberto = false;
        cout << "Cofre fechado." << endl;
    }

    void guardar(const string& item) {
        if (!verificar_acesso()) return;
        conteudo.push_back(item);
        cout << "Item '" << item << "' guardado no cofre." << endl;
    }

    void retirar(const string& item) {
        if (!verificar_acesso()) return;
        auto it = find(conteudo.begin(), conteudo.end(), item);
        if (it != conteudo.end()) {
            conteudo.erase(it);
            cout << "Item '" << item << "' retirado do cofre." << endl;
        } else {
            cout << "Item '" << item << "' nao encontrado no cofre." << endl;
        }
    }

    void listar_conteudo() const {
        if (!verificar_acesso()) return;
        if (conteudo.empty()) {
            cout << "O cofre esta vazio." << endl;
        } else {
            cout << "Conteudo do cofre:" << endl;
            for (const string& item : conteudo)
                cout << "  - " << item << endl;
        }
    }

    bool esta_bloqueado() const {
        return bloqueado;
    }

    void resetar_bloqueio(const string& codigo_master) {
        if (codigo_master == CODIGO_MASTER) {
            bloqueado = false;
            tentativas_erradas = 0;
            aberto = false;
            cout << "Bloqueio removido pelo tecnico. Cofre pronto para uso." << endl;
        } else {
            cout << "Codigo master incorreto. Operacao negada." << endl;
        }
    }
};

int main() {
    Cofre cofre("1234");

    // Tentativas erradas → bloqueio
    cout << "=== Testando bloqueio ===" << endl;
    cofre.abrir("0000");
    cofre.abrir("9999");
    cofre.abrir("1111");          // 3ª falha → bloqueia

    cout << "Bloqueado? " << (cofre.esta_bloqueado() ? "Sim" : "Nao") << endl;
    cofre.abrir("1234");          // bloqueado, não abre

    // Intervenção técnica
    cout << "\n=== Intervencao tecnica ===" << endl;
    cofre.resetar_bloqueio("ERRADO");
    cofre.resetar_bloqueio("MASTER2024");

    // Uso normal
    cout << "\n=== Uso normal ===" << endl;
    cofre.abrir("1234");
    cofre.guardar("Passaporte");
    cofre.guardar("Joias");
    cofre.guardar("Dinheiro");
    cofre.listar_conteudo();
    cofre.retirar("Joias");
    cofre.retirar("Laptop");      // item inexistente
    cofre.listar_conteudo();
    cofre.fechar();
    cofre.guardar("Documento");   // cofre fechado
    cofre.fechar();               // já está fechado

    // Tentativa de acesso direto: não compila
    // cout << cofre.conteudo.size();    // erro: 'conteudo' is private
    // cout << cofre.combinacao;         // erro: 'combinacao' is private

    return 0;
}