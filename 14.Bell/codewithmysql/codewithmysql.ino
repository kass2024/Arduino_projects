#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
const char* ssid = "Methode2";
const char* password = "123456789@";
const IPAddress host(192, 168, 43, 87); // MySQL server IP address
const int port = 3306;
const char* user = "root";
const char* db_password = "";
const char* database = "bell"; // Your database name

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
    MySQL_Connection conn((Client *)&client);

    Serial.print("Connecting to MySQL server: ");
    if (conn.connect(host, port, const_cast<char*>(user), const_cast<char*>(db_password), const_cast<char*>(database))) {
        Serial.println("Connected");

        // Create a MySQL_Cursor instance to execute queries
        MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

        // Execute the query
        char query[128];
        sprintf(query, "SELECT * FROM bell_schedule");
        cur_mem->execute(query);

        // Fetch the rows and control the lamp
        MySQL_Row row;
        do {
            cur_mem->get_next_row();
            row = cur_mem->get_next_row();
            if (row != NULL) {
                int num_fields = row.field_count();
                for (int i = 0; i < num_fields; i++) {
                    MySQL_Field *field = row.get_field(i);
                    if (field != NULL) {
                        int hours = atoi(field->getString(1));
                        int minutes = atoi(field->getString(2));
                        int seconds = atoi(field->getString(3));
                        // Get current time
                        struct tm * timeinfo;
                        time_t now = time(nullptr);
                        timeinfo = localtime(&now);
                        int currentHours = timeinfo->tm_hour;
                        int currentMinutes = timeinfo->tm_min;
                        int currentSeconds = timeinfo->tm_sec;
                        // Compare with current time and control the lamp
                        if (currentHours == hours && currentMinutes == minutes && currentSeconds == seconds) {
                            digitalWrite(lampPin, HIGH); // Turn on lamp
                            delay(5000); // Keep lamp on for 5 seconds
                            digitalWrite(lampPin, LOW); // Turn off lamp
                        }
                    }
                }
            }
        } while (row != NULL);

        // Delete the cursor instance
        delete cur_mem;
    } else {
        Serial.println("Connection failed");
    }
}
