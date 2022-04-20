void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int myValue = random(100);
  Serial.print("The Value is: ");
  Serial.println(myValue);
  delay(1000);
}
