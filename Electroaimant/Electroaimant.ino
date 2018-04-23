int etat;
int oldEtatBP;

const int WAIT = 0;
const int START = 1;
const int STOP = 2;

const int pinBP = 3;
const int pinLEDR = 4;
const int pinLEDV = 5;
const int pinEA = 6;

void setup() {
 pinMode(pinBP, INPUT);
 pinMode(pinLEDR, OUTPUT);
 pinMode(pinLEDV, OUTPUT);
 pinMode(pinEA, OUTPUT);

 etat = WAIT;
 oldEtatBP = LOW;
 digitalWrite(pinLEDR, LOW);
 digitalWrite(pinLEDV, LOW);
 digitalWrite(pinEA, LOW);
}

void loop() {
  int etatBP = digitalRead(pinBP);
  
  if(oldEtatBP == LOW && etatBP == HIGH){
    if (etat == WAIT || etat == STOP){
      etat = START;
      digitalWrite(pinLEDR, HIGH);
      digitalWrite(pinLEDV, LOW);
      digitalWrite(pinEA, HIGH);
     }
    else {
      etat = STOP;
      digitalWrite(pinLEDR, LOW);
      digitalWrite(pinLEDV, HIGH);
      digitalWrite(pinEA, LOW);
     }
   }
      oldEtatBP = etatBP;
      delay(100);
}
