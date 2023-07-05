#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "Yasodha";
const char* password = "yasodha56";

// Replace with your XAMPP server's IP address or domain name
const char* serverURL = "http:// ip address/door.php;

#define RXp2 16
#define TXp2 17

void setup() {
Serial.begin(115200);
Serial2.begin(9600, SERIAL_8N1, RXp2 , TXp2);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Send data to the XAMPP server
  sendSensorData("2023-07-03 12:34:56", "open door","100");
}

void loop() {
  // Your code
}

void sendSensorData(String timestamp, String door_status,String persons_detected) {
  HTTPClient http;

  // Build the request URL with the timestamp and status as query parameters
  String URL =  "timestamp=" + timestamp + "&door_status=" + door_status + "&persons_detected=" + persons_detected;


  // Send the HTTP GET request
  http.begin(URL);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    Serial.print("Data sent. HTTP response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error sending data. HTTP response code: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}

