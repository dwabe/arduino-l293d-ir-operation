
#include <IRremote.h>

#define Next_button 6375  // code received from next button
#define Prev_button 19125  // code received from previous button
//#define left_button 4335  // code received from left button
//#define right_button 23205 // code received from right button
#define Stop_button 14535   // code received from stop button

int receiver_pin = 2;      //output pin of IR receiver to pin 2 of arduino
IRrecv receiver(receiver_pin); //Arduino will take output of IR receiver from pin 2
decode_results output;

// by default this example uses the standalone version of the library
// comment out the following row to switch to the twoWire version
#define use_standalone

// import the library in the sketch
#include <L293.h>

// give a name to the pins that we use
const int speedPin = 6;    // that is the pin that we use to control the motor's speed
const int forwardPin = 7; // this is the pin that we use to tell the motor to go forward
const int reversePin = 8; // this is the pin that we use to tell the motor to go reverse
const int speedPin1 = 3;    // that is the pin that we use to control the motor's speed
const int forwardPin1 = 4; // this is the pin that we use to tell the motor to go forward
const int reversePin1 = 5;
#ifdef use_standalone

// make a new instance of the L293 library and call it "motor"
// then show what are the pins used to control speed, to tell the motor to go forward and to tell the motor to go reverse
L293 motor( speedPin, forwardPin, reversePin );
L293 motor1( speedPin1, forwardPin1, reversePin1 );

#else

// if you using the twoWire version of the library only one pin is required to tell the direction
// the forwardPin can do the job of the directionPin in this case
L293_twoWire motor( speedPin, forwardPin );

#endif

void setup()
{
  Serial.begin(9600);
  receiver.enableIRIn(); // start to take the output from IR receiver
}

void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    switch(value) {
      case Next_button:
           motor.forward(255);
           motor1.forward(255);
           break;
      case Prev_button:
           motor.back(255);
           motor1.back(255);
           break;
     // case left_button: 
           
     // case right_button:
           
      case Stop_button:
           motor.stop();
           motor1.stop();
           break;
    }
    receiver.resume();
  }
} 
