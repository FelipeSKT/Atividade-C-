import copy

class Matriz:
    def __init__(self, linhas: int, colunas: int):
        if linhas <= 0 or colunas <= 0:
            raise ValueError("Dimensões devem ser positivas.")
        self.linhas  = linhas
        self.colunas = colunas
        # Lista de listas — análogo ao int** em C++
        self._dados = [[0] * colunas for _ in range(linhas)]

    # ── Construtor de cópia via __copy__ e __deepcopy__ ──────────

    def __copy__(self):
        """Cópia rasa: novo objeto Matriz, mas compartilha as linhas internas."""
        novo = Matriz.__new__(Matriz)
        novo.linhas  = self.linhas
        novo.colunas = self.colunas
        novo._dados  = list(self._dados)   # copia a lista externa, NÃO as linhas
        return novo

    def __deepcopy__(self, memo):
        """Cópia profunda: aloca estrutura completamente nova."""
        novo = Matriz.__new__(Matriz)
        novo.linhas  = self.linhas
        novo.colunas = self.colunas
        novo._dados  = [linha[:] for linha in self._dados]   # copia cada linha
        memo[id(self)] = novo
        return novo

    # ── Interface pública ────────────────────────────────────────

    def get(self, i: int, j: int) -> int:
        return self._dados[i][j]

    def set(self, i: int, j: int, valor: int):
        self._dados[i][j] = valor

    def imprimir(self, nome: str):
        print(f"{nome}:")
        for linha in self._dados:
            print("\t".join(str(v) for v in linha))
        print()

    def __del__(self):
        # Em Python o GC gerencia a memória, mas podemos limpar referências
        self._dados = None


# ── Demo ──────────────────────────────────────────────────────────
if __name__ == "__main__":
    original = Matriz(2, 3)
    for i in range(2):
        for j in range(3):
            original.set(i, j, i * 3 + j + 1)   # valores 1..6

    # Cópia profunda — blocos independentes
    copia_deep = copy.deepcopy(original)
    copia_deep.set(0, 0, 99)
    copia_deep.set(1, 2, 77)

    original.imprimir("original (não deve mudar)")
    copia_deep.imprimir("copia profunda (modificada)")

    # ── Demonstração do perigo da cópia rasa ──────────────────────
    copia_rasa = copy.copy(original)
    copia_rasa.set(0, 0, 666)   # MODIFICA A LINHA INTERNA COMPARTILHADA

    print("--- Após modificar a cópia RASA ---")
    original.imprimir("original (CORROMPIDO pela cópia rasa!)")
    copia_rasa.imprimir("copia rasa")