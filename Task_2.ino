/*
  PIR-Based Motion Detection
  Arduino UNO: PIR OUT -> D2; LED -> D13
  Use a 220-ohm series resistor with an external LED.
*/
const int PIR_PIN = 2;
const int LED_PIN = 13;
int previousMotionState = LOW;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR Motion Detection System Started");
  Serial.println("Allow the sensor to stabilize after power-up.");
}

void loop() {
  int motionState = digitalRead(PIR_PIN);

  if (motionState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    if (previousMotionState == LOW) {
      Serial.println("Motion detected! LED ON");
    }
  } else {
    digitalWrite(LED_PIN, LOW);
    if (previousMotionState == HIGH) {
      Serial.println("No motion detected. LED OFF");
    }
  }

  previousMotionState = motionState;
  delay(100);
}