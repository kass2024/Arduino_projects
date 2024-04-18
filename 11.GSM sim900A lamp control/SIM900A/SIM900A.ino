#include <SoftwareSerial.h> 
SoftwareSerial SIM900(9, 10); // TXpin=9 RXpin=10
int relay1=4;
int relay2=5;
int relay3=6;
int relay4=7;
String passcode="abc123"; 
String incoming = "";

void setup() {

   Serial.begin(9600);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay4,OUTPUT);

  SIM900.begin(9600); // original 19200
randomSeed(analogRead(0));

  SIM900.print("AT+CMGF=1\r");  // set SMS mode to text
  delay(1000);
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
  delay(1000);
     SIM900.println("AT+CMGD=1,4"); // delete all SMS
   delay(5000);
  Serial.println("Ready...");
  
}


void loop() {


  if(SIM900.available() >0)
  {

  incoming=SIM900.readString(); 
  Serial.println(incoming);
     String fulldata = getValue(incoming, '%', 0); 
String password = getValue(incoming, '%', 1); //contains password
String  load= getValue(incoming, '%', 2); //contains load number 
String  loadstatus= getValue(incoming, '%', 3);// contains on and off state

Serial.print("value 1: ");
Serial.println(password);
Serial.print("value 2: ");
Serial.println(load);
Serial.print("value 3: ");
Serial.println(loadstatus);

int loadvalue = loadstatus.toInt();

if((password==passcode)&&(load=="load1")&&(loadvalue==1))
{
  digitalWrite(relay1,HIGH);
  }
else if((password==passcode)&&(load=="load1")&&(loadvalue==0))
{
  digitalWrite(relay1,LOW);
  }

 else if((password==passcode)&&(load=="load2")&&(loadvalue==1))
{
  digitalWrite(relay2,HIGH);
  }
else if((password==passcode)&&(load=="load2")&&(loadvalue==0))
{
  digitalWrite(relay2,LOW);
  }
  else if((password==passcode)&&(load=="load3")&&(loadvalue==1))
{
  digitalWrite(relay3,HIGH);
  }
else if((password==passcode)&&(load=="load3")&&(loadvalue==0))
{
  digitalWrite(relay3,LOW);
  }
  else if((password==passcode)&&(load=="lock")&&(loadvalue==1))
{
  digitalWrite(relay4,HIGH);
  }
else if((password==passcode)&&(load=="lock")&&(loadvalue==0))
{
  digitalWrite(relay4,LOW);
  }
    delay(20);
}
}
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
