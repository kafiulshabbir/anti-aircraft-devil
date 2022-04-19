int photores =A0;
int photoval;



void setup()
{
  pinMode(photores, INPUT);
  Serial.begin(9600);
 
}

void loop()
{
 photoval = analogRead(photores);
  Serial.println(photoval);
  delay(500);
  
}
