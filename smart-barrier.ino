#include <Servo.h>    //servo library included

#define trigPin 9     //defines the trig and echopins for the ultrasonic sensor
#define echoPin 10

int leds[2] = {5,6};  //open led is on pin 5, closed is on pin 6. 

const int buzzer = 11; //defines buzzer pin

Servo myServo;      //creates the servo object

void setup() {
  Serial.begin(9600);   //initialize serial comms

  pinMode(trigPin, OUTPUT);   // Set trigPin as output
  pinMode(echoPin, INPUT);    // Set echoPin as input
  
  myServo.attach(3);    // attach the servo to pin 3

  for (int i = 0; i < 2; i++){    //define leds as output pins
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buzzer, OUTPUT);    //define buzzer as output
}

void loop() {
  digitalWrite(trigPin, LOW);   // Clear the trigger pin
  delayMicroseconds(2);

  // send a 10us HIGH pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure the time it takes to receive the echo
  long duration = pulseIn(echoPin, HIGH);

  // convert duration to distance in centimeters; assuming the speed of sound in air is 340m/s
  long distance = duration * 0.034 / 2;

  // print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  //  turn off all leds
  for (int i=0; i<2; i++) {
    digitalWrite(leds[i], LOW);
  }

  //set servo to flat
  myServo.write(90);

  //light up based on distance
  if (distance > 14) {
    digitalWrite(leds[1], HIGH); // Farther than 14 cm
    myServo.write(90);      //set servo flat
  } 
  else {
    digitalWrite(leds[0], HIGH); // Closer than 14 cm

    myServo.write(0); //set servo to open the bin

    //make the buzzer beep
    for (int i=0; i<10; i++) {
        tone(buzzer, 1000); // send 1KHz sound signal
        delay(100);        // wait 0.1 sec
        noTone(buzzer);     // Stop sound
        delay(100);        // wait 0.1 sec
    }

    delay(500);
  } 

  //add small delay between readings
  delay(500);
}
