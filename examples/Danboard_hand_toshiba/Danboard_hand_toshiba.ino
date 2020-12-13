#include <IRremote.h>
#include <Servo.h> 
#include "ir_toshiba.h"
#include "maruino_servo.h"

#define LED_PIN_R 13
#define LED_PIN_G  2
#define LED_PIN_B  9

const int brt_max = 128;

void setup()
{
  Serial.begin(9600);
  Serial.println("Maruino with Servo Shield");
  irrecv.enableIRIn(); // Start the receiver

  // attaches the servo on Auduino pin to the servo object
  attach_servo();

  // Servo position set to initial position
  myservo1.write(pos_ini1);
  myservo2.write(pos_ini2);
  myservo3.write(pos_ini3);
  myservo4.write(pos_ini4);
  myservo5.write(pos_ini5);
  myservo6.write(pos_ini6);

  // LED setup
  pinMode(LED_PIN_R, OUTPUT);
  pinMode(LED_PIN_G, OUTPUT);
  pinMode(LED_PIN_B, OUTPUT);

  setLedColor(1);
  delay(1000);

  setLedColor(2);
  delay(1000);

  setLedColor(4);
  delay(1000);

  setLedColor(0);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    button_det(results.value);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

void button_det(int code) 
{
  switch(code){
    case b_blue:  // blue button
      setLedColor(4);
      set_servo(guu);
      break;
    case b_red:  // red button
      setLedColor(1);
      set_servo(choki);
      break; 
    case b_green:  // green button
     setLedColor(2);
     set_servo(paa);
      break;
    case b_yellow:  // yellow button
      setLedColor(3);
      set_servo(guwashi);
      break;
    case tenkey_01:  // 1 button
      set_servo(1);
      break;
    case tenkey_02:  // 2 button
      set_servo(2);
      break;
    case tenkey_03:  // 3 button
      set_servo(3);
      break;
    case tenkey_04:  // 4 button
      set_servo(4);
      break;
    case tenkey_05:  // 5 button
      set_servo(5);
      break;
    case tenkey_06:  // 6 button
      set_servo(6);
      break;
    case tenkey_07:  // 7 button
      set_servo(7);
      break;
    case tenkey_08:  // 8 button
      set_servo(8);
      break;
    case tenkey_09:  // 9 button
      set_servo(9);
      break;
    case tenkey_10:  // 10 button
      set_servo(10);
      break;
    case tenkey_11:  // 11 button
      set_servo(11);
      break;
    case tenkey_12:  // 12 button
      set_servo(12);
      break;
    case b_kettei:  // kettei button
      set_servo_shobu();
      break;
    case b_qmenu:  // quick menu button
      set_servo_countup();
      break;
    case b_return:  // return button
//      set_servo_random();
      myservo1.write(pos_max1);
      delay(500);
      myservo1.write(pos_ini1);
      delay(500);
      myservo2.write(pos_max2);
      delay(500);
      myservo2.write(pos_ini2);
      delay(500);
      myservo3.write(pos_max3);
      delay(500);
      myservo3.write(pos_ini3);
      delay(500);
      myservo4.write(pos_max4);
      delay(500);
      myservo4.write(pos_ini4);
      delay(500);
      myservo5.write(pos_max5);
      delay(500);
      myservo5.write(pos_ini5);
      delay(500);
      myservo6.write(pos_max6);
      delay(500);
      myservo6.write(pos_ini6);
      delay(500);
      break;
  }
}

void setLedColor(int color){
  digitalWrite(LED_PIN_R, color & B001);
  digitalWrite(LED_PIN_G, color & B010);
  digitalWrite(LED_PIN_B, color & B100);
}

