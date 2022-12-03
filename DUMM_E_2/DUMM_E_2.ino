#include <Servo.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
char auth[] = "y52RJzeocPafu1d0N-yX_a8NpapifwaF";//Enter your Blynk auth token
char ssid[] = "IEM IEDC LAB";//Enter your WIFI name
char pass[] = "IEMIEDC501";//Enter your WIFI password
BLYNK_WRITE(V0){
  servo.write(int(param.asInt()));
  Serial.println(param.asInt());
} 
BLYNK_WRITE(V1){
  servo1.write(int(param.asInt()));
  Serial.println(param.asInt());
}
BLYNK_WRITE(V2){
  servo2.write(int(param.asInt()));
  Serial.println(param.asInt());
}
BLYNK_WRITE(V3){
  servo3.write(int(param.asInt()));
  Serial.println(param.asInt());
}
void setup() {
  pinMode(05,OUTPUT);
  pinMode(04,OUTPUT);
  pinMode(00,OUTPUT);
  pinMode(02,OUTPUT);
  
  Serial.begin(115200);
  servo1.attach(05);
  servo.attach(04);
  servo2.attach(0);
  servo3.attach(02);
  Blynk.begin(auth, ssid, pass);

}
 
void loop() {
  Blynk.run();
}
