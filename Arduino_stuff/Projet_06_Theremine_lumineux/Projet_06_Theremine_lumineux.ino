const int sensorPin = A0;     // Constantes
const int ledPin = 13;        // LED reliée à la broche 13 présente sur la carte

int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  pinMode(ledPin, OUTPUT);    // Configurer led comme une sortie
  digitalWrite(ledPin, HIGH); // L'allumer

  // Créer une boucle qui dure 5 secondes pour calibrer les valeurs min et max de la photorésistance
  while(millis() < 5000) {    
    sensorVal = analogRead(sensorPin);
    if (sensorVal < sensorHigh) {   // Si la valeur est infèrieur à 1024 alors redéfinir une valeur max
      sensorHigh = sensorVal;       
    }
    if (sensorVal > sensorLow) {    // Si la valeur est supérieur à 0 alors redéfinir une valeur min
      sensorLow = sensorVal;
    }
  }
  Serial.print("Valeur max de la photorésistance :");
  Serial.println(sensorHigh);
  Serial.print(", Valeur min :");
  Serial.println(sensorLow);
  
  digitalWrite(ledPin, LOW);  //Éteindre la led à la fin des 5 secondes de calibrage
}

void loop() {
  sensorVal = analogRead(sensorPin);
  // Créer une variable pitch et passer les valeurs du capteur dans l'intervalle recalibré
  //à des valeurs compréhensibles pour le buzzer piezo
  int pitch = map(sensorVal,sensorLow,sensorHigh,50,4000);

  tone(8,pitch,20);           // Configurer le buzzer sur la broche 8, avec la valeur de pitch
                              //pour fréquence et pendant une durée de 20 millisecondes 

  delay(10);
}
