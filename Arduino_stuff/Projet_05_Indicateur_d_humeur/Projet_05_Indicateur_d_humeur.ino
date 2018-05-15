#include <Servo.h>        // Importer la bibliothèque Servo
Servo myServo;            // Créer une variable faisant référence à la bibliothèque Servo

const int potPin = A0;    // Constante

int potVal;               // Variables
int angle;

void setup() {
  myServo.attach(9);      // Spécifier la broche à laquelle est connectée le servomoteur

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("La valeur du potentiomètre est de :");
  Serial.println(potVal);

  angle = map(potVal, 0, 1023, 0, 179);     // Recalibrer la valeur du potentiomètre initialement comprise entre 0
  Serial.print(", l'angle est de :");       //et 1023 en valeurs comprise entre 0 et 179 (pour l'angle en °)
  Serial.println(angle);

  myServo.write(angle);   // Faire bouger le servomoteur de l'angle indiqué
  delay(1500);
}
