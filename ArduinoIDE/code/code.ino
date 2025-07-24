#include <WiFi.h>  
#include <WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"
#define DHTPIN  26   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11
#define MOISTURE_PIN 34
#define GAS_PIN 35

DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "YOUR SSID";   // your network SSID (name) 
const char* password = "PASSWORD";   // your network password
WiFiClient  client;

unsigned long myChannelNumber = XXXXXXX;  //your Thingspeak ChannelNumber
const char * myWriteAPIKey = "Z36QIP4REJXXXXXX";  //your WriteAPIKey

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;  //30 Seconds delay



void setup() {
  Serial.begin(115200);  //Initialize serial
  //initBME();
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
  dht.begin();

}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }


      delay(2000);
    
      // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      float h = dht.readHumidity();
      // Read temperature as Celsius (the default)
      float t = dht.readTemperature();
      int moistureRaw = analogRead(MOISTURE_PIN);
      int gasRaw = analogRead(GAS_PIN);

      int moisturePercentage = 100 - ((moistureRaw * 100.0) / 4095.0);
      int gasPercentage = (gasRaw * 100.0) / 4095.0;
     
    
      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t))   //used only for float values 
      {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
      }
      else
      {

        ThingSpeak.setField(1, h);
        ThingSpeak.setField(2, t);
        ThingSpeak.setField(3, moisturePercentage);
        ThingSpeak.setField(4, gasPercentage);

        int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
        if(x == 200){
          Serial.println("Channel update successful.");
        }
        else{
          Serial.println("Problem updating channel. HTTP error code " + String(x));
        }
        lastTime = millis();
      }
       Serial.print("Humidity: ");   //to print values in serial moniter
       Serial.print(h); 
       Serial.print(" %\t");
       Serial.print("Temp: "); 
       Serial.print(t); 
       Serial.print(" °C\t");
       Serial.print("Moisture: "); 
       Serial.print(moisturePercentage); 
       Serial.print(" %\t");
       Serial.print("Gas: "); 
       Serial.print(gasPercentage); 
       Serial.println(" %");

    
     
    
    
  }
}
