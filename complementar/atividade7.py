'''
7. Defina uma classe Conjunto, que mantém o controle de uma coleção de objetos distintos. Internamente, use uma lista como uma variável de controle, mas sem permitir valores
duplicados em seu conteúdo. A seguinte sugestão de design pode ser adotada:
O método para adicionar elementos deve inserir o elemento no conjunto se ele não existir.
O método para remover deve remover um elemento apenas se ele existir no conjunto. O
2
método pesquisar retorna True/False se o elemento existe ou não dentro do conjunto. Obs:
Faça em ambas as linguagens (Python e C++).
'''



class Conjunto:
    """Classe que representa um conjunto de objetos distintos."""

    def __init__(self):
        self._elementos = []

    def adicionar(self, elemento):
        """Insere o elemento no conjunto apenas se ele não existir."""
        if not self.pesquisar(elemento):
            self._elementos.append(elemento)
            print(f"[+] '{elemento}' adicionado ao conjunto.")
        else:
            print(f"[!] '{elemento}' já existe no conjunto. Duplicata ignorada.")

    def remover(self, elemento):
        """Remove o elemento do conjunto apenas se ele existir."""
        if self.pesquisar(elemento):
            self._elementos.remove(elemento)
            print(f"[-] '{elemento}' removido do conjunto.")
        else:
            print(f"[!] '{elemento}' não encontrado no conjunto.")

    def pesquisar(self, elemento):
        """Retorna True se o elemento existir no conjunto, False caso contrário."""
        return elemento in self._elementos

    def tamanho(self):
        """Retorna a quantidade de elementos no conjunto."""
        return len(self._elementos)

    def __str__(self):
        return f"Conjunto({self._elementos})"


# ── Demonstração ──────────────────────────────────────────────
if __name__ == "__main__":
    c = Conjunto()

    c.adicionar(10)
    c.adicionar(20)
    c.adicionar(30)
    c.adicionar(20)          # duplicata → ignorada

    print(c)                 # Conjunto([10, 20, 30])
    print("Tamanho:", c.tamanho())

    print("Pesquisar 20:", c.pesquisar(20))   # True
    print("Pesquisar 99:", c.pesquisar(99))   # False

    c.remover(20)
    c.remover(99)            # não existe → aviso

    print(c)                 # Conjunto([10, 30])