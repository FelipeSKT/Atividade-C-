"""
. Crie uma classe Livro com atributos título, autor e ano. Implemente construtores que
aceitem diferentes combinações de parâmetros (com e sem ano). Em C++, use o destrutor
para exibir uma mensagem de desalocação. Em Python, implemente __del__ e __init__.
O que deve ser feito:
• Construtor padrão e construtor com parâmetros
• Em C++: destrutor que imprime mensagem ao sair de escopo
• Em Python: __del__ equivalente
• Criar um vetor/lista de livros e observar a ordem de destruição
"""
class Livro:
    # 1. Em Python, não declaramos o tipo e as variáveis fora dos métodos.
    # Tudo é criado diretamente no construtor (__init__).
    
    # 2. O Python não aceita múltiplos construtores (sobrecarga). 
    # Em vez disso, passamos "valores padrão" (default) nos parâmetros.
    # Assim, um único __init__ cobre todos os cenários (padrão, sem ano, completo).
    def __init__(self, titulo="Sem Titulo", autor="Desconhecido", ano=0):
        # Usamos dois underlines (__) para deixar o atributo "privado"
        self.__titulo = titulo
        self.__autor = autor
        self.__ano = ano
        
    # Getters - Em Python, sempre passamos 'self' como primeiro parâmetro
    def getTitulo(self):
        return self.__titulo
    
    def getAutor(self):
        return self.__autor
    
    def getAno(self):
        return self.__ano
    
    # Setters - Recebem o 'self' e o valor a ser alterado
    def setTitulo(self, titulo):
        self.__titulo = titulo
    
    def setAutor(self, autor):
        self.__autor = autor
        
    def setAno(self, ano):
        self.__ano = ano
        
    # Destrutor equivalente ao ~Livro() do C++
    def __del__(self):
        print(f"Livro '{self.__titulo}' foi apagado!")

def main():
    print("Criando a lista de livros...\n")
    
    # Em Python, usamos listas (arrays dinâmicos) com colchetes []
    lista_livros = [
        Livro("Magia Negra", "Julio", 1500),
        Livro("Obras Arcanas", "Turquia", 1600),
        Livro("Abra Cadabra", "Pedro", 1800),
        Livro(), # Construtor padrão (Sem titulo, Desconhecido, 0)
        Livro("Magia Fundamental", "Artus") # Construtor sem ano
    ]
    
    print("\nSaindo da main. Os destrutores serao chamados agora:\n")

if __name__ == "__main__":
    main()