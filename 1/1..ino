/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

const int irReceiverPin=11;

IRrecv irrecv(irReceiverPin);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println("irCode: ");
    Serial.println(results.value, HEX);
    Serial.println(", bits: ");
    Serial.println(results.bits);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
