#include <AFMotor.h>

AF_DCMotor RightMotors(3, MOTOR12_1KHZ);
AF_DCMotor LeftMotors(4, MOTOR12_1KHZ);

char t;

void setup()
{

  Serial.begin(9600);

  RightMotors.setSpeed(250);
  LeftMotors.setSpeed(250);
}

void loop()
{
  Forward();
  delay(1000);
  Backward();
  delay(1000);
  LeftTurn();
  delay(1000);
  RightTurn();
  delay(1000);
  Stop();
  delay(1000);
}

void Stop()
{
  RightMotors.run(RELEASE);
  LeftMotors.run(RELEASE);
}

void Forward()
{
  RightMotors.run(FORWARD);
  LeftMotors.run(FORWARD);
  RightMotors.setSpeed(200);
  LeftMotors.setSpeed(200);
}

void Backward()
{
  RightMotors.run(BACKWARD);
  LeftMotors.run(BACKWARD);
  RightMotors.setSpeed(200);
  LeftMotors.setSpeed(200);
}

void RightTurn()
{
  RightMotors.run(FORWARD);
  LeftMotors.run(BACKWARD);
  RightMotors.setSpeed(200);
  LeftMotors.setSpeed(200);
}

void LeftTurn()
{
  RightMotors.run(BACKWARD);
  LeftMotors.run(FORWARD);
  RightMotors.setSpeed(200);
  LeftMotors.setSpeed(200);
}
