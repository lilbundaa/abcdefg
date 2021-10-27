#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define LED D1
#define LED1 D2
 
char auth[] = "rjFtkVRLuS0GqT2Yf8dvV7vzYn8mJBL7";
char ssid[] = "AGHIKA";
char pass[] = "4y4h1buku";
char server[] = "blynk-cloud.com";
int port = 8080;
 
BlynkTimer timer;
WidgetLCD lcd(V1);
 
void SendSensor(){
  bool StateLED = digitalRead(LED);
  bool StateLED1 = digitalRead(LED1);
  if(StateLED == HIGH && StateLED1 == LOW){
    lcd.clear();
    lcd.print(1, 0, "LED 1 Menyala"); 
    lcd.print(1, 1, "LED 2 Mati"); 
  } else if(StateLED == LOW && StateLED1 == HIGH){
    lcd.clear();
    lcd.print(1, 0, "LED 1 Mati"); 
    lcd.print(1, 1, "LED 2 Menyala"); 
  } else if(StateLED == HIGH && StateLED1 == HIGH){
    lcd.clear();
    lcd.print(1, 0, "LED 1 Menyala"); 
    lcd.print(1, 1, "LED 2 Menyala"); 
  } else if(StateLED == LOW && StateLED1 == LOW){
    lcd.clear();
    lcd.print(1, 0, "LED 1 Mati"); 
    lcd.print(1, 1, "LED 2 Mati"); 
  }
}
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, server, port);
  lcd.clear(); 
  lcd.print(2, 0, "Hello World"); 
  timer.setInterval(1000L, SendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
