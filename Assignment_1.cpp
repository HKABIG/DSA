#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <ESP8266WiFi.h>

String apiKey = "G8AFY9MGP02DG2EJ";
const char *ssid =  "Pratham";   
const char *pass =  "pratham2002";
const char *server = "api.thingspeak.com";

int sensor_pin =D7;
const int SW420_PIN = D1;   // Define digital input pin for SW420 sensor
int vibration =10;
DHT dht(D4, DHT11);
const int FLOAT_SENSOR_PIN = D3;



int buzzer = D0;
int smokeA0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 300;

WiFiClient client;

//unsigned long myChannelNumber = 2104408; //Your Channel Number (Without Brackets)
//const char * myWriteAPIKey = "REBL81PJ40V3CJD6"; //Your Write API Key


void setup() {

  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


   
  pinMode(SW420_PIN, INPUT);
  dht.begin();
  pinMode(sensor_pin, INPUT);
  pinMode(FLOAT_SENSOR_PIN, OUTPUT);

 pinMode(buzzer, OUTPUT);
 pinMode(smokeA0, INPUT);
 Serial.begin(9600);
}

void loop() {

vibration = digitalRead(SW420_PIN);
 if (vibration == HIGH){
  Serial.println("Vibration detected!");
   digitalWrite(buzzer,HIGH);
   tone(buzzer, 1000, 200);

 }

float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

else{
  // Print humidity and temperature to serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  }


 int analogSensor = analogRead(smokeA0);

 Serial.print("Pin A0: ");
 Serial.println(analogSensor);
 // Checks if it has reached the threshold value
 if (analogSensor > sensorThres)
 {
   digitalWrite(buzzer,HIGH);
   tone(buzzer, 1000, 200);
 }
 else
 {
   noTone(buzzer);
 }

  if (digitalRead(FLOAT_SENSOR_PIN )){
    Serial.println("Manhole water level is maintained.");

  }
  else{
      Serial.println("Manhole water level crossed threshold level");
       digitalWrite(buzzer,HIGH);
       tone(buzzer, 1000);
  }




  if (client.connect(server, 80))
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(temperature);
    postStr += "&field2=";
    postStr += String(humidity);
    postStr += "\r\n\r\n";
    postStr += "&field3=";
    postStr += String(analogSensor);
    postStr += "\r\n\r\n";


    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

  }

    client.stop();


 delay(3000);
}