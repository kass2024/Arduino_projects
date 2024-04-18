int button = 2;  
int counter = 0; 
int buttonState;  
int led =10;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);

  if (buttonState == HIGH) {
    counter++;
    digitalWrite(led,HIGH);
    if (counter >15) {
      counter = 0;
      digitalWrite(led,LOW);  
    }
    Serial.println(counter);
  }
delay(250);
}
