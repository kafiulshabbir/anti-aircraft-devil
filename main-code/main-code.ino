const double percent = 10;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(f(1,2));
  delay(1000);
}
