#include <Servo.h>    

#define trigPin 9     
#define echoPin 10

int leds[2] = {5,6};  //Open LED is on pin 5, Closed is on pin 6. 

const int buzzer = 11; 

Servo myServo; 

void setup() {
  Serial.begin(9600);   

  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT);    
  
  myServo.attach(3);   
  for (int i = 0; i < 2; i++){    //Define LED pins as output
    pinMode(leds[i], OUTPUT);
  }

  pinMode(buzzer, OUTPUT);   
}

void loop() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);

  // send a 10us HIGH pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  long duration = pulseIn(echoPin, HIGH);

  // Convert duration to distance in cm assuming the speed of sound assumed to be 340m/s
  long distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  //  Turn off all LEDs
  for (int i=0; i<2; i++) {
    digitalWrite(leds[i], LOW);
  }

  //Set gate flat
  myServo.write(90);

  if (distance > 14) {
    digitalWrite(leds[1], HIGH); // Farther than 14 cm set servo to close the barrier
    myServo.write(90);      
  } 
  else {
    digitalWrite(leds[0], HIGH); // Closer than 14 cm set servo to open the barrier
    myServo.write(0); 

    //Buzzer tone
    for (int i=0; i<10; i++) {
        tone(buzzer, 1000);
        delay(100);        
        noTone(buzzer);     
        delay(100);        
    }

    delay(500);
  } 

  //Delay between readings
  delay(500);
}
