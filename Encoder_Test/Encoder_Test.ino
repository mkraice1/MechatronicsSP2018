//Quadrature Encoder
//Connect Encoder to Pins encoder0PinA, encoder0PinB, and +5V.
//Mechatronics 530.421 Lab 2

int encoder0PinA = 9;
int encoder0PinB = 10;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int encoder0PinBLast = LOW;
int n1 = LOW;
int n2 = LOW;

void setup() {
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  Serial.begin (9600);
}

//Increase or decrease pos depends on user's definition of positive pos.
void loop() {
  n1 = digitalRead(encoder0PinA);
  n2 = digitalRead(encoder0PinB);
//Using rising edge of the channel A
  if ((encoder0PinALast == LOW) && (n1 == HIGH)) {
    if (n2 == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  }
//Using falling edge of the channel A
  else if ((encoder0PinALast == HIGH) && (n1 == LOW)) {
    if (n2 == HIGH) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  }
//Using rising edge of the channel B
  else if ((encoder0PinBLast == LOW) && (n2 == HIGH)) {
    if (n1 == HIGH) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  } 
//Using falling edge of the channel B
  else if ((encoder0PinBLast == HIGH) && (n2 == LOW)) {
    if (n1 == LOW) {
      encoder0Pos--;
    } else {
      encoder0Pos++;
    }
  } 
  encoder0PinALast = n1;
  encoder0PinBLast = n2;
  Serial.print ("encoder");Serial.println (encoder0Pos);Serial.println ("");
}
