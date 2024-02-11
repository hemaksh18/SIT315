const byte LED_PIN = 13;
const byte METER_PIN = A4;
double timerFrequency = 2.0; // initialising freaquency 

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(METER_PIN, INPUT);  
  Serial.begin(9600);
  startTimer(timerFrequency);
}

void loop()
{ 
  // analog value of the potntiometer stored 
  int potential = analogRead(METER_PIN);
  // mapping the freaquency using analog value 
  timerFrequency = map(potential, 0, 1023, 0.5, 10);
  startTimer(timerFrequency);// function called with frequency passed as parameter 
  
}

void startTimer(double timerFrequency)// initialises the timer with related frequency rate 
{
  noInterrupts();
  TCCR1A = 0; // timer set to 0 to prevent interruption
  TCCR1B = 0;
  TCNT1 = 0; 
  
  // Calculate the value to compare with timer counter and give the frequency
  unsigned long potential = (F_CPU / (2 * 1024 * timerFrequency)) - 1;
  
  // if the potential value matches with the timer counter value of register, interrupt is generated 
  OCR1A = potential;
  
  //  set the prescaler to 1024
  TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
  
  // once potential value reaches OCR1IA it generates interrupt  
  TIMSK1 |= (1 << OCIE1A);
  
  interrupts();
}

ISR(TIMER1_COMPA_vect){
   digitalWrite(LED_PIN, digitalRead(LED_PIN) ^ 1); // interrupt that is triggering the LED
}
