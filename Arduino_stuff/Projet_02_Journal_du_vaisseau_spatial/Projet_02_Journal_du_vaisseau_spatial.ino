int switchState = 0;      //Définir une variable pour le bouton poussoir

void setup() {
  pinMode(3,OUTPUT);      //Configurer les LEDs en tant que sorties
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);       //Configurer l'interrupteur en tant qu'entrée
}

void loop() {
  switchState = digitalRead(2);   //Lire la valeur du bouton poussoir et la stocker dans la variable switchState
  
  if (switchState == LOW) {       //Si switchState est de 0, pas d'appui sur BP
    digitalWrite(3,HIGH);         //Allumer la LED en sortie 3
    digitalWrite(4,LOW);          //Eteindre la LED en sortie 4
    digitalWrite(5,LOW);
  }
  else {                          //Si elle est de 1, appui sur BP
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);

    delay(250);                  //Mettre en pause le programme pendant un délai de 250/1000 seconde (soit 0.25s)

    digitalWrite(4,HIGH);         //Faire clignoter les LEDs 4 et 5
    digitalWrite(5,LOW);

    delay(250);
  }
    
}                                // Retour au début de la boucle loop
