const int sensorPin = A0;         //Création d'une constante pour l'entrée analogique
const float baselineTemp = 28.0;   //Création d'une constante, sous forme de nombre décimal, pour la température de référence

void setup() {
  Serial.begin(9600);              //Vitesse de communication

  for(int pinNumber = 3; pinNumber < 6; pinNumber++){   //Configurer les sorties 3 sorties LED en même temps
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);

  Serial.print("Valeur capteur : ");     //Afficher le texte dans le moniteur série
  Serial.print(sensorVal);              //Afficher la variable

  float voltage = (sensorVal/1024.0) * 5.0;   //Création d'une variable, sous forme de nombre décimal, pour la tension calculée à partir de la valeur du capteur
  Serial.print(", Volts : "); 
  Serial.println(voltage);

  float temperature = (voltage - .5) * 100;   //Création d'une variable pour la température mesurée calculée à partir de la valeur de la tension
  Serial.print(", degres C : ");
  Serial.println(temperature);

  if(temperature < baselineTemp){      //Si la température est inférieur à 28.0°
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
  }
  else if(temperature >= baselineTemp && temperature < baselineTemp+2){   //Si la température est comprise entre 28 et 30
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){ //Si la température est comprise entre 30 et 32
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
     digitalWrite(5, LOW);
  }
  else if(temperature >= baselineTemp+4){                                 //Si la température est au dessus de 32
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
     digitalWrite(5, HIGH);
  }
  delay(2000);
}

