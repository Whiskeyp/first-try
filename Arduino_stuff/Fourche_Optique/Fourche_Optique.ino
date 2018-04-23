int etat;
int oldEtatBP;

const int WAIT = 0;
const int START = 1;
const int STOP = 2;

const int pinBP = 3;
const int pinRecepteur = 4;
const int pinDiode = 5;
const int pinLEDR = 6;
const int pinLEDV = 7;
const int pinLEDJ = 8;


void setup() {
 pinMode(pinBP, INPUT);
 pinMode(pinRecepteur, INPUT);
 pinMode(pinLEDR, OUTPUT);
 pinMode(pinLEDV, OUTPUT);
 pinMode(pinLEDJ, OUTPUT);
 pinMode(pinDiode, OUTPUT);

 etat = WAIT;
 oldEtatBP = LOW;
 digitalWrite(pinLEDR, LOW);
 digitalWrite(pinLEDV, LOW);
 digitalWrite(pinLEDJ, LOW);
 digitalWrite(pinDiode, LOW);
}

void loop() {
  int etatBP = digitalRead(pinBP);
 
  if(oldEtatBP == LOW && etatBP == HIGH){
    if (etat == WAIT || etat == STOP){
      etat = START;
      digitalWrite(pinLEDV, HIGH);
      digitalWrite(pinLEDR, LOW);
      digitalWrite(pinDiode, HIGH);
     }
    else {
      etat = STOP;
      digitalWrite(pinLEDV, LOW);
      digitalWrite(pinLEDR, HIGH);
      digitalWrite(pinDiode, LOW);
      digitalWrite(pinLEDJ, LOW);
      digitalWrite(pinRecepteur, LOW);
     }
 }
    if (etat == START){
          digitalWrite(pinLEDJ, digitalRead(pinRecepteur));
     }
      oldEtatBP = etatBP;
      delay(100);
}
