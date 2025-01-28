
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <HCSR04.h>
  
#define BLYNK_AUTH_TOKEN "x7hpsy2d3p_ZywWpXFY3KcZrSDWsXNBU" 
#define MoistureData1 D1
#define MoistureData2 D2
#define DHTPIN D3
#define relay2 D5
#define relay3 D6
#define relay4 D7
#define echoPin D0
#define trigPin D8
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int RainsensorData,Moisturesensor1,Moisturesensor2;
long duration;
int distance;
float Temp,Humidity;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone";
char pass[] = "qwertyuiop";
WidgetLCD lcd(V8);

void setup() {
 
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  Serial.begin(9600);
  dht.begin();
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  lcd.clear(); 

}

void loop() {

 RainsensorData = analogRead(A0); 
 Blynk.virtualWrite(A0, RainsensorData);

 Moisturesensor1 = digitalRead(MoistureData1); 
 Blynk.virtualWrite(V1, Moisturesensor1);

 Moisturesensor2 = digitalRead(MoistureData2); 
 Blynk.virtualWrite(V2, Moisturesensor2);

  if(Moisturesensor1== HIGH && Moisturesensor2== HIGH)
      {
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, LOW);
      }
      else if(Moisturesensor1== HIGH && Moisturesensor2== LOW)
      {
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, HIGH);
      }
      else if(Moisturesensor1== LOW && Moisturesensor2== HIGH)
      {
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, LOW);
      }
      else
      {
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
      }

   
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  Blynk.virtualWrite(V8,distance);


  Temp = dht.readTemperature();
  Blynk.virtualWrite(V6,Temp);

  Humidity = dht.readHumidity();
  Blynk.virtualWrite(V7,Humidity);
 
  Blynk.run();
}
