int led= 13;                                    
String DataIn;                                   

void setup() {                                      
Serial.begin(9600);                       
pinMode(led, OUTPUT);            
}

void loop() {                                  
  if (Serial.available()) {                   
    DataIn = Serial.readString();       
    Serial.print(DataIn);
  }
 if (DataIn == "on") {            
    digitalWrite(led, HIGH);         
  } if (DataIn == "off") {     
    digitalWrite(led, LOW);        
  }
  delay(100);
  Serial.flush();
}
