#include <AFMotor.h>

AF_DCMotor RightMotors(3, MOTOR12_1KHZ);
AF_DCMotor LeftMotors(4, MOTOR12_1KHZ);


#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>


#define EN_L 9
#define IN1_L 10
#define IN2_L 11

#define EN_R 8
#define IN1_R 12
#define IN2_R 13


double w_r = 0, w_l = 0;

//wheel_rad is the wheel radius ,wheel_sep is
double wheel_rad = 0.0325, wheel_sep = 0.295;


ros::NodeHandle nh;
int lowSpeed = 200;
int highSpeed = 50;
double speed_ang = 0, speed_lin = 0;

void messageCb( const geometry_msgs::Twist& msg) {
  speed_ang = msg.angular.z;
  speed_lin = msg.linear.x;
  w_r = (speed_lin / wheel_rad) + ((speed_ang * wheel_sep) / (2.0 * wheel_rad));
  w_l = (speed_lin / wheel_rad) - ((speed_ang * wheel_sep) / (2.0 * wheel_rad));
}


ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );
void Motors_init();
void MotorL(int Pulse_Width1);
void MotorR(int Pulse_Width2);

void setup() {

  Motors_init();
  nh.initNode();
  nh.subscribe(sub);
  RightMotors.setSpeed(250);
  LeftMotors.setSpeed(250);

}


void loop() {
  Motors(w_l * 10, w_r * 10);
  nh.spinOnce();

}


void Motors_init() {

  pinMode(EN_L, OUTPUT);
  pinMode(EN_R, OUTPUT);
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);
  pinMode(IN1_R, OUTPUT);
  pinMode(IN2_R, OUTPUT);
  digitalWrite(EN_L, LOW);
  digitalWrite(EN_R, LOW);
  digitalWrite(IN1_L, LOW);
  digitalWrite(IN2_L, LOW);
  digitalWrite(IN1_R, LOW);
  digitalWrite(IN2_R, LOW);

}

void Motors(int Pulse_Width1, int Pulse_Width2) {
  
  if (Pulse_Width1 > 0 && Pulse_Width2 > 0) {
    Forward();
  }
  
  if (Pulse_Width1 < 0 && Pulse_Width2 < 0) {
    Backward();
  }
  
  if (Pulse_Width1 > 0 && Pulse_Width2 < 0) {
    RightTurn();
  }
  
  if (Pulse_Width1 < 0 && Pulse_Width2 > 0) {
    LeftTurn();
  }

  if (Pulse_Width1 == 0 && Pulse_Width2 == 0) {
    Stop();
  }

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
