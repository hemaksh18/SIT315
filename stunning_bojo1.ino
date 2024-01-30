// C++ code
//
int LED = 13;
int pir = 2;

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int detect = digitalRead(pir);
  
  if(detect == HIGH)
  {
    digitalWrite(LED,HIGH);
    Serial.println("DETECTED");
    delay(2000);
  } 
  else 
  {
    digitalWrite(LED, LOW); 
    Serial.println("NOT DETETCTED");
    delay(2000);
  }
}