#include <IRremote.h>
#include <Servo.h> 
#include "ir_akizuki.h"
#include "maruino_servo.h"

void setup()
{
  Serial.begin(115200);
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
    case b_power:  // power button
      set_servo(0);
      Serial.println("power");
      break;
    case b_A:  // A button
      set_servo(guu);
      Serial.println("A");
      break;
    case b_B:  // B button
      set_servo(choki);
      Serial.println("B");
      break; 
    case b_C:  // C button
     set_servo(paa);
      Serial.println("C");
      break;
    case b_UL:  // UpLight button
      set_servo(1);
      Serial.println("UL");
      break;
    case b_U:  // UP button
      set_servo(2);
      Serial.println("U");
      break;
    case b_UR:  // UpRight button
      set_servo(3);
      Serial.println("UR");
      break;
    case b_L:  // Left button
      set_servo(4);
      Serial.println("L");
      break;
    case b_CENT:  // Center button
      set_servo(5);
      Serial.println("CENT");
      break;
    case b_R:  // Right button
      set_servo(6);
      Serial.println("R");
      break;
    case b_DL:  // DownLest button
      set_servo(7);
      Serial.println("DL");
      break;
    case b_D:  // Down button
      set_servo(8);
      Serial.println("D");
      break;
    case b_DR:  // DownRight button
      set_servo(9);
      Serial.println("DR");
      break;

    case tenkey_00:  // from IR button
      set_servo(0);
      Serial.println("B000000");
      break;
    case tenkey_01:  // from IR button
      set_servo(1);
      Serial.println("B000001");
      break;
    case tenkey_02:  // from IR button
      set_servo(2);
      Serial.println("B000010");
      break;
    case tenkey_03:  // from IR button
      set_servo(3);
      Serial.println("B000011");
      break;
    case tenkey_04:  // from IR button
      set_servo(4);
      Serial.println("B000100");
      break;
    case tenkey_05:  // from IR button
      set_servo(5);
      Serial.println("B000101");
      break;
    case tenkey_06:  // from IR button
      set_servo(6);
      Serial.println("B000110");
      break;
    case tenkey_07:  // from IR button
      set_servo(7);
      Serial.println("B000111");
      break;
    case tenkey_08:  // from IR button
      set_servo(8);
      Serial.println("B001000");
      break;
    case tenkey_09:  // from IR button
      set_servo(9);
      Serial.println("B001001");
      break;
    case tenkey_0A:  // from IR button
      set_servo(10);
      Serial.println("B001010");
      break;
    case tenkey_0B:  // from IR button
      set_servo(11);
      Serial.println("B001011");
      break;
    case tenkey_0C:  // from IR button
      set_servo(12);
      Serial.println("B001100");
      break;
    case tenkey_0D:  // from IR button
      set_servo(13);
      Serial.println("B001101");
      break;
    case tenkey_0E:  // from IR button
      set_servo(14);
      Serial.println("B001110");
      break;
    case tenkey_0F:  // from IR button
      set_servo(15);
      Serial.println("B001111");
      break;
    case tenkey_10:  // from IR button
      set_servo(16);
      Serial.println("B010000");
      break;
    case tenkey_11:  // from IR button
      set_servo(17);
      Serial.println("B010001");
      break;
    case tenkey_12:  // from IR button
      set_servo(18);
      Serial.println("B010010");
      break;
    case tenkey_13:  // from IR button
      set_servo(19);
      Serial.println("B010011");
      break;
    case tenkey_14:  // from IR button
      set_servo(20);
      Serial.println("B010100");
      break;
    case tenkey_15:  // from IR button
      set_servo(21);
      Serial.println("B010101");
      break;
    case tenkey_16:  // from IR button
      set_servo(22);
      Serial.println("B010110");
      break;
    case tenkey_17:  // from IR button
      set_servo(23);
      Serial.println("B010111");
      break;
    case tenkey_18:  // from IR button
      set_servo(24);
       Serial.println("B011000");
     break;
    case tenkey_19:  // from IR button
      set_servo(25);
       Serial.println("B011001");
      break;
    case tenkey_1A:  // from IR button
      set_servo(26);
       Serial.println("B011010");
      break;
    case tenkey_1B:  // from IR button
      set_servo(27);
       Serial.println("B011011");
      break;
    case tenkey_1C:  // from IR button
      set_servo(28);
       Serial.println("B011100");
      break;
    case tenkey_1D:  // from IR button
      set_servo(29);
       Serial.println("B011101");
      break;
    case tenkey_1E:  // from IR button
      set_servo(30);
       Serial.println("B011110");
      break;
    case tenkey_1F:  // from IR button
      set_servo(31);
       Serial.println("B011111");
      break;
  }
}

