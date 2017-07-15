#include <Arduino.h>

int Ain1 = 4;
int Ain2 = 2;
int PWMA = 3;
int Bin1 = 6;
int Bin2 = 7;
int PWMB = 5;
int button1 = 21;
int button2 = 22;
int button3 = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);


}

void loop() {


  // Pressing any button will take it out of standby and run the program
  delay(100);
  while(!(digitalRead(button1) || digitalRead(button2) || digitalRead(button3))) {
     move(0);
     Serial.println("Standby");
  }
  delay(100);

  while(!(digitalRead(button1) || digitalRead(button2) || digitalRead(button3))) {
    move(32);
  }

  
}

void move(int velocity) {
  digitalWrite(Ain1, HIGH);
  digitalWrite(Ain2, LOW);
  analogWrite(PWMA, velocity);
  digitalWrite(Bin1, LOW);
  digitalWrite(Bin2, HIGH);
  analogWrite(PWMB, velocity);
}
