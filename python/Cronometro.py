import time


class Cronometro:

    def __init__(self):
        self.__tempo_inicio = 0.0   # marca o momento em que foi iniciado
        self.__tempo_total = 0.0    # acumula o tempo entre paradas
        self.__rodando = False      # indica se está em contagem

    # ── Método privado ──────────────────────────────────────────────────────
    def __tempo_decorrido(self) -> float:
        """Calcula o intervalo (em segundos) desde o último iniciar()."""
        return time.time() - self.__tempo_inicio

    def __registrar_volta(self):
        """Exibe o tempo da volta atual sem parar a contagem."""
        if self.__rodando:
            volta = self.__tempo_decorrido()
            print(f"Volta: {volta:.2f}s")
        else:
            print("Aviso: Cronômetro não está rodando.")

    # ── Métodos públicos ────────────────────────────────────────────────────
    def iniciar(self):
        """Começa a contagem — se já estiver rodando, exibe aviso."""
        if self.__rodando:
            print("Aviso: Cronômetro já está rodando!")
            return
        self.__tempo_inicio = time.time()
        self.__rodando = True
        print("Cronômetro iniciado.")

    def parar(self):
        """Interrompe e acumula o tempo decorrido — se já parado, exibe aviso."""
        if not self.__rodando:
            print("Aviso: Cronômetro já está parado!")
            return
        self.__tempo_total += self.__tempo_decorrido()
        self.__rodando = False
        print("Cronômetro parado.")

    def resetar(self):
        """Zera tudo."""
        self.__tempo_inicio = 0.0
        self.__tempo_total = 0.0
        self.__rodando = False
        print("Cronômetro resetado.")

    def exibir_tempo(self):
        """Mostra o tempo total acumulado em segundos com duas casas decimais."""
        if self.__rodando:
            total = self.__tempo_total + self.__tempo_decorrido()
        else:
            total = self.__tempo_total
        print(f"Tempo total: {total:.2f}s")

    def volta(self):
        """Método público que aciona o registro de volta (acesso controlado)."""
        self.__registrar_volta()


# ── Demonstração ─────────────────────────────────────────────────────────────
if __name__ == "__main__":
    c = Cronometro()

    c.iniciar()
    time.sleep(1.5)
    c.volta()            # mostra tempo parcial sem parar
    time.sleep(1.0)
    c.exibir_tempo()     # ~2.5s rodando
    c.parar()
    c.exibir_tempo()     # tempo acumulado

    print()
    c.iniciar()          # retoma contagem
    time.sleep(0.8)
    c.parar()
    c.exibir_tempo()     # ~3.3s no total

    print()
    c.parar()            # aviso: já está parado
    c.iniciar()
    c.iniciar()          # aviso: já está rodando
    c.parar()

    print()
    c.resetar()
    c.exibir_tempo()     # 0.00s após reset

    try:
        c.__tempo_inicio = 0   # AttributeError por name mangling
    except AttributeError as e:
        print(f"\nTentativa de trapaça bloqueada: {e}")