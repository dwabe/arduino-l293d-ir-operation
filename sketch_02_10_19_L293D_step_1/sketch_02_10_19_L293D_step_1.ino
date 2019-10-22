#include <IRremote.h> //including the remote library
int receiver_pin = 2; //output pin of IR receiver to pin 2 of arduino
IRrecv receiver(receiver_pin); //arduino will take output of IR receiver from pin 2
decode_results output;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn(); // start to take the output from IR receiver
}

void loop() {
  if (receiver.decode(&output)) {
    unsigned int value = output.value;
    Serial.println(value);
    receiver.resume();
  }
}
