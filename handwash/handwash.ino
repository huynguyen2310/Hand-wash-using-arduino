#include <Servo.h>

#define trigPin 3
#define echoPin 2

Servo servo1;
Servo servo2;

void setup() 
    {
        Serial.begin (9600);
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
         /*set up for ultrasonic*/
        servo1.attach(4);
        servo2.attach(5);
    }
void loop() 
    {
        long duration, distance;
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        distance = (duration/2)*29.1;
        if (distance < 5) /*the distance is less than 5 cm*/
            {
                Serial.println("show your hand");
                servo1.write(100);
                /*rotate servo1 to 100degress*/
                servo2.write(100);
            }
        else  
            {  
                servo1.write(0);
                servo2.write(0);
                Serial.println("The distance is more than 5, move your hand closer");
                Serial.print(distance);
                Serial.println(" cm");
            }
      delay(500);
}
