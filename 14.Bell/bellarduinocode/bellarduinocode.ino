#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid = "Methode2";
const char* password = "123456789@";
const char* apiURL = "/bell/api.php";

const int lampPin = D1; // GPIO5 on ESP8266

void setup() {
    Serial.begin(115200);
    pinMode(lampPin, OUTPUT);
    connectToWiFi();
}

void loop() {
    fetchSchedule();
    delay(10000); // Fetch schedule every 10 seconds, adjust as needed
}

void connectToWiFi() {
    Serial.println();
    Serial.print("Connecting to WiFi");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");
}

void fetchSchedule() {
    WiFiClient client;
    if (!client.connect("192.168.43.87", 80)) {
        Serial.println("Connection failed!");
        return;
    }

    Serial.println("Connected to API");
    client.print(String("GET ") + apiURL + " HTTP/1.1\r\n" +
                 "Host: 192.168.43.87\r\n" +
                 "Connection: close\r\n\r\n");

    delay(500); // Allow some time for the response to arrive

    // Check if data is available to read
    while (client.connected() && !client.available()) {
        delay(10);
    }

    // If no data available or response is not HTTP/1.1 200 OK
    if (!client.available() || client.readStringUntil('\n') != "HTTP/1.1 200 OK") {
    Serial.println("Invalid response from server");
    Serial.println("Response from server:");
    while (client.available()) {
        Serial.write(client.read());
    }
    return;
}


    // Read response data
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, client);

    // Check for parsing errors
    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    // Parse JSON response
    JsonArray schedule = doc.as<JsonArray>();
    Serial.println("Current Time:");
    printCurrentTime(); // Print current time
    Serial.println("Schedules:");
    for (JsonObject scheduleItem : schedule) {
        int hours = scheduleItem["hours"];
        int minutes = scheduleItem["minutes"];
        int seconds = scheduleItem["seconds"];
        
        // Print schedule
        Serial.printf("  %02d:%02d:%02d\n", hours, minutes, seconds);
    }
    Serial.println();
}

void printCurrentTime() {
    struct tm * timeinfo;
    time_t now = time(nullptr);
    timeinfo = localtime(&now);
    int currentHours = timeinfo->tm_hour;
    int currentMinutes = timeinfo->tm_min;
    int currentSeconds = timeinfo->tm_sec;
    
    // Print current time
    Serial.printf("  %02d:%02d:%02d\n", currentHours, currentMinutes, currentSeconds);
}
