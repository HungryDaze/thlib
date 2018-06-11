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
    Sensor(uint8_t pin,char p);//constructor for INPUT_PULLUP
    ~Sensor();//deconstructor

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
#endif // THLIB_H_INCLUDED
