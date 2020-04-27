// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B
int enB = 3; 
int in3 = 5;
int in4 = 4;

//PWM input
int pwmIn = 6; // Pin for the PWM signal.
int pwmVal = 0;// Variable to store the read value

//Button for 5s mode
int buttonIn = 2; //Pin that the button is connected to.
int buttonVal = 0; //Variable to store the button value.

//NOTE: **When adjusting the speed it will only change after the loop is complete.**
int motorTime = 10000; // How long the motor will spin in millis.
int motorTime2 = 5000; // How long the motor will spin when button is HIGH
int pauseTime = 1000; // How long to pause at the end of each run.

void setup() {
  Serial.begin(115200);
  
  //Set pin 6 and 2 as inputs for PWM and button.
  pinMode(pwmIn, INPUT);
  pinMode(buttonIn, INPUT);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {

  pwmVal = digitalRead(pwmIn); // read the input pin
  buttonVal = digitalRead(buttonIn); // read the button to see if its high or low
  
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Set speed, range 0~255
  analogWrite(enA, pwmVal);

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // Set speed, range 0~255
  analogWrite(enB, pwmVal);
  
  //Run the motor depending on button value
  if (buttonVal = LOW){
    delay(motorTime);
  }
  else if (buttonVal = HIGH){
    delay(motorTime2);
  }

  //Pause the motor for "pauseTime".
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(pauseTime);


  //// Change motor directions


  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Set speed, range 0~255
  analogWrite(enA, pwmVal);

  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // Set speed, range 0~255
  analogWrite(enB, pwmVal);
  
  //Run the motor depending on button value
  if (buttonVal = LOW){
    delay(motorTime);
  }
  else if (buttonVal = HIGH){
    delay(motorTime2);
  }


  //Pause the motor for "pauseTime".
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(pauseTime);

  Serial.println(pwmVal);
}
