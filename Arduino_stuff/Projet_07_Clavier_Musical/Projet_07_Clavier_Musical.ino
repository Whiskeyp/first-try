const int sensorPin = A0;        //Définir une constante pour l'entrée analogique
int notes[] = {262,294,330,394}; //Définir un tableau avec les valeurs de fréquence des notes de musique

void setup() {
  Serial.begin(9600);           //Vitesse de communication
}

void loop() {
  int keyVal = analogRead(sensorPin);  //Lire la valeur de l'entrée analogique
  Serial.println(keyVal);

  if(keyVal == 1023){
    tone(8, notes[0]);                 //Emettre la note 0 du tableau (262 Hz) sur la sortie digitale
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
  else{
    noTone(8);
  }
}
