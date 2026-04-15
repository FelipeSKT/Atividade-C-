/*
2. Implemente uma classe Sensor que controla quantas instâncias existem ao mesmo tempo.
O construtor incrementa um contador estático; o destrutor o decrementa. O programa deve
mostrar a contagem a cada criação e destruição. O que deve ser feito:
• Atributo estático compartilhado entre instâncias
• Construtor incrementa; destrutor decrementa
• Testar dentro de escopos aninhados para ver o comportamento
• Em Python: usar variável de classe e __del__
*/

class Sensor{

    private:

        int contador;


    public:

        Sensor(){
            this->contador = 0;
            
        }


};