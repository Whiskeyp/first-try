                             //Algorithme : comment on résout le problème
#include <Servo.h>

//Variables globales (déclarées dans toutes les fonctions de l'algorithme)
int angleSM;

ServoSM

//Constantes
const int pinServo = 9; //broche servomoteur

const int pinInterPlus = 2; //broches interrupteurs
const int pinInterMoins = 3;

const int pinLEDR = 4; //broches LEDs
const int pinLEDV = 5;

void setup() { //établir l'état initial      

//Paramètres des E/S
  pinMode(pinInterPlus, INPUT); //InterPlus
  pinMode(3, INPUT); //InterMoins
//Configurer: pinInterPlus & pinInterMoins en entrée
  pinMode(pinLEDR, OUTPUT); //LEDR
  pinMode(pinLEDV, OUTPUT); //LEDV
//Configurer : pinLEDR & pinLEDV en sortie

  angleSM = 90;//angle du servomoteur
//éteindre les 2 LEDs
  digitalWrite(pinLEDR, LOW);
  digitalWrite(pinLEDV, LOW);
}

void loop() {

//Lire les interrupteurs
  int interPlus = digitalRead(pinInterPlus);
  int interMoins = digitalRead(pinInterMoins);
 
//Partie active algorithme
if (interPlus == HIGH && interMoins == LOW){
  digitalWrite(pinLEDR, HIGH);  //allumer LEDR
  if (angleSM < 180){
    angleSM++; //incrémenter angleSM de 1
   }
}

else if(interPlus == LOW && interMoins == HIGH){
 digitalWrite(pinLEDV, HIGH);  //allumer LEDV
 if (angleSM > 0){
   angleSM--); //décrémenter angleSM de 1
  }
}

else if(interPlus == HIGH && interMoins == HIGH){
 digitalWrite(pinLEDR, HIGH);
 digitalWrite(pinLEDV, HIGH);
 angleSM = 90;
}

else { //(interPlus == LOW && interMoins == LOW)
  digitalWrite(pinLEDR, LOW);
  digitalWrite(pinLEDV, LOW);
}

servoM.write(angleSM);
delay(200);

}//fin de la fonction loop
