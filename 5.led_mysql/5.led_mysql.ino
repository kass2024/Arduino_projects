#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <ESP8266WiFi.h>

char ssid[] = "your_wifi_ssid";
char pass[] = "your_wifi_password";
char user[] = "your_mysql_username";
char password[] = "your_mysql_password";
IPAddress server_addr(192, 168, 43, 58); // MySQL server IP
int ledPin = D2;      // Assuming the LED is connected to digital pin D2

WiFiClient client;
MySQL_Connection conn((Client *)&client);

char SELECT_SQL[] = "SELECT status FROM iot.button WHERE id=1";
char query[128];

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  Serial.print("Assigned IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("");

  Serial.println("Connecting to database");

  while (conn.connect(server_addr, 3306, user, password, "iot") != true) {
    delay(200);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connected to SQL Server!");
}

void loop() {
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  cur_mem->execute(SELECT_SQL);
  row_values *row = NULL;

  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      int status = atoi(row->values[0]);

      // Control the LED based on the "status" value
      digitalWrite(ledPin, (status == 1) ? HIGH : LOW);

      Serial.print("LED status: ");
      Serial.println(status);
    }
  } while (row != NULL);

  delete cur_mem;

  delay(10000); // 10 seconds delay
}
