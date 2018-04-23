 //Variables globales
int etat;
int oldEtatBP;

//Les constantes :
//Les 3 états de l'automate :
const int WAIT = 0;
const int START = 1;
const int STOP = 2;
//Les numéros des broches E/S :
const int pinBP = 3;
const int pinLEDR = 4;
const int pinLEDV = 5;

//Configuration :
void setup() {
  //Configuration des E/S :
  pinMode(pinBP, INPUT);
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDV, OUTPUT);
  //Configuration Etat Initial (WAIT) :
  etat = WAIT;
  oldEtatBP = LOW;
  digitalWrite(pinLEDR, LOW);
  digitalWrite(pinLEDV, LOW);
}

//Partie active
void loop() {
  int etatBP = digitalRead(pinBP);//lecture état courant du BP
  
  if(oldEtatBP == LOW && etatBP == HIGH){ //l'état du BP passe de LOW à HIGH en une boucle de temps (il est appuyé, front montant)
    if (etat == WAIT || etat == STOP){
      etat = START;
      digitalWrite(pinLEDR, LOW);
      digitalWrite(pinLEDV, HIGH);
     }
    else {
      etat = STOP;
      digitalWrite(pinLEDR, HIGH);
      digitalWrite(pinLEDV, LOW);
     }
      oldEtatBP = etatBP;
      delay(100);
   }
}
