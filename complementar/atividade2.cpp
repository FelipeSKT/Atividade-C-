/**

class Widget:            

  def __init__(self):    

    self._msg = "Hello, I'm a widget!"

  def replace(self):     

    index = self._msg.index('w')

    self._msg = (          

      self._msg[:index] + 'g' + self._msg[index+1:]
    )

  def __str__(self):
    return 'My string: ' + self._msg

 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Widget {

  private:
    string msg;

  public:
    Widget(){
        msg = "Hello, I'm a widget!";
    }
    
    void replace(){
      for (size_t i = 0; i < msg.length() ; i++)  // ✅ length() é um método, precisa de ()
      {
        if (msg[i] == 'w')  // ✅ == para comparação (não =) e '' para char (não "")
        {
          msg[i] = 'g';     // ✅ '' para atribuição de char (não "")
        }
      }
    }
    
    string str(){
      return "String: " + msg;
    }

};



