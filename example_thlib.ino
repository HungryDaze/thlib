#include<thlib.h>

Sensor motion(2); //inputs need only one argument
Sensor light(14); // analog pin number some with arduino uno and nano
Sensor relay(3,HIGH); // two arguments for outputs




void setup() {
  

}

void loop() {
  
 If(motion.state() == 1)
  relay.state(LOW);

 etc.......


}
