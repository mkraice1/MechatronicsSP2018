//DC Motor and Encoder: measure speed
//Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
//Mechatronics 520.340 Lab2
#define encoder0PinA  2
#define encoder0PinB  3
volatile long encoder0Pos=0;
long newposition;
long oldposition = 0;
unsigned long newtime;
unsigned long oldtime = 0;
long vel;
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
newposition = encoder0Pos;
newtime = millis(); //return time in milliseconds since program start running

//implement your method for computing the real time motor velocity, store in variable 'vel'.
//start of your code

//end of your code

Serial.print ("speed = ");
Serial.println (vel);
oldposition = newposition;
oldtime = newtime;
delay(250);
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}
