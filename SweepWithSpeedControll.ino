/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.
 
 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
 
 modified 28 Sept. 2015
 by Jed Koch
 */

#include <Servo.h> 

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
Servo myservo;  // create servo object to control a servo 
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position 

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 

  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {     // in steps of 1 degree 
    checkPot();
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delayMicroseconds(val);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    checkPot();
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delayMicroseconds(val);                       // waits 15ms for the servo to reach the position 
  } 
} 

void checkPot(){
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 10, 2000);     // scale it to use it with the servo (value between 0 and 180) 
}

