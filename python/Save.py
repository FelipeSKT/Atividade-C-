import datetime

class Logger:
    def __init__(self, caminho_arquivo: str):
        self._arquivo = open(caminho_arquivo, "a", encoding="utf-8")
        inicio = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self._arquivo.write(f"[{inicio}] === Sessão iniciada ===\n")
        self._arquivo.flush()

    def registrar(self, mensagem: str):
        agora = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self._arquivo.write(f"[{agora}] {mensagem}\n")
        self._arquivo.flush()

    def __del__(self):
        if self._arquivo and not self._arquivo.closed:
            fim = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            self._arquivo.write(f"[{fim}] === Sessão encerrada ===\n")
            self._arquivo.close()

if __name__ == "__main__":
    logger = Logger("sessao.log")
    logger.registrar("Aplicação iniciada.")
    logger.registrar("Processando dados...")
   