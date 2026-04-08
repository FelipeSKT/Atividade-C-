class Termostato:
    MIN = 0
    MAX = 40
 
    def __init__(self):
        self.__temperatura = 20  # inicia em 20 conforme o enunciado
        self.__ligado = False
 
    def __del__(self):
        pass  # destrutor vazio, equivalente ao ~Termostato(){}
 
    def __validar_temperatura(self, valor) -> bool:
        """Retorna True se a temperatura for válida, False se estiver fora dos limites."""
        if valor < self.MIN or valor > self.MAX:
            print("Aviso: Temperatura fora dos limites permitidos (0 a 40)!")
            return False
        return True
 
    def ligar(self):
        self.__ligado = True
 
    def desligar(self):
        self.__ligado = False
 
    def aumentar(self, graus: int):
        if not self.__ligado:
            print("Aviso: Termostato desligado!")
            return
 
        nova_temp = self.__temperatura + graus
 
        if self.__validar_temperatura(nova_temp):
            self.__temperatura = nova_temp
 
    def diminuir(self, graus: int):
        if not self.__ligado:
            print("Aviso: Termostato desligado!")
            return
 
        nova_temp = self.__temperatura - graus
 
        if self.__validar_temperatura(nova_temp):
            self.__temperatura = nova_temp
 
    def exibir_estado(self):
        print(f"Ligado: {'Sim' if self.__ligado else 'Nao'}")
        print(f"Temperatura: {self.__temperatura}°C")
 
 
if __name__ == "__main__":
    ar = Termostato()
 
    ar.ligar()
    ar.exibir_estado()
    ar.aumentar(5)
    ar.aumentar(5)
    ar.exibir_estado()
    ar.diminuir(3)
    ar.exibir_estado()
    ar.desligar()
    ar.diminuir(3)  
    ar.exibir_estado()