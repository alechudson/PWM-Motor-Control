// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3; 
int in3 = 5;
int in4 = 4;

// Potentiometer to PWM
int knob = A0; // The pin reading signal from 10K pot.
int knobIn = 0; // variable to store the raw value of the pot.
int knobValue = 0; // variable to store the PWM value of the pot.

//NOTE: **When adjusting the speed it will only change after the loop is complete.**
int motorTime = 10000; // How long the motor will spin in millis.
int pauseTime = 2000; // How long to pause at the end of each run.

void setup() {
  Serial.begin(115200);

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  knobIn = analogRead(knob);
  knobValue = map(knobIn, 0, 1023, 0, 255); //Mapping the values from the pot to PWM.
  motorControl();
  Serial.println(knobValue);
}

void motorControl() {
    // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Set speed, range 0~255
  analogWrite(enA, knobValue);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Set speed, range 0~255
  analogWrite(enB, knobValue);
  delay(motorTime);


  //Pause the motor for "pauseTime".
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(pauseTime);


  // Change motor directions


  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Set speed, range 0~255
  analogWrite(enA, knobValue);

  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // Set speed, range 0~255
  analogWrite(enB, knobValue);
  delay(motorTime);


  //Pause the motor for "pauseTime".
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(pauseTime);
}
