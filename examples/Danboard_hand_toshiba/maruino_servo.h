// File Name: maruino_servo.h
#ifndef MARUINO_SERVO_H
#define MARUINO_SERVO_H

// Maruino Servo Shield Pin define
#define SRVO_PIN1 A1
#define SRVO_PIN2 A2
#define SRVO_PIN3 A3
#define SRVO_PIN4 3
#define SRVO_PIN5 5
#define SRVO_PIN6 6

// twelve servo objects can be created on most boards
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 
Servo myservo3;  // create servo object to control a servo 
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo
Servo myservo6;  // create servo object to control a servo

// Servo Parameter
const int pos_ini1 = 5;
const int pos_ini2 = 5;
const int pos_ini3 = 5;
const int pos_ini4 = 5;
const int pos_ini5 = 5;
const int pos_ini6 = 5;

const int pos_max1 = 125;
const int pos_max2 = 125;
const int pos_max3 = 115;
const int pos_max4 = 125;
const int pos_max5 = 105;
const int pos_max6 = 125;

// Finger Pattern
const int guu = B11111;
const int choki = B11001;
const int paa = B00000;
const int guwashi = B10100;

void setLedColor(int color);

// attaches the servo on Auduino pin to the servo object
void attach_servo()
{
  myservo1.attach(SRVO_PIN1);
  myservo2.attach(SRVO_PIN2);
  myservo3.attach(SRVO_PIN3);
  myservo4.attach(SRVO_PIN4);
  myservo5.attach(SRVO_PIN5);
  myservo6.attach(SRVO_PIN6);
}

// detaches the servo on Auduino pin to the servo object
void detach_servo()
{
  myservo1.detach();
  myservo2.detach();
  myservo3.detach();
  myservo4.detach();
  myservo5.detach();
  myservo6.detach();
}

// Move Servo
void set_servo(int finger) 
{
  if(finger & B00001 == 1){
    myservo1.write(pos_max1);
  }else{
    myservo1.write(pos_ini1);
  }
    
  if((finger >> 1) & B00001 == 1){
    myservo2.write(pos_max2);
  }else{
    myservo2.write(pos_ini2);
  }

  if((finger >> 2) & B00001 == 1){
    myservo3.write(pos_max3);
  }else{
    myservo3.write(pos_ini3);
  }

  if((finger >> 3) & B00001 == 1){
    myservo4.write(pos_max4);
  }else{
    myservo4.write(pos_ini4);
  }

  if((finger >> 4) & B00001 == 1){
    myservo5.write(pos_max5);
  }else{
    myservo5.write(pos_ini5);
  }
  if((finger >> 5) & B00001 == 1){
    myservo6.write(pos_max6);
  }else{
    myservo6.write(pos_ini6);
  }
}

// Random Pattern
void set_servo_random() 
{
  int i;
  int rnd;
  randomSeed(millis());

  for(i=0; i<32; i++){
    rnd = random(32);
    setLedColor(rnd % 8);
    set_servo(rnd);
    delay(500);
  }
  delay(1000);
  setLedColor(0);
  set_servo(0);
}

// Binary countup
void set_servo_countup() 
{
  int i;

  for(i=0; i<32; i++){
    setLedColor(i % 8);
    set_servo(i);
    delay(500);
  }
  delay(1000);
  setLedColor(0);
  set_servo(0);
}

// Jan-ken
void set_servo_shobu() 
{
  int x = millis() % 3;

  switch(x){
    case 0: setLedColor(4); set_servo(guu); break;
    case 1: setLedColor(1); set_servo(choki); break;
    case 2: setLedColor(2);set_servo(paa); break;
  }
}

#endif
