#define transistorPin 13


void setup() {
  // put your setup code here, to run once:
    pinMode(transistorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(transistorPin, HIGH);
  delay(5000);
  digitalWrite(transistorPin, LOW);
  delay(5000);
}
