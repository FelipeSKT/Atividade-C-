#include <fstream>
#include <string>
#include <stdexcept>
#include <ctime>

using namespace std;

class Logger {
public:
    explicit Logger(const string& caminho) {
        arquivo_.open(caminho, ios::app);
        if (!arquivo_.is_open())
            throw runtime_error("Não foi possível abrir: " + caminho);

        arquivo_ << "[" << timestamp() << "] === Sessão iniciada ===\n";
        arquivo_.flush();
    }

    Logger(const Logger&)            = delete;
    Logger& operator=(const Logger&) = delete;

    void registrar(const string& mensagem) {
        arquivo_ << "[" << timestamp() << "] " << mensagem << "\n";
        arquivo_.flush();
    }

    ~Logger() {
        if (arquivo_.is_open()) {
            arquivo_ << "[" << timestamp() << "] === Sessão encerrada ===\n";
            arquivo_.close();   
        }
    }

private:
    ofstream arquivo_;

    static string timestamp() {
        time_t agora = time(nullptr);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&agora));
        return buf;
    }
};


int main() {
    Logger logger("sessao.log");          
    logger.registrar("Aplicação iniciada.");
    logger.registrar("Processando dados...");

    return 0;
}