const int PHOTO_PIN = A0;
const int MOTOR_PIN = 13;

const int LOWER_THRESHOLD = 330;

const int INTERVAL = 200;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);

  while(!Serial);

  Serial.println("LightSensor,Motor,VBat");
   
}



int lightOutput;
int motorPinValue;
int Vbat = 6;
unsigned long time;

void loop() {
  lightOutput = analogRead(A0);
  motorPinValue = (lightOutput > LOWER_THRESHOLD);
  time = millis();

  //Serial.print(time);
  //Serial.print(",");
  Serial.print(lightOutput);
  Serial.print(",");
  Serial.print(motorPinValue);
  Serial.print(",");
  Serial.println(Vbat);

    digitalWrite(MOTOR_PIN, (motorPinValue) ? HIGH : LOW);

  delay(INTERVAL);
}
