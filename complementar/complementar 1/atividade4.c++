/**
"""
3. O código abaixo define uma classe Radio que implementa um modelo (muito) simples
de rádio. Embora possa se criticar o realismo do modelo, há problemas mais sérios na
modelagem. Especificamente, há 5 erros críticos com a sintaxe da classe definida. Identifique
e os corrija.
"""

class Radio( ):
    def __init__(self):
        self._powerOn = False
        self._volume = 5
        self._station = 90.7
        self._presets = [90.7, 92.3, 94.7, 98.1, 105.7, 107.7]
    
    def tooglePower(self):
        self._powerOn = not self._powerOn
    def setPreset(self, ind):
        self._presets[ind] = self._station
    def gotoPreset(self, ind):
        self._station = self._presets[ind]
    def increaseVolume(self):
        self._volume = self._volume + 1
    def decreaseVolume(self):
        self._volume = self._volume - 1
    def increaseStation(self):
        self._station = self._station + .2
    def decreaseStation(self):
        self._station = self._station - .2
4. Refaça a classe Radio acima em C++.
 */

#include <iostream>
#include <string>
using namespace std;

 class Radio{
    private:
        bool ligado;
        int volume;
        float station;
        int stations[10] = {90.7, 92.3, 94.7, 98.1, 105.7, 107.7};

    public:

        Radio(bool ligado, int volume, float station){
            this->ligado = ligado;
            this->volume = volume;
            this->station = station;
        }

        bool isLigado (){
            return ligado;
        }

        int getVolume(){
            return volume;
        }

        float getStation(){
            return station;
        }

        void printStations(){
            for (size_t i = 0; i < 6; i++)
            {
                cout <<"Canal: " <<stations[i] <<" ";
            }
            cout << endl;
            return;
        }

        void aumentarVolume(){
            if (volume >= 100)
            {
                volume = 100;
                return;
            }
            volume = volume + 1;
            return;
        }

        void diminuirVolume(){
            if (volume <= 0){
                volume =0;
                return;
            }
            volume = volume - 1;
        }

        void aumentarStation(){
            station = station + 0.2;
        }

        void diminuirStation(){
            station + station - 0.2;
        }

 };
    