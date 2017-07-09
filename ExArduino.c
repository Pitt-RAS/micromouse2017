#include <ArduinoRobot.h>

// Create a motor class with constructor parameters (A1/A2)
// Use ibrary for encoders, IMU, display
void setup()
{
  Robot.begin():
  Robot.setMode(MODE_LINE_FOLLOW);
}

void moveForward(sec)
{
  Robot.motorsWrite(255, 255);
  delay(sec * 1000);
}

void moveBackward(sec)
{
  Robot.motorsWrite(-255,-255);
  delay(sec * 1000);
}

void spinRight(sec)
{
  Robot.motorsWrite(255, -255);
  delay(sec * 1000);
}

void spinLeft(sec)
{
  Robot.motorsWrite(-255, 255);
  delay(sec * 1000);
}

void turnLeft()
{
  Robot.turn(-90);
  delay(1000);
}

void turnRight()
{
  Robot.turn(90);
  delay(1000);
}

void turnAround()
{
  Robot.turn(180);
  delay(1000);
}

void playSong()
{
  char song[] = ""; // Place notes here
  Robot.playMelody(song);
}

void stop()
{
  Robot.motorsWrite(0,0);
}


// Dale stole this function off the internet
// this function will return the number of bytes currently free in RAM
int memoryTest() {
  int byteCounter = 0; // initialize a counter
  byte *byteArray; /
  
  while ( (byteArray = (byte*) malloc (byteCounter * sizeof(byte))) != NULL ) {
    byteCounter++;
    free(byteArray);
  }
  free(byteArray); /
  return byteCounter;
}

void loop()
{
  moveForward(1);
  stop();
}