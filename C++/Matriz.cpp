#include <iostream>
#include <stdexcept>

class Matriz {
public:
    // ── Construtor ──────────────────────────────────────────────
    Matriz(int linhas, int colunas)
        : linhas_(linhas), colunas_(colunas)
    {
        if (linhas <= 0 || colunas <= 0)
            throw std::invalid_argument("Dimensões devem ser positivas.");

        dados_ = new int*[linhas_];
        for (int i = 0; i < linhas_; ++i) {
            dados_[i] = new int[colunas_]();   // () → inicializa com 0
        }
    }

    // ── Construtor de cópia ────────────────────
    Matriz(const Matriz& outra)
        : linhas_(outra.linhas_), colunas_(outra.colunas_)
    {
        dados_ = new int*[linhas_];
        for (int i = 0; i < linhas_; ++i) {
            dados_[i] = new int[colunas_];
            for (int j = 0; j < colunas_; ++j)
                dados_[i][j] = outra.dados_[i][j];   
        }
    }

    // ── Operador de atribuição (Regra dos Três) ──────────────────
    Matriz& operator=(const Matriz& outra) {
        if (this == &outra) return *this;   // autoatribuição

        liberar();   // libera memória atual

        linhas_   = outra.linhas_;
        colunas_  = outra.colunas_;
        dados_ = new int*[linhas_];
        for (int i = 0; i < linhas_; ++i) {
            dados_[i] = new int[colunas_];
            for (int j = 0; j < colunas_; ++j)
                dados_[i][j] = outra.dados_[i][j];
        }
        return *this;
    }

    // ── Destrutor ────────────────────────────────────────────────
    ~Matriz() {
        liberar();
    }

    // ── Interface pública ────────────────────────────────────────
    int& at(int i, int j) {
        return dados_[i][j];
    }

    int at(int i, int j) const {
        return dados_[i][j];
    }

    void imprimir(const std::string& nome) const {
        std::cout << nome << ":\n";
        for (int i = 0; i < linhas_; ++i) {
            for (int j = 0; j < colunas_; ++j)
                std::cout << dados_[i][j] << "\t";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

private:
    int   linhas_;
    int   colunas_;
    int** dados_;

    void liberar() {
        for (int i = 0; i < linhas_; ++i)
            delete[] dados_[i];
        delete[] dados_;
        dados_ = nullptr;
    }
};

// ── main ─────────────────────────────────────────────────────────
int main() {
    Matriz original(2, 3);
    original.at(0, 0) = 1;
    original.at(0, 1) = 2;
    original.at(0, 2) = 3;
    original.at(1, 0) = 4;
    original.at(1, 1) = 5;
    original.at(1, 2) = 6;

    Matriz copia(original);        // invoca construtor de cópia

    copia.at(0, 0) = 99;
    copia.at(1, 2) = 77;

    original.imprimir("original (não deve mudar)");
    copia.imprimir("copia (modificada)");

    return 0;
}