class TV:

    #Construtor
    def __init__(self, marca, modelo):
        self.marca = marca
        self.modelo = modelo
        self.estaLigada = False
        self.volume = 10
        self.estaMutada = False
        self.canal = 1
        self.canalAnterior = 1


    def ligar(self):
        if not self.estaLigada:
            self.estaLigada = True
            print("TV ligada.")
        else:
            print("TV já está ligada.")


    def desligar(self):
        if self.estaLigada:
            self.estaLigada = False
            print("TV desligada.")
        else:
            print("TV já está desligada.")

    def aumentarVolume(self):
        if self.volume < 100:
            self.volume += 1
            print("Volume:", self.volume)
        else:
            print("Volume já está no máximo.")


    def diminuirVolume(self):
        if self.volume > 0:
            self.volume -= 1
            print("Volume:", self.volume)
        else:
            print("Volume já está no mínimo.")


    def mutar(self):
        self.estaMutada = True
        print("TV mutada.")


    def desmutar(self):
        self.estaMutada = False
        print("TV desmutada.")


    def proximoCanal(self):
        self.canalAnterior = self.canal
        self.canal += 1
        print("Canal:", self.canal)


    def voltarCanal(self):
        self.canal, self.canalAnterior = self.canalAnterior, self.canal
        print("Canal:", self.canal)


    def acessarCanal(self, numeroCanal):
        if numeroCanal >= 1:
            self.canalAnterior = self.canal
            self.canal = numeroCanal
            print("Canal:", self.canal)
        else:
            print("Canal inválido.")

    def exibirStatus(self):
        print("--- Status da TV ---")
        print("Marca   :", self.marca)
        print("Modelo  :", self.modelo)
        print("Ligada  :", "Sim" if self.estaLigada else "Não")
        print("Canal   :", self.canal)
        print("Volume  :", self.volume)
        print("Mutada  :", "Sim" if self.estaMutada else "Não")

def main():
    tv = TV("Samsung", "Crystal 4K")

    tv.ligar()
    tv.exibirStatus()

    print()
    tv.acessarCanal(5)
    tv.aumentarVolume()
    tv.aumentarVolume()
    tv.mutar()
    tv.desmutar()
    tv.proximoCanal()
    tv.voltarCanal()

    print()
    tv.exibirStatus()

    tv.desligar()


if __name__ == "__main__":
    main()