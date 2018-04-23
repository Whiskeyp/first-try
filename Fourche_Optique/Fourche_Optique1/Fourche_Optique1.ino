const int pinStartStop = 3;
const int pinFourcheR  = 6;
const int pinFourcheE  = 7;
const int pinLEDrouge  = 8;
const int pinLEDverte  = 9;
const int pinLEDjaune  = 10;

boolean actif; 
int t0; 
int oldStartStop;          

void configurationAttente(){
  digitalWrite(pinLEDrouge, HIGH);
  digitalWrite(pinLEDverte, LOW);
  digitalWrite(pinLEDjaune, LOW);
  digitalWrite(pinFourcheE, LOW);
  actif = false;
  oldStartStop = LOW;
}

void setup(void) {

  Serial.begin(19200);

  pinMode(pinStartStop, INPUT);
  pinMode(pinFourcheR,  INPUT);
  pinMode(pinFourcheE,  OUTPUT);
  pinMode(pinLEDrouge,  OUTPUT); 
  pinMode(pinLEDverte,  OUTPUT);
  pinMode(pinLEDjaune,  OUTPUT);
  configurationAttente();
}

void loop() { 
  
  int fourche;
  int startStop;
  int t1;

  startStop = digitalRead(pinStartStop);
    
  if (startStop == HIGH && oldStartStop == LOW){  
    t0 = millis();
    if (actif == false){
      digitalWrite(pinLEDrouge, LOW);
      digitalWrite(pinLEDverte, HIGH);
      digitalWrite(pinLEDjaune, LOW);
      digitalWrite(pinFourcheE, HIGH);    
      actif = true;
    }
    else{ 
      configurationAttente();
      Serial.println(-1);
    }
  }
  oldStartStop = startStop;
  
  if (actif){
    //Fourche Optique

    fourche = digitalRead(pinFourcheR);
    t1 = millis();
    digitalWrite(pinLEDjaune, fourche);
    Serial.print(t1-t0);
    Serial.print("\t");
    Serial.println(fourche);
    Serial.flush();
    delay(10);
  }
}
