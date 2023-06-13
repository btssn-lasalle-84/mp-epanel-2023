// commande moteur pas à pas bipolaire avec Arduino-MotorShield
#include <Arduino.h>
#include <SoftwareSerial.h>
#define DIRA 12
#define DIRB 13
#define BRAKEA 9
#define BRAKEB 8 
#define PWMA 3
#define PWMB 11
#define VAL 100
#define ILSPORT1 2
#define ILSPORT2 3
#define ILSPORT3 4
#define ILSPORT4 5
#define ILSPORT5 6
#define ILSPORT6 7
#define ILSPORT7 8
#define ILSPORT8 9
int destination;

int etape;

void pas_une_phase(int etape)  // pas One Phase ON
{
   switch (etape) {
      case 0 : // 1000
        digitalWrite(BRAKEA,LOW);
        digitalWrite(BRAKEB,HIGH);
        digitalWrite(DIRA,HIGH);
        break;
      case 1 : // 0010
        digitalWrite(BRAKEA,HIGH);
        digitalWrite(BRAKEB,LOW);
        digitalWrite(DIRB,HIGH);
        break;
      case 2 : // 0100
        digitalWrite(BRAKEA,LOW);
        digitalWrite(BRAKEB,HIGH);
        digitalWrite(DIRA,LOW);
        break;
      case 3 : // 0001
        digitalWrite(BRAKEA,HIGH);
        digitalWrite(BRAKEB,LOW);
        digitalWrite(DIRB,LOW);
        break;
   }  
}
void pas_une_phase_sens_1() 
{
    etape++;
    if (etape > 3) etape = 0;
    pas_une_phase(etape);  
}
void pas_une_phase_sens_2() 
{
  etape--;
  if (etape < 0) {
    etape = 3;
  }
  pas_une_phase(etape);  
}

void pwm(int pwm) 
{
  analogWrite(PWMA, pwm);
  analogWrite(PWMB, pwm); 
}

void rotationSimple(int sens) 
{
  int k;
  unsigned int duree_courant = 5; //temps d'allumage d'une bobine
  unsigned long duree_pas = 1; //temps que met un pas a se faire 
  unsigned long temps;
  for (k = 0; k < 1; k++) {
    temps = millis();
    if (sens == 1) {
      pas_une_phase_sens_1();
    } else {
      pas_une_phase_sens_2();
    }
    pwm(255); // courant max
    while (millis() - temps < duree_courant) {
      // autre chose à faire pendant le pas moteur
    }
    pwm(0); // courant de repos, en fonction de la charge
    while (millis() - temps < duree_pas) {
      // autre chose à faire pendant le pas moteur
    }
    delay(0);
  }
}
void rotation45(int sens, int pasMax) 
{
  int k;
  unsigned int duree_courant = 2; //temps d'allumage d'une bobine
  unsigned long duree_pas = 1; //temps que met un pas a se faire 
  unsigned long temps;
  for (k = 0; k < pasMax; k++) {
    temps = millis();
    if (sens == 1) 
    {
      pas_une_phase_sens_1();
    } else {
      pas_une_phase_sens_2();
    }
    pwm(255); // courant max
    while (millis() - temps < duree_courant) 
    {
      // autre chose à faire pendant le pas moteur
    }
    pwm(0); // courant de repos, en fonction de la charge
    while (millis() - temps < duree_pas) 
    {
      // autre chose à faire pendant le pas moteur
    }
    delay(1000);
  }
}
void initialisation() {
  Serial.println(digitalRead(ILSPORT1));
  while (digitalRead(ILSPORT1) == HIGH) 
  {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
  delay(3000);
}

void setup() 
{
  Serial.begin (9600); 
  pinMode(DIRA,OUTPUT); 
  pinMode(DIRB,OUTPUT);
  pinMode(BRAKEA,OUTPUT);
  pinMode(BRAKEB,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(ILSPORT1,INPUT);
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  etape = 0;
 // initialisation();
}

//définition des fonction cardinals
void rotationN() 
{
  Serial.println(digitalRead(ILSPORT1));
  while (digitalRead(ILSPORT1) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }


}

void rotationNE()
{
  Serial.println(digitalRead(ILSPORT2));
  while (digitalRead(ILSPORT2) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationE() 
{
  Serial.println(digitalRead(ILSPORT3));
  while (digitalRead(ILSPORT3) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationSE() 
{
  Serial.println(digitalRead(ILSPORT4));
  while (digitalRead(ILSPORT4) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationS() 
{
  Serial.println(digitalRead(ILSPORT5));
  while (digitalRead(ILSPORT5) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationSO() 
{
  Serial.println(digitalRead(ILSPORT6));
  while (digitalRead(ILSPORT6) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationO() 
{
  Serial.println(digitalRead(ILSPORT7));
  while (digitalRead(ILSPORT7) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void rotationNO() 
{
  Serial.println(digitalRead(ILSPORT8));
  while (digitalRead(ILSPORT8) == HIGH) {
    rotationSimple(1);
    pwm(0); // courant de repos, en fonction de la charge
  }
}

void loop() 
{
  //rotation45(1,1000);

  etape=0;
    if (Serial.available())
  {
    etape = Serial.read();
    Serial.println(etape);
  }
  switch (etape)
  {
    case 49:
      Serial.println("NORD");
      rotationN();
      break;
    case 50:
      Serial.println("NORD-EST");
      rotationNE();
      break;
    case 51:
      Serial.println("EST");
      rotationE();
      break;
    case 52:
      Serial.println("SUD-EST");
      rotationSE();
      break;
    case 53:
      Serial.println("SUD");
      rotationS();
      break;
    case 54:
      Serial.println("SUD-OUEST");
      rotationSO();
      break;
    case 55:
      Serial.println("OUEST");
      rotationO();
      break;
    case 56:
      Serial.println("NORD-OUEST");
      rotationNO();
      break;

    default:
      break;
  }
}