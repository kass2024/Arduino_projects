const int buttonPin = 7;  
const int ledPin = 13;    

int buttonState = 0;
int lastButtonState = 0;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);    
}

void loop() {
  // Read the state of the switch
  buttonState = digitalRead(buttonPin);

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // If the button is pressed, toggle the LED state
    if (buttonState == HIGH) {
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
    delay(50);  
  }

  // Save the current button state for the next iteration
  lastButtonState = buttonState;
}

