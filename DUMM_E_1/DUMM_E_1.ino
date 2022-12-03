#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo servo_base;
Servo servo_2A;
Servo servo_2B;
Servo servo_3A;
Servo servo_3B;
Servo servo4;
Servo servo5;
Servo servo6;

int motor_base=0;
int motor_2A=0;
int motor_2B=0;
int motor_3A=0;
int motor_3B=0;
int motor4=0;
int motor5=0;
int motor6=0;


char auth[] = "Fm9rDNbRFBw-asq2WHtc_4ip1TTR3dg8";
char ssid[] = "IEM IEDC LAB";
char pass[] = "IEMIEDC501";

 BLYNK_WRITE(V1){
  motor_base=param.asInt();
  
}
BLYNK_WRITE(V2){
  int val= param.asInt()-90;
  motor_2A=90+val;
  motor_2B=90-val;
}
BLYNK_WRITE(V3){
  int val= param.asInt()-90;
  motor_3A=90+val;
  motor_3B=90-val;
}
BLYNK_WRITE(V4){
  motor4=param.asInt();
  } 
BLYNK_WRITE(V5){
  motor5=param.asInt();
  }
BLYNK_WRITE(V6){
  motor6=param.asInt();
}
void setup() {
  pinMode(16,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(05,OUTPUT);
  pinMode(04,OUTPUT);
  Serial.begin(115200);
  servo_base.attach(16);//d0
  servo_2A.attach(05);//d1
  servo_2B.attach(04);//d2
  servo_3A.attach(00);//d3
  servo_3B.attach(02);//d4 
  servo4.attach(14);//d5
  servo5.attach(12);//d6
  servo6.attach(13);//d7
  servo_base.write(90);
  servo_2A.write(90);
  servo_2B.write(90);
  servo_3A.write(90);
  servo_3B.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(90);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() {
  Blynk.run();
  servo_base.write(motor_base);
  servo_2A.write(motor_2A);
  servo_2B.write(motor_2B);
  servo_3A.write(motor_3A);
  servo_3B.write(motor_3B);
  servo4.write(motor4);
  servo5.write(motor5);
  servo6.write(motor6);
  }
