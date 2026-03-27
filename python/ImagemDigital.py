class ImagemDigital:
 

    def __init__(self, nome, largura, altura, formato="PNG"):
        self.nome = nome          # atributo público (não há private/public em Python)
        self.largura = largura
        self.altura = altura
        self.formato = formato

    def exibir_info(self):
        print(f"Arquivo : {self.nome}")
        print(f"Formato : {self.formato}")
        print(f"Tamanho : {self.largura} x {self.altura} px")
 

    def total_pixels(self):
        return self.largura * self.altura

    def __str__(self):
        return f"ImagemDigital('{self.nome}', {self.largura}x{self.altura})"
 
def main():
    print("=== Criando imagem ===")
 
    # Instanciando o objeto (sem 'new' como no C++)
    img = ImagemDigital("foto.png", 1920, 1080)
 
    # Acessando atributos diretamente
    print("Nome:", img.nome)
    print("Largura:", img.largura)
    print("Altura:", img.altura)
 
    print()
    print("=== Chamando métodos ===")
    img.exibir_info()
 
    print()
    print("Total de pixels:", img.total_pixels())
 
    print()
    print("=== Alterando atributos ===")
    img.nome = "nova_foto.jpg"   # em C++: img.nome = "nova_foto.jpg";
    img.formato = "JPEG"
    img.exibir_info()
 
    print()
    print("=== Criando segunda imagem ===")
    img2 = ImagemDigital("thumb.png", 150, 150)
    print(img)    # chama __str__ automaticamente
    print(img2)
 
 
if __name__ == "__main__":
    main()