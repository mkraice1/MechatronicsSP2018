//DC Motor and Encoder
//Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
//Mechatronics 530.421 Lab2
#define encoder0PinA  2
#define encoder0PinB  3
volatile long encoder0Pos=0;
void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);
  attachInterrupt(0, doEncoder, RISING);  // PIN 2 generates the interrupt
  Serial.begin (9600);
}
void loop()
{
  RotateCW();
  delay(3000);
  RotateCCW();
  delay(3000);
  Stop();
  delay(3000);
}

void RotateCW()
{
  //fill in with your codes
}
void RotateCCW()
{
  //fill in will your codes
}
void Stop()
{
  //fill in will your codes
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}

