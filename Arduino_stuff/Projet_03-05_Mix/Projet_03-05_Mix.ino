#include <Servo.h>
Servo  myServo;

const int sensorPin = A0;

int sensorVal;
int angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.print("La valeur du capteur de température est :");
  Serial.println(sensorVal);

  angle = map(sensorVal, 160, 180, 0, 179);       // Recalibrage de la température mesurée en valeur de l'angle (les valeurs min 
  //et max de température sont subjectives car bien que le capteur soir sur une entrée analogique, il ne variera pas entre 0 et 1023
  //mais en fonction de la température ambiante. Celle-ci est de 28° dans notre cas, et à l'aide de quelques essaies, nous avons pu 
  //redéfinir un intervalle de valeurs adéquat
  Serial.print(", l'angle est de :");  
  Serial.println(angle);

  myServo.write(angle);
  delay(1500);
}
