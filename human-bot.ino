#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


#define LEFT_BOTTOM_FOOT  0 //левая стопа
#define LEFT_BOTTOM_BEND  1 //левое колено
#define LEFT_BOTTOM_HAUNCH  2  //левое бедро

#define RIGHT_BOTTOM_FOOT  4 //правая стопа
#define RIGHT_BOTTOM_BEND  5 //правое колено
#define RIGHT_BOTTOM_HAUNCH  6  //правое бедро


#define FOOT_BOTTOM_SERVOMIN  200 // минимальный угол поворота стопы назад
#define FOOT_BOTTOM_SERVOAVARAFE  300 // средний угол поворота стопы, чтобы стоят
#define FOOT_BOTTOM_SERVOMAX  400 // максимальный угол поворота стопы вперед


#define HAUNCH_BOTTOM_SERVOMIN  200 // минимальный угол поворота стопы назад
#define HAUNCH_BOTTOM_SERVOAVERAGE  300 // средний угол поворота стопы, чтобы стоят
#define HAUNCH_BOTTOM_SERVOMAX  400 // максимальный угол поворота стопы вперед


#define SERVOMIN  10 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);

  pwm.begin();  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);


  standUp();




  

//  leftBottomFootStay();
//  rightBottomFootStay();
//
//  delay(10);
//  leftBottomBendStay();
//  rightBottomBendStay();
//
//  delay(10);
//  leftBottomHaunchStay();
//  rightBottomHaunchStay();

}


void loop() {

}


/********************************
 ***     Комманда встать     ***
 ********************************/
void standUp() {


  
  pwm.setPWM(LEFT_BOTTOM_HAUNCH, 0, 230);
  pwm.setPWM(RIGHT_BOTTOM_HAUNCH, 0, 450);

  delay(100);

  pwm.setPWM(LEFT_BOTTOM_BEND, 0, 80);
  pwm.setPWM(RIGHT_BOTTOM_BEND, 0, 570);

  delay(100);

  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, 200);
  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, 450);
  
  
  
//  delay(1000);
  
//  pwm.setPWM(LEFT_BOTTOM_HAUNCH, 0, 300);
//  pwm.setPWM(RIGHT_BOTTOM_HAUNCH, 0, 350);
//
//  pwm.setPWM(LEFT_BOTTOM_BEND, 0, 300);
//  pwm.setPWM(RIGHT_BOTTOM_BEND, 0, 350);
//
//  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, 330);
//  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, 340);
}


/********************************
 ***     Комманда сесть       ***
 ********************************/
void setDown() {

  /**
   * Минимальная нижняя позиция
   */
  pwm.setPWM(LEFT_BOTTOM_HAUNCH, 0, 230);
  pwm.setPWM(RIGHT_BOTTOM_HAUNCH, 0, 450);

  delay(100);

  pwm.setPWM(LEFT_BOTTOM_BEND, 0, 80);
  pwm.setPWM(RIGHT_BOTTOM_BEND, 0, 570);

  delay(100);

  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, 200);
  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, 450);
}





/********************************
 ***     Работа с бедрами     ***
 ********************************/

void leftBottomHaunchStay() {
  Serial.println("left bottom haunch STAY");  
  pwm.setPWM(LEFT_BOTTOM_HAUNCH, 0, HAUNCH_BOTTOM_SERVOAVERAGE);
}

void rightBottomHaunchStay() {
  Serial.println("left bottom haunch STAY");  
  pwm.setPWM(RIGHT_BOTTOM_HAUNCH, 0, 320);
}


/********************************
 ***     Работа с коленями    ***
 ********************************/


void leftBottomBendStay() {
  Serial.println("left bottom bend STAY");  
  pwm.setPWM(LEFT_BOTTOM_BEND, 0, FOOT_BOTTOM_SERVOAVARAFE);
}

void rightBottomBendStay() {
  Serial.println("left bottom foot STAY");  
  pwm.setPWM(RIGHT_BOTTOM_BEND, 0, FOOT_BOTTOM_SERVOAVARAFE);
}


/********************************
 ***     Работа со стопами    ***
 ********************************/
void leftBottomFootUp() {
  Serial.println("left bottom foot UP");
  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOMAX);
}

void leftBottomFootDown() {
  Serial.println("left bottom foot DOWN");  
  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOMIN);
}

void leftBottomFootStay() {
  Serial.println("left bottom foot STAY");  
  pwm.setPWM(LEFT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOAVARAFE);
}

void rightBottomFootDown() {
  Serial.println("left bottom foot UP");
  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOMAX);
}

void rightBottomFootUp() {
  Serial.println("left bottom foot DOWN");  
  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOMIN);
}

void rightBottomFootStay() {
  Serial.println("left bottom foot STAY");  
  pwm.setPWM(RIGHT_BOTTOM_FOOT, 0, FOOT_BOTTOM_SERVOAVARAFE);
}
