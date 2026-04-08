class Cofre:

    CODIGO_MASTER = "MASTER2024"  # senha do técnico, separada da combinação normal

    def __init__(self, combinacao: str):
        self.__combinacao = combinacao
        self.__conteudo = []
        self.__aberto = False
        self.__tentativas_erradas = 0
        self.__bloqueado = False

    # ── Métodos privados ──────────────────────────────────────────────────
    def __verificar_acesso(self) -> bool:
        """Checa se o cofre está aberto e não bloqueado."""
        if self.__bloqueado:
            print("Acesso negado: cofre bloqueado permanentemente. Chame um técnico.")
            return False
        if not self.__aberto:
            print("Acesso negado: o cofre está fechado.")
            return False
        return True

    # ── Métodos públicos ──────────────────────────────────────────────────
    def abrir(self, combinacao: str):
        if self.__bloqueado:
            print("Cofre bloqueado! Intervenção técnica necessária.")
            return

        if self.__aberto:
            print("O cofre já está aberto.")
            return

        if combinacao == self.__combinacao:
            self.__aberto = True
            self.__tentativas_erradas = 0
            print("Cofre aberto com sucesso.")
        else:
            self.__tentativas_erradas += 1
            restantes = 3 - self.__tentativas_erradas
            print(f"Combinação incorreta! Tentativas restantes: {restantes}.")
            if self.__tentativas_erradas >= 3:
                self.__bloqueado = True
                print("ALERTA: Cofre bloqueado após 3 tentativas erradas!")

    def fechar(self):
        if not self.__aberto:
            print("O cofre já está fechado.")
            return
        self.__aberto = False
        print("Cofre fechado.")

    def guardar(self, item: str):
        if not self.__verificar_acesso():
            return
        self.__conteudo.append(item)
        print(f"Item '{item}' guardado no cofre.")

    def retirar(self, item: str):
        if not self.__verificar_acesso():
            return
        if item in self.__conteudo:
            self.__conteudo.remove(item)
            print(f"Item '{item}' retirado do cofre.")
        else:
            print(f"Item '{item}' não encontrado no cofre.")

    def listar_conteudo(self):
        if not self.__verificar_acesso():
            return
        if not self.__conteudo:
            print("O cofre está vazio.")
        else:
            print("Conteúdo do cofre:")
            for item in self.__conteudo:
                print(f"  - {item}")

    def esta_bloqueado(self) -> bool:
        """Único jeito de o código externo saber se o cofre está bloqueado."""
        return self.__bloqueado

    def resetar_bloqueio(self, codigo_master: str):
        """Aceita a senha mestra e desbloqueia o cofre — simula intervenção técnica."""
        if codigo_master == self.CODIGO_MASTER:
            self.__bloqueado = False
            self.__tentativas_erradas = 0
            self.__aberto = False
            print("Bloqueio removido pelo técnico. Cofre pronto para uso.")
        else:
            print("Código master incorreto. Operação negada.")


# ── Demonstração ──────────────────────────────────────────────────────────────
if __name__ == "__main__":
    cofre = Cofre("1234")

    # Tentativas erradas → bloqueio
    print("=== Testando bloqueio ===")
    cofre.abrir("0000")
    cofre.abrir("9999")
    cofre.abrir("1111")          # 3ª falha → bloqueia

    print(f"Bloqueado? {cofre.esta_bloqueado()}")
    cofre.abrir("1234")          # bloqueado, não abre

    # Intervenção técnica
    print("\n=== Intervenção técnica ===")
    cofre.resetar_bloqueio("ERRADO")
    cofre.resetar_bloqueio("MASTER2024")

    # Uso normal
    print("\n=== Uso normal ===")
    cofre.abrir("1234")
    cofre.guardar("Passaporte")
    cofre.guardar("Joias")
    cofre.guardar("Dinheiro")
    cofre.listar_conteudo()
    cofre.retirar("Joias")
    cofre.retirar("Laptop")      # item inexistente
    cofre.listar_conteudo()
    cofre.fechar()
    cofre.guardar("Documento")   # cofre fechado
    cofre.fechar()               # já está fechado

    # Tentativa de acesso direto (bloqueada pelo encapsulamento)
    print("\n=== Tentativa de trapaça ===")
    try:
        print(cofre.__conteudo)
    except AttributeError as e:
        print(f"Acesso direto bloqueado: {e}")