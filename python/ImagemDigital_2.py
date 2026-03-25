class ImagemDigital:
 

    def __init__(self, nome, largura, altura, formato="PNG"):
        self.nome = nome
        self.largura = largura
        self.altura = altura
        self.formato = formato
 

    def exibir_info(self):
        print(f"Arquivo : {self.nome}")
        print(f"Formato : {self.formato}")
        print(f"Tamanho : {self.largura} x {self.altura} px")
 

    def total_pixels(self):
        return self.largura * self.altura

    def eh_paisagem(self):
        return self.largura > self.altura
 

    def eh_quadrada(self):
        return self.largura == self.altura

    def renomear(self, novo_nome):
        self.nome = novo_nome

    def redimensionar(self, nova_largura, nova_altura):
        self.largura = nova_largura
        self.altura = nova_altura
 

    def classificar_tamanho(self):
        pixels = self.total_pixels()
        if pixels < 100_000:
            return "pequena"
        elif pixels < 2_000_000:
            return "média"
        else:
            return "grande"
 

    def __str__(self):
        return f"ImagemDigital('{self.nome}', {self.largura}x{self.altura})"
 
 
def main():
    print("=== Criando imagem ===")
    img = ImagemDigital("foto.png", 1920, 1080)
    print("Nome:", img.nome)
    print("Largura:", img.largura)
    print("Altura:", img.altura)
 
    print()
    print("=== exibir_info() e total_pixels() ===")
    img.exibir_info()
    print("Total de pixels:", img.total_pixels())
 
    print()
    print("=== Alterando atributos ===")
    img.nome = "nova_foto.jpg"
    img.formato = "JPEG"
    img.exibir_info()
 
    print()
    print("=== Novos métodos ===")
 
    # eh_paisagem() — banner largo
    img2 = ImagemDigital("banner.png", 1280, 720)
    print("banner.png é paisagem?", img2.eh_paisagem())   # True
 
    # eh_quadrada() — avatar quadrado
    img3 = ImagemDigital("avatar.png", 200, 200)
    print("avatar.png é quadrada?", img3.eh_quadrada())   # True
 
    # renomear()
    img2.renomear("banner_novo.png")
    print("Nome após renomear:", img2.nome)
 
    # redimensionar()
    img2.redimensionar(640, 360)
    print("Após redimensionar:", img2.largura, "x", img2.altura)
 
    # classificar_tamanho()
    img4 = ImagemDigital("icone.png", 32, 32)
    img5 = ImagemDigital("wallpaper.jpg", 3840, 2160)
    print("Tamanho do ícone:", img4.classificar_tamanho())      # pequena
    print("Tamanho do wallpaper:", img5.classificar_tamanho())  # grande
 
    print()
    print("=== __str__ ===")
    print(img2)   # chama __str__ automaticamente
    print(img3)
 
 
if __name__ == "__main__":
    main()