#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

// Fourche Optique
const int pinStartStop = 3;
const int pinFourcheR1  = 4;
const int pinFourcheE1  = 5;
const int pinFourcheR2  = 6;
const int pinFourcheE2  = 7;
const int pinLEDrouge  = 8;
const int pinLEDverte  = 9;
const int pinLEDjaune1  = 10;
const int pinLEDjaune2  = 11;

boolean actif; 
int t0; 
int oldStartStop;          

void configurationAttente(){
  digitalWrite(pinLEDrouge, HIGH);
  digitalWrite(pinLEDverte, LOW);
  digitalWrite(pinLEDjaune1, LOW);
  digitalWrite(pinLEDjaune2, LOW);
  digitalWrite(pinFourcheE1, LOW);
  digitalWrite(pinFourcheE2, LOW);
  actif = false;
  oldStartStop = LOW;
}

void setup(void) {
  Serial.begin(9600);
  
//Fourche Optique
  pinMode(pinStartStop, INPUT);
  pinMode(pinFourcheR1,  INPUT);
  pinMode(pinFourcheE1,  OUTPUT);
  pinMode(pinFourcheR2,  INPUT);
  pinMode(pinFourcheE2,  OUTPUT);
  pinMode(pinLEDrouge,  OUTPUT); 
  pinMode(pinLEDverte,  OUTPUT);
  pinMode(pinLEDjaune1,  OUTPUT);
  pinMode(pinLEDjaune2,  OUTPUT);
  configurationAttente();

//Accéléromètre
  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  mma.setRange(MMA8451_RANGE_2_G);
}

void loop() {
  
  int Fourche1;
  int Fourche2;
  int StartStop;
  int t1;
  int t2;

  StartStop = digitalRead(pinStartStop);
    
  if (StartStop == HIGH && oldStartStop == LOW){  
    t0 = millis();
    if (actif == false){
      digitalWrite(pinLEDrouge, LOW);
      digitalWrite(pinLEDverte, HIGH);
      digitalWrite(pinLEDjaune1, LOW);
      digitalWrite(pinLEDjaune2, LOW);
      digitalWrite(pinFourcheE1, HIGH); 
      digitalWrite(pinFourcheE2, HIGH);
      actif = true;
    }
    else{ 
      configurationAttente();
      Serial.println(-1);
    }
  }
  oldStartStop = StartStop;
  
  if (actif){
    
  sensors_event_t event; 
  mma.getEvent(&event);
  
  Fourche1 = digitalRead(pinFourcheR1);
  t1 = millis();
  digitalWrite(pinLEDjaune1, Fourche1);
  
  Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.print(t1-t0); Serial.print("\t");
  Serial.println();
  Serial.flush();
  delay(100);
  }
}
