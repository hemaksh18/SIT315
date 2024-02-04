
//pins connected to components for recieving input and output
const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

// setting initial state of button and LED 
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;

// setting up pins for recieving input(button press) and generating output(led glow) 
void setup()
{
  //This is used to enable internal pullup command which pulls the pin to ground that was previously connected to 5v
  pinMode(BTN_PIN, INPUT_PULLUP);
  //Once the button is pressed/held the LED glows as output
  pinMode(LED_PIN, OUTPUT);
  //initialising the serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop()
{
  // new variable assigned to check/read the state of button 
  uint8_t buttonState = digitalRead(BTN_PIN);
  
  //prints the previous and new button and led state
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println("");
  
  
  //if the button state is different from previous one then loop is executed
  if(buttonState != buttonPrevState)
  {
    if(buttonState == digitalRead(BTN_PIN)) // corrected code to aviod detecting multiple state changes in one press
    {
      ledState = !ledState;// changes the previous led state to new one
      digitalWrite(LED_PIN, ledState);
    }
  }
  
  buttonPrevState = buttonState; // updates previous button state to current one
    
  //when previous line of code is executed then delay of 500 ms occurs
  delay(500);
}