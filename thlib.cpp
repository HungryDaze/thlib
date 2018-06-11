#include "thlib.h"

using namespace std;


 /* ********** Sensor ********** */


Sensor::Sensor(uint8_t pin){					// constructor for inputs sensors 

    this->pin = pin;
	if ((pin >= 0) && (pin<=13)) this->type = digital;
	if ((pin>=13) && (pin<=19)) this->type = analog;
	pinMode(pin,INPUT);   
	
}


Sensor::Sensor(uint8_t pin,signalType type){
	
	this->pin = pin;
	this->type = type;
	pinMode(pin,INPUT);

	
}

Sensor::Sensor(uint8_t pin,int value){      // constructor for outputs sensors 

    this->pin = pin;
    if ((pin >= 0) && (pin<=13)) this->type = digital;
	if ((pin>=13) && (pin<=19)) this->type = analog;

    this->value = value;
	
    pinMode(pin,OUTPUT);

    if(type==analog){
		analogWrite(pin,value);
	}
    else {
       digitalWrite(pin,value);
    }
}

Sensor::Sensor(uint8_t pin,signalType type,int value){

	this->pin = pin;
	this->type = type;

	pinMode(pin,OUTPUT);

	if(type==analog){
       analogWrite(pin,value);
    }
    else {
       digitalWrite(pin,value);
    }
}

Sensor::~Sensor(){}  

int Sensor::state(){        						 // implement for state() method 

     if(type==analog){
		uint16_t temp = analogRead(pin);

		return temp;
      }

     else{
		
		uint16_t temp = digitalRead(pin);

		return temp;
      }
}

void Sensor::state(int value){

     if(type==analog){
        analogWrite(pin,value);
     }

     else {
        digitalWrite(pin,value);
     }
}

/* ********** EEPROM ********** */





 void Sensor::report(){

	Serial.print("pin : ");
	Serial.println(pin);
	Serial.print("type : ");
	switch(type){
		case 0 : Serial.println("analog");break;
		case 1 : Serial.println("digital");break;
	}
	Serial.print("value : ");
	Serial.println(value);


 }

/* ********** Imaginary Sensor ********** */

ImSensor::ImSensor(int value,signalType type){ //destructor of imaginary Sensor

	this->type = type;
	this->value = value;


	
}	

ImSensor::~ImSensor(){} // destructor of Imaginary Sensor


int ImSensor::state(){                  	  // implement for state() method on imaginary sensor
 return ImSensor::value;
}
	
void ImSensor::state(int value){
 this->value = value;
}

	
 /* ********** Sonar Sensor ********** */

Sonar::Sonar(int triggerPin, int echoPin){

	this->triggerPin = triggerPin;
	this->echoPin = echoPin;
}
double Sonar::state(){

    Sensor trigger(triggerPin,LOW);
    Sensor echo(echoPin);

	trigger.state(HIGH);
	delayMicroseconds(10);

	long duration = pulseIn(echoPin,HIGH);
    double distance = duration *0.034/2;
	return distance;
}

/* ********** Timer ********** */

Timer::Timer(unsigned long duration){ // constructor 
	this->duration = duration;
	this->limit = 0;
}


Timer::~Timer(){} // deconstructor 


void Timer::change(unsigned long newDuration){
	this->duration = newDuration;	
}


void Timer::refresh(){
	limit = millis() + duration;
}
 unsigned long Timer::recall(unsigned long t){

	limit = t + duration;
}

void Timer::refresh(unsigned long t){
		
	limit=t+duration;
}

unsigned long Timer::recall(){

	unsigned long temp = limit;
	if(millis()>limit) limit = millis() + duration;

return temp;
}
