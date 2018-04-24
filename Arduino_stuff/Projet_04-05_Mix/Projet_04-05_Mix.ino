#include <Servo.h>
Servo  myServo;

const int sensorPin = A0;

int sensorVal;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.print("La valeur du capteur de température est :");
  Serial.println(sensorVal);

  angle = map(sensorVal, 0, 1023, 0, 179);       // Recalibrage de la luminosité mesurée en valeur de l'angle
  Serial.print(", l'angle est de :");  
  Serial.println(angle);

  myServo.write(angle);
  delay(1500);
}
