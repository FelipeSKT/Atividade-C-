class TV:
    # -------------------------------------------------------------------------
    # C++: class TV { public: string marca; bool estaLigada; ... };
    #
    # Python: os atributos NÃO são declarados fora do construtor.
    #         Eles são criados dentro do __init__ usando "self.atributo = valor".
    #         Tudo em Python é público por padrão (convenção: _ = "privado").
    # -------------------------------------------------------------------------

    # -------------------------------------------------------------------------
    # CONSTRUTOR
    # C++: TV(string marca, string modelo) { this->marca = marca; ... }
    # Python: def __init__(self, marca, modelo):  →  "self" é o "this" do C++
    #         mas deve ser declarado EXPLICITAMENTE como primeiro parâmetro.
    # -------------------------------------------------------------------------
    def __init__(self, marca: str, modelo: str):
        # C++: this->marca = marca;
        # Python: self.marca = marca   →  cria E atribui ao mesmo tempo
        self.marca = marca
        self.modelo = modelo
        self.esta_ligada = False        # C++: bool estaLigada = false;
        self.volume = 10                # C++: int volume = 10;
        self.esta_mutada = False
        self.canal = 1
        self.canal_anterior = 1
        self.favoritos: list[int] = []  # C++: int canaisFavoritos[10]={0}; int favoritos=0;
        #                               # Python usa lista dinâmica — sem tamanho fixo!
        #                               # Não precisa de variável separada "favoritos"
        #                               # pois len(self.favoritos) já dá o tamanho.

    # =========================================================================
    # MÉTODOS
    # C++: void ligar() { ... }
    # Python: def ligar(self):  →  sempre recebe "self" como 1º parâmetro.
    #         O retorno padrão é None (equivalente ao void do C++).
    # =========================================================================

    def ligar(self):
        # C++: if (!estaLigada)
        # Python: if not self.esta_ligada   →  "!" vira "not", sem parênteses obrigatórios
        if not self.esta_ligada:
            self.esta_ligada = True
            print("TV ligada.")
            # ---- Comportamento da questão 5: reset ao ligar ----
            self.volume = 10
            self.esta_mutada = False   # desmuta sempre ao ligar
            self.canal = 1
        else:
            print("TV já está ligada.")

    def desligar(self):
        if self.esta_ligada:
            self.esta_ligada = False
            print("TV desligada.")
        else:
            print("TV já está desligada.")

    def aumentar_volume(self):
        # C++: if (volume < 100) volume++;
        # Python: não tem "++" — usamos "+= 1"
        if self.volume < 100:
            self.volume += 1
            print(f"Volume: {self.volume}")   # C++: cout << "Volume: " << volume << endl;
            #                                  # Python: f-string  →  f"texto {variavel}"
        else:
            print("Volume já está no máximo.")

    def diminuir_volume(self):
        if self.volume > 0:
            self.volume -= 1
            print(f"Volume: {self.volume}")
        else:
            print("Volume já está no mínimo.")

    def mutar(self):
        self.esta_mutada = True
        print("TV mutada.")

    def desmutar(self):
        self.esta_mutada = False
        print("TV desmutada.")

    def proximo_canal(self):
        self.canal_anterior = self.canal
        self.canal += 1
        print(f"Canal: {self.canal}")

    def voltar_canal(self):
        # C++: int temp = canal; canal = canalAnterior; canalAnterior = temp;
        # Python: troca simultânea sem variável temporária!
        self.canal, self.canal_anterior = self.canal_anterior, self.canal
        print(f"Canal: {self.canal}")

    def acessar_canal(self, numero_canal: int):
        # C++: void acessarCanal(int numeroCanal)
        # Python: def acessar_canal(self, numero_canal: int)
        #         A anotação ": int" é opcional (type hint) — não é obrigatória.
        if numero_canal >= 1:
            self.canal_anterior = self.canal
            self.canal = numero_canal
            print(f"Canal: {self.canal}")
        else:
            print("Canal inválido.")

    def exibir_status(self):
        # C++: cout << "Ligada: " << (estaLigada ? "Sim" : "Não") << endl;
        # Python: operador ternário  →  "Sim" if condição else "Não"
        print("--- Status da TV ---")
        print(f"Marca   : {self.marca}")
        print(f"Modelo  : {self.modelo}")
        print(f"Ligada  : {'Sim' if self.esta_ligada else 'Não'}")
        print(f"Canal   : {self.canal}")
        print(f"Volume  : {self.volume}")
        print(f"Mutada  : {'Sim' if self.esta_mutada else 'Não'}")

    def reset_fabrica(self):
        self.volume = 10
        self.esta_mutada = False
        self.canal = 1
        print("Configurações voltaram ao padrão de fábrica.")

    # -------------------------------------------------------------------------
    # FAVORITOS
    # C++: array fixo de 10 posições + contador manual
    # Python: lista dinâmica — cresce e encolhe sozinha,
    #         sem necessidade de índice manual nem posições zeradas.
    # -------------------------------------------------------------------------

    def add_favorito(self):
        if len(self.favoritos) >= 10:   # C++: if (favoritos == 10)
            #                            # len() substitui o contador manual
            print("Limite de canais favoritos atingido.")
            return

        if self.canal in self.favoritos:    # C++: loop manual para checar duplicata
            print("Canal já está nos favoritos.")  # Python: operador "in" faz isso em 1 linha
            return

        self.favoritos.append(self.canal)   # C++: canaisFavoritos[posicao] = canal; favoritos++;
        print(f"Canal {self.canal} adicionado aos favoritos.")

    def remove_favorito(self):
        if not self.favoritos:              # C++: if (favoritos == 0)
            print("Não há canais favoritados.")
            return

        if self.canal not in self.favoritos:    # C++: loop manual para achar posição
            print("Esse canal não está nos seus favoritos.")
            return

        self.favoritos.remove(self.canal)   # C++: canaisFavoritos[posicao] = 0; (sem decremento aqui)
        #                                   # .remove() já reduz o tamanho da lista automaticamente
        print(f"Canal {self.canal} removido dos favoritos.")

    def jump_favoritos(self):
        if not self.favoritos:
            print("Não há canais favoritados.")
            return

        # Filtra apenas os favoritos maiores que o canal atual
        # C++: loop manual verificando canaisFavoritos[i] > canal
        # Python: list comprehension — cria uma nova lista filtrada em 1 linha
        candidatos = [f for f in self.favoritos if f > self.canal]

        if candidatos:
            # C++: loop achando o menor entre os candidatos
            # Python: min() já faz isso nativamente
            self.canal = min(candidatos)
        else:
            # Nenhum favorito acima → usa o menor de todos (wrap-around)
            # C++: segundo loop manual
            # Python: min() na lista inteira
            self.canal = min(self.favoritos)

        print(f"Canal: {self.canal}")


# =============================================================================
# PONTO DE ENTRADA
# C++: int main() { ... return 0; }
# Python: convenção de usar  if __name__ == "__main__":
#         Isso garante que o bloco só rode quando o arquivo for executado
#         diretamente — não quando for importado por outro módulo.
#         Não há "return 0" — Python não exige código de saída.
# =============================================================================
if __name__ == "__main__":
    # C++: TV tv("Samsung", "Crystal 4K");
    # Python: tv = TV("Samsung", "Crystal 4K")   →  sem tipo na declaração
    tv = TV("Samsung", "Crystal 4K")

    tv.ligar()
    tv.exibir_status()

    print()
    tv.acessar_canal(5)
    tv.aumentar_volume()
    tv.aumentar_volume()
    tv.mutar()
    tv.desmutar()
    tv.proximo_canal()
    tv.voltar_canal()

    print()
    tv.exibir_status()

    # Testando favoritos
    print()
    tv.acessar_canal(5)
    tv.add_favorito()
    tv.acessar_canal(12)
    tv.add_favorito()
    tv.acessar_canal(30)
    tv.add_favorito()
    tv.acessar_canal(5)
    tv.jump_favoritos()   # deve ir para 12

    tv.desligar()