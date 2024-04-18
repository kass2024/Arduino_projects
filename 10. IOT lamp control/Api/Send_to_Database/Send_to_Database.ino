#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <ESP8266HTTPClient.h>
#include <Servo.h>

WiFiClient wifiClient;

unsigned long prevTime1 = millis();
unsigned long prevTime2 = millis();
unsigned long prevTime3 = millis();


const char* ssid = "Methode2";
const char* password = "123456789@";
int lamp =5;
int pump =4;

void setup() {

  Serial.begin(115200); // Starts the serial communication
  pinMode(lamp, OUTPUT);
  pinMode(pump, OUTPUT);


  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

}

void loop() {
  unsigned long currentTime = millis();

   if(currentTime - prevTime3 > 1000){
  
      HTTPClient http;
      

  
        String serverPath = "http://iot.kass.co.rw/api.php";
  
        // Your Domain name with URL path or IP address with path
        //http.begin( serverPath.c_str());
        http.begin(wifiClient, serverPath.c_str());
  
        // Send HTTP GET request
        int httpResponseCode = http.GET();
        delay(1000);
  
        if (httpResponseCode > 0) {
          //Serial.print("HTTP Response code: ");
          //Serial.print(httpResponseCode);
          String payload = http.getString();
          int Value = payload.toInt();
          Serial.println(Value);
          //Serial.println(payload);
          if(Value == 1){
           digitalWrite(lamp, LOW);
           Serial.println("LED ON");
          }
         if(Value == 2){
           digitalWrite(lamp, HIGH);
           Serial.println("LED OFF");
          }
           if(Value == 3){
           digitalWrite(pump, LOW);
           Serial.println("LED OFF");
          }
           if(Value == 4){
           digitalWrite(pump, HIGH);
           Serial.println("LED OFF");
          }
            }
        else{
          Serial.println("Not Activate all");
          }
         http.end();
  
      prevTime3 = currentTime;
   }
  // Clears the trigPin

delay(1000);
}
