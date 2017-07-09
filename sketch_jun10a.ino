int Ain1 = 4;
int Ain2 = 2;
int PWMA = 3;
int Bin1 = 6;
int Bin2 = 7;
int PWMB = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Ain1, HIGH);
  digitalWrite(Ain2, LOW);
  analogWrite(PWMA, 64);
  digitalWrite(Bin1, LOW);
  digitalWrite(Bin2, HIGH);
  analogWrite(PWMB, 64);
}
