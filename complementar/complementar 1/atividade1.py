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

## Comparação em C++ para eu aprender python

"""

class Widget {           

public:                  

  Widget() {             

    _msg = "Hello, I'm a widget!";
  }
  
  void replace() {
    size_t i = _msg.find('w');
    if (i != string::npos)
      _msg[i] = 'g'; 
  }
  string str() const {
    return "My string: " + _msg;
  }
private:
  string _msg;
};

"""