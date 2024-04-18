char Incoming_value = 0;
                
void setup() 
{
  Serial.begin(9600);         
  pinMode(13, OUTPUT);       
}

void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      
    Serial.println(Incoming_value);               
    if(Incoming_value == '1')
    {             
      digitalWrite(13, HIGH);
      Serial.println("lED IS ON");  
    } 
    if(Incoming_value == '0') 
    {      
      digitalWrite(13, LOW);
      Serial.println("lED IS OFF"); 
    }   
  }
  delay(100);
  Serial.flush();                            
} 
