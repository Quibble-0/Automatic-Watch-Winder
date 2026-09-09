long duration;
int distance;

// sensor variables
int trig = 6;
int echo = 7;

// stepper motor variables
int fullRotation = 200;
int status = 0;
int dirPin = 12;
int stepPin = 13;

void setup() {

  // configure motor and sensor
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  delay(2000);

  digitalWrite(dirPin, HIGH);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);


}

void loop() {

  //trigger sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // get time
  duration = pulseIn(echo, HIGH);

  // convert time to distance
  distance = duration * 0.034 / 2;

  // trigger motor to spin if nothing is near sensor
  if (distance > 5) {
    
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(5000);
  }


}

