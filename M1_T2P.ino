// C++ code
//
int LED = 13;
int pir = 2;

volatile bool detect = false; // checking if motion is detected or not

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pir), ISRmotion, CHANGE);// adds interrupt to pir pin
}

void loop()
{
  
  if(detect == HIGH)
  {
    digitalWrite(LED,HIGH);
    Serial.println("DETECTED");
    delay(2000);
    detect = false;
  } 
  else 
  {
    digitalWrite(LED, LOW); 
    Serial.println("NOT DETETCTED");
    delay(2000);
  }
  
}
 void ISRmotion()// function that targets the pin
  {
    detect = digitalRead(pir);
  }
