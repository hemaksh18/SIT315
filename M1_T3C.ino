// C++ code
//
int LED = 13;
int pir = 2;
int pirSec = 7;

volatile bool detect = false; // checking if motion is detected or not
volatile bool detectSec = false; // checking if motion is detected or not

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(pir,INPUT);
  pinMode(pirSec,INPUT);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pir), ISRmotion, CHANGE);// adds interrupt to pir pin
  attachInterrupt(digitalPinToInterrupt(pirSec), ISRmotionSec, CHANGE); // adds interrupt to pirSec pin

}

void loop()
{
   
  
  if(detect == HIGH || detectSec == HIGH)
  {
    digitalWrite(LED,HIGH);
    Serial.println("DETECTED");
    delay(2000);
    detect = false;
    detectSec = false;
  } 
  
    
  else 
  {
    digitalWrite(LED, LOW); 
    Serial.println("NOT DETECTED");
    delay(2000);
  }
  
}
 void ISRmotion()// function that targets the pin 2
  {
    detect = digitalRead(pir);
   
  }

void ISRmotionSec()// function that targets the pin 7 
  {
   	detectSec = digitalRead(pirSec);
  }


