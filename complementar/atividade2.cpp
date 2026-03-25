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

 class Widget {
    Widget(){
        msg = "ola, eu sou um widget"
    }
    

 };