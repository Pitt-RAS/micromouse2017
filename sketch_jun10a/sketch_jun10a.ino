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
  Serial.begin(BAUD);
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
  // put your main code here, to run repeatedly:
  bool b1 = false;
  bool b2 = false;
  bool b3 = false;
  while(!(b1 || b2 || b3)) {
    if (digitalRead(button1)) {
      Serial.println("b1\n");
      b1 = true;
    }
    if (digitalRead(button2)) {
      Serial.println("b2\n");
      b2 = true;
    }
    if (digitalRead(button3)) {
      Serial.println("b3\n");
      b3 = true;
    }
  }
  move(32);
  delay(1000);
  move(0);
  delay(1000);
}

void move(int velocity) {
  digitalWrite(Ain1, HIGH);
  digitalWrite(Ain2, LOW);
  analogWrite(PWMA, velocity);
  digitalWrite(Bin1, LOW);
  digitalWrite(Bin2, HIGH);
  analogWrite(PWMB, velocity);
}
