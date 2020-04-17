
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  570 // this is the 'maximum' pulse length count (out of 4096)

uint8_t servonum = 0;

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}

void loop() {
//
for(int i=0;i<8;i+=2)
{
  pwm.setPWM(i, 0, angleToPulse(45) );
}
for(int i=1; i<8; i+=2)
  {
        pwm.setPWM(i, 0, angleToPulse(170) );      
    }
// 
//  }
 
  // wait for 1 second
 
}
