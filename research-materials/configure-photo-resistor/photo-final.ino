int photores =A0;
int photoval;
int red=9;
int green=8;


void setup()
{
  pinMode(photores, INPUT);
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop()
{
 photoval = analogRead(photores);
  Serial.println(photoval);
  delay(500);
  if(photoval>350){
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }// i have used 350 as a example value for the analog value we recieve frome the photoresistor the actually value should be experimentally found 
  if(photoval<350){
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
  }
}
