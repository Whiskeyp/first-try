#include <LiquidCrystal.h>
// Pour plus d'infos : https://www.arduino.cc/en/Reference/LiquidCrystal
// Creer une instance pour la bibliothèque et préciser les broches utilisées,
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

// Définir un caractère spécialdéfinir avec un tableau de 8 byte, un par ligne
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);    // Préciser la taille de l'écran LCD (16 colonnes par 2 lignes)
  pinMode(switchPin, INPUT);

  // Afficher un message de bienvenue
  lcd.print("Bonjour mon");
  lcd.setCursor(0, 1);
  lcd.print("dromadaire");
  lcd.createChar(1, smiley);    // Créer le caractère spécial,
  lcd.setCursor(12, 1);
  lcd.write(byte(1));     // Afficher le caractère spécial
  delay(2000);
  lcd.clear();    // Effacer l'écran
  lcd.clear();

  // Afficher un message d'introduction
  lcd.print("Demande a la ");    // Afficher ce texte sur la première ligne
  lcd.setCursor(0, 1);    // Mettre le curseur au début de la deuxième ligne
  lcd.print("paquerette !");   // Afficher ce texte sur la deuxième ligne
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {   // Si la valeur de l'interrupteur change
    if (switchState == LOW) {     // Et qu'il est à l'état LOW
        reply = random(8);    // Donner un nombre aléatoire entre 0 et 7

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Je t'aime :");
      lcd.setCursor(0, 1);

      switch(reply){    // Effectuer l'action suivante en fonction du résultat de reply
        case 0 :
        lcd.print("A la folie !");
        break;
        
        case 1 :
        lcd.print("Passionnement");
        break;

        case 2 :
        lcd.print("Enormement");
        break;

        case 3 :
        lcd.print("Beaucoup");
        break;

        case 4 :
        lcd.print("A l'exces");
        break;

        case 5 :
        lcd.print("Tellement");
        break;

        case 6 :
        lcd.print("Completement");
        break;

        case 7 :
        lcd.print("Pas du tout");
        break;
      }
    }
  }

  prevSwitchState = switchState;
}
