#include <Arduino.h>

#define RANGE_SENSOR_ON_TIME 50 // length of LED pulse
#define RANGE_SENSOR_OFF_TIME 250 // time between pulses


int Ain1 = 4;
int Ain2 = 2;
int PWMA = 3;
int Bin1 = 6;
int Bin2 = 7;
int PWMB = 5;
int button1 = 21;
int button2 = 22;
int button3 = 23;
int sensorData = 0;

int emitterPin1 = 29;
int sensorPin1 = A14;

int emitterPin2 = 30;
int sensorPin2 = 14;

int emitterPin3 = 31;
int sensorPin3 = 15;

int emitterPin4 = 32;
int sensorPin4 = 16;

int emitterPin5 = 33;
int sensorPin5 = 17;

long last_reading_time = 0;

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

  // put your main code here, to run repeatedly:

  delay(100);
  while(!(digitalRead(button1) || digitalRead(button2) || digitalRead(button3))) {
     move(0);
     Serial.println("Standby");
  }
  delay(100);

  while(!(digitalRead(button1) || digitalRead(button2) || digitalRead(button3))) {
    /*
    move(32);
    delay(1000);
    move(0);
    delay(1000);
    */
    delay(100);
    getSensorData(sensorPin1, emitterPin1);
    //getSensorData(sensorPin2, emitterPin2);
    getSensorData(sensorPin3, emitterPin3);
    //getSensorData(sensorPin4, emitterPin4);
    getSensorData(sensorPin5, emitterPin5);
    Serial.println();
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

int getSensorData(int pin, int emitterPin) {
  float off_reading, on_reading;
  
  while (micros() - last_reading_time < RANGE_SENSOR_OFF_TIME) {
    // wait until this sensor has been off for long enough to turn it on again
  }
  
  off_reading = analogRead(pin);
  //Serial.println(off_reading);
  digitalWrite(emitterPin, HIGH);

  delayMicroseconds(RANGE_SENSOR_ON_TIME);
  
  on_reading = analogRead(pin);
  //Serial.println(on_reading);
  digitalWrite(emitterPin, LOW);
  last_reading_time = micros();
  //Serial.println(last_reading_time);
  Serial.print(pin);
  Serial.print("\tOn: ");
  Serial.print(on_reading);
  Serial.print("\tOff: ");
  Serial.print(off_reading);
  Serial.print("\tNet: ");
  Serial.print(on_reading - off_reading);
  Serial.println();
  return on_reading - off_reading;
}

