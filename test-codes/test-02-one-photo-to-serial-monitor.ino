int photores = A0;

void setup()
{
	pinMode(photores, INPUT);
	Serial.begin(9600);
}

void loop()
{
	int photoval = analogRead(photores);
	Serial.println(photoval);
	delay(500);
	return;
}
