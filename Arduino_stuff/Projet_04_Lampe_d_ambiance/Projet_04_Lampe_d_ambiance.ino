const int greenLEDPin = 9;    // Associociation de chaque LED (entrées digitales) à une constante
const int blueLEDPin = 10;
const int redLEDPin = 11;

const int redSensorPin = A0;  // Associociation de chaque photorésistance (entrées analogiques) à une constante
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;             // Définir une variable pour chaque LED
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;       // Définir une variable pour chaque photorésistance
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);      // Lire la valeur des photorésistances et l'affecter à une variable
  delay(5);                                       // Laisser un délai de quelques millisecondes afin que analogRead fasse bien son boulot
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  Serial.print("Valeurs des photorésistances \t Rouge : ");    // Afficher les valeurs des photorésistances, le \t permet de faire un alinéa
  Serial.println(redSensorValue);
  Serial.print("\t Vert : ");
  Serial.println(greenSensorValue);
  Serial.print("\t Bleu : ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue/4;                    // Associer les valeurs des photorésistances aux variables des LEDs en les pasant de 1024 (définition du capteur) à 256 
  greenValue = greenSensorValue/4;                //(définition des LEDs) soit divisé par 4
  blueValue = blueSensorValue/4;

  Serial.print("Valeurs recalculees \t Rouge : ");    // Afficher les valeurs des photorésistances recalculées
  Serial.println(redValue);
  Serial.print("\t Vert : ");
  Serial.println(greenValue);
  Serial.print("\t Bleu : ");
  Serial.println(blueValue);

  analogWrite(redLEDPin, redValue);               // Moduler la luminosité des LEDs (analog) en fonction des photorésistances
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
