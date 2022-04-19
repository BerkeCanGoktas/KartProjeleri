#define ledPin 13
#define sensorPin D5
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}
void loop()
{
  int sensorDeger = digitalRead(sensorPin);
  Serial.println(sensorDeger);
  delay(1000);
//  int sensorDeger = digitalRead(sensorPin);
//  if (sensorDeger < 500)
//  {
//    digitalWrite(ledPin,HIGH);
//    Serial.print(sensorDeger);
//    Serial.println("Led yakıldı");
//    
//    delay(1000);
//  }
//  else 
//  {
//    
//    digitalWrite(ledPin,LOW);
//    Serial.print(sensorDeger);
//    Serial.println("Led söndürüldü");
//    delay(1000);
//    
//  }
  
}
