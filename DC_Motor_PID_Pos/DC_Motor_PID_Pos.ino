//Pololu DC motor with encoder position control with PID controller
//Mechatronics 530.421 Lab5
//Courtsey: MIT OCW 2.017 Lab4 "Motor Control"

void setup() {
  Serial.begin(9600);
  float Kp = 0.0; //proportional control parameter
  float Ki = 0.0; //integral control parameter
  float Kd = 0.0; //differential control parameter
  int setPoint = 0; //set point (value which you want to control)

  pinMode (ClockPin, INPUT);
  pinMode (UpDownPin, INPUT);

  //encoder pin on interrupt 0 (pin 2)
  attachInterrupt(0, doEncoder, CHANGE);
  int time_1 = millis(); //read initial time stamp, in milliseconds.
}

void loop() {
  //Serial.println("Motor Control");
  int time_2 = millis(); //read the current time stamp
  int dt = time_2 - time_1; //compute detla time
  time_1 = time_2; //reassign new time_1

  //update state variables for use in PID controller
  float vel = (encoder0Pos - oldPos) / dt; // velocity estimate in milliseconds
  int error = setPoint - encoder0Pos; // position error in counts

  //reassign state variables
  int oldPos = encoder0Pos;

  //########FILL IN CONTROLLER############
  // command = ????
  // remember command should be an integer
  //########END OF YOUR CODE##############

}
