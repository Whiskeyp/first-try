#include <CapacitiveSensor.h>
// Creer une instance pour la bibliothèque et préciser les broches utilisées,
//4 émet le courant et 2 reçoit les informations 
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 500;     // Variable représentant le seuil d'allumage de la LED
const int LEDPin = 12;  

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // Déclarer une variable de type long pour la valeur du capteur, lire sur un échantillon 
  //de 30 valeurs
  long sensorVal = capSensor.capacitiveSensor(30);
  Serial.print("Valeur du capteur");
  Serial.println(sensorVal);

  if (sensorVal > threshold) {     // Si la valeur du capteur est sup à la valeur seuil alors
    digitalWrite(LEDPin, HIGH);     //la lampe s'allume
  }
  else {                            // Sinon non
    digitalWrite(LEDPin, LOW);
  }
  delay(10);
}
