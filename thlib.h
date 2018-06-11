#ifndef THLIB_H_INCLUDED
#define THLIB_H_INCLUDED

#include "Arduino.h"


using namespace std;

/* One pin sensor call : Sensor name(pin number,enum signalType, startingValue for Outputs)*/

enum signalType{analog,digital};


class Sensor{

protected:

    uint8_t pin;
    signalType type;
    int value;


public:
    Sensor(uint8_t pin); //constructor for inputs for pins 0 - 19
	Sensor(uint8_t pin,signalType type);//constructor for inputs over pin 19
    Sensor(uint8_t pin,int value);//constructor for outputs for pins 0 - 19
	Sensor(uint8_t pin,signalType type,int value);//constructor for outputs
    ~Sensor();


   void state(int value);
   int state();

     void report();
   

};

class ImSensor{

protected:
	
    signalType type;
	int value;

	

public:

	ImSensor(int value=0,signalType type = digital); // constructor for imaginary sensor
	~ImSensor();

	int state();
	void state(int x);
	

};

class Sonar{
public:

int triggerPin;
int echoPin;

Sonar(int triggerPin, int echoPin);

double state();

};

class Timer{
	
public:
	unsigned long limit;
	unsigned long duration;

	Timer(unsigned long duration);
	~Timer();

	void change(unsigned long newDuration);
	void refresh();
	void refresh(unsigned long t);
	unsigned long recall();
        unsigned long recall(unsigned long t);
};

/*Class Gree{

	unsigned int cloture[] {8860,4440,620,1660,600,560,620,560,620,560,620,1680,580,560,620,560,620,580,600,580,600,580,600,1660,600,
  1680,580,580,600,580,620,560,620,560,620,560,620,560,620,560,620,560,620,560,620,1680,580,560,620,1680,580,
580,600,580,600,580,600,580,600,1660,600,580,620,1660,600,560,620,560,620,1680,580,580,600,19760,600,580,600,
580,600,580,600,580,600,580,600,580,620,560,620,560,600,580,620,560,620,560,620,560,620,560,620,1660,600,580,
600,580,600,560,620,580,600,580,600,580,600,580,600,580,600,580,600,580,600,580,600,580,600,580,620,560,620,
  1640,620,560,620,560,620,1660,600,0};

};*/

/* (FULL FAN SWING) = {8840,4460,600,1680,580,1680,600,560,620,1660,600,1680,580,1680,580,1680,580,580,600,580,600,1680,
580,1680,600,1660,600,560,620,560,620,560,620,560,620,560,620,560,620,560,620,560,620,580,600,1660,600,580,600,580,600,580,600,580,
600,580,600,580,620,1660,580,580,620,1680,580,560,620,560,620,1680,580,560,620,19760,600,1680,580,580,600,580,600,580,600,580,600,580,
600,580,620,560,620,560,600,580,620,560,620,560,620,560,620,1640,620,560,620,560,620,560,620,560,620,560,620,580,600,580,600,580,
600,580,600,580,600,580,600,580,600,580,600,580,600,1680,600,560,620,1680,580,560,620,0};*/

#endif // THLIB_H_INCLUDED
