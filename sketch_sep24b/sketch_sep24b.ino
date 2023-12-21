/********************************************************************************

 * Servo motor control with Arduino
 * Potentiometer connected to Arduino is used to set Servo's position.
 * https://simple-circuit.com/
 * https://simple-circuit.com/sg90-servo-motor-control-with-arduino-proteus-simulation/

/********************************************************************************/

#include <Servo.h>   // include Arduino Servo library

Servo servo;       // create servo object to control a servo

#define PotPin    A0   // define potentiometer output pin connection
#define ServoPin  9    // define Servo control pin connection

void setup()
{

  servo.attach( ServoPin );  // attaches Servo control pin

}


void loop()
{
  uint16_t an = analogRead(PotPin);    // read analog data from potentiometer output

  uint8_t angle = map(an, 0, 1023, 0, 180);   // scale previous value between 0 and 180 (angle form)

  if ( angle != servo.read() )   // check if angle changed
    servo.write(angle);          // set new servo motor angle

  delay(10);                     // waits for the servo to get there

}

// end of code.