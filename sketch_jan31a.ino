#include "NewPing.h"
#include "Servo.h"

#define TRIG_PIN 15
#define ECHO_PIN 14
#define MAX_DISTANCE 30

#define S0 3
#define S1 8
#define S2 13
#define S3 2

#define sensorOut 12


// Motor A pins
const int IN1 = 6;
const int IN2 = 7;
const int ENA = 11;  // PWM pin


// Motor B pins
const int IN3 = 5;
const int IN4 = 4;
const int ENB = 10;  // PWM pin
 
const  unsigned int BAUD_RATE=9600;
int angle;
bool firstPhase;
bool secondPhase;
bool thirdPhase;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo firstServo;
Servo secondServo;

void setup() {
  // Set motor control pins as outputs
 Serial.begin(9600);
 firstServo.attach(A5);   
 secondServo.attach(9);

 angle = 0;
 firstPhase = true;
 secondPhase = false;
 thirdPhase = false;
  

 pinMode(S1, OUTPUT);
 pinMode(S0, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);
 pinMode(sensorOut, INPUT);
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);


 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(ENA, OUTPUT);

 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(ENB, OUTPUT);


 // Stop motors at startup
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);


 analogWrite(ENA, 0);
 analogWrite(ENB, 0);
}

  //secondServo.write(init_angle - 20);


  //the ball yipee
  // just gonna assume down is increasing (which i alr did before anyway)
  


  /*
  if (firstPhase) {
    driveForward(50);
    if (getRedFreq() > 200 && getGreenFreq() <150 && getBlueFreq() < 150) {
      brakeEngine(250);
      firstPhase = false;
      secondPhase = true;
      // delay(1000)
      // driveForward(100)
      // delay(100)
      // stopEngine()
      // delay(100)
    }
  }
  if (secondPhase) {
    turnRightInPlace(30)
    if (getGreenFreq() > 200 && getRedFreq() < 50) {
      secondPhase = false;
      thirdPhase = true;
    }
  }
  if (thirdPhase) {

  }

  // angle += 1;
  // Serial.println(sonar.ping_cm());

  angle = 0;
  // firstServo.write(angle);  
 
  secondServo.write(angle);    
  delay(1000);
  secondServo.write(90);
  delay(1000);
  secondServo.write(180);
  delay(1000);
  
  firstServo.write(10);  
  delay(1000);
  

  // digitalWrite(S2, HIGH);
  // digitalWrite(S3, HIGH);
  // greenFrequency = pulseIn(sensorOut, LOW);
  // Serial.println(getBlueFreq());
  // Serial.println(firstServo.read());
  delay(500);
  */

int getRedFreq() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int freq = pulseIn(sensorOut, LOW);
  return freq;
  int mapped = map(freq, 125, 40, 0, 255);

// // // Clamp to be safe
  mapped = constrain(mapped, 0, 255);
  return mapped;
}

int getGreenFreq() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int freq = pulseIn(sensorOut, LOW);
  return freq;
  int greenMapped = map(freq, 125, 40, 0, 255);

// // Clamp to be safe
  greenMapped = constrain(greenMapped, 0, 255);
  return greenMapped;
}

int getBlueFreq() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int freq = pulseIn(sensorOut, LOW);
  return freq;
  int mapped = map(freq, 125, 40, 0, 255);

// // // Clamp to be safe
  mapped = constrain(mapped, 0, 255);
  return mapped;
}

void driveBackward(int power) {
  // Left is backwards
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, power);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, power);
}

void brakeEngine (int power) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(20);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, power);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, power);
}
void stopEngine () {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void driveForward(int power) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, power);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, power);
}




void turnRight(int power) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, power);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, power);
}

void turnLeftInPlace(int power) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, power);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, power);
}

void turnRightInPlace(int power) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, power);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, power);
}

void turnLeft(int power) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, power);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, power);
}

bool condition;
bool condition2;
int r, g, b;
void loop() {
  // 50 is not enough to move, need higher power
  //turnRightInPlace(50);
  //delay(5000);
  //stopEngine();
  //pick the box
  int init_angle = 10;
  r = getRedFreq();
  g = getGreenFreq();
  b = getBlueFreq();
  Serial.print(r);
  Serial.print (" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.println(b);

  delay(3000);
  driveForward(255);
  delay(10000);
  // driveBackward(100);
  // delay(10000);
  int pow = 250;
  secondServo.write(70);
  while (pow > 50) {
    turnRight(pow);
    delay(3000);
    pow-=25;
  }
  
  
  /*
  if (r < 0.5 * g && r < 0.5 * b) {
    condition = true;
  }

  if (g < 0.5 * r && g < 0.5 * b) {
    condition2 = true;
  }
  
  if (condition) {
    brakeEngine(100);
    delay(100);
    turnRightInPlace(100);
    delay(200);
    if (condition2) {
      brakeEngine(100);
      delay(100);
      driveForward(60);
    }
  }
  */
  // turnRight(250);

  // driveForward(50);
  // if (getRedFreq() > 200 && getGreenFreq() <150 && getBlueFreq() < 150) {
  //     brakeEngine(250);
  //     firstPhase = false;
  //     secondPhase = true;
  //     delay(1000)
  //     driveForward(100)
  //     delay(100)
  //     stopEngine()
  //     delay(100)
  // }
  // secondServo.write(init_angle);
  // delay(500);
  // secondServo.write(init_angle-50);
  // delay(500);
  // int distance = sonar.ping_cm();
  // turnRightInPlace(100);
  // delay(100);
  // //Serial.println(distance);
  // if (abs(distance - sonar.ping_cm()) <= 4 && (6 <= distance && distance <= 12)){
  //   driveForward(10);
  //   delay(50);
  //   secondServo.write(init_angle - 50);
  //   driveForward(100);
  //   delay(2000);
  // }
}
