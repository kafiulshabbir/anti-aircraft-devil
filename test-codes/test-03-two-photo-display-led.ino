int photores_yellow = A0;
int photores_green = A1;
int led_out_green = 3;
int led_out_yellow = 2;


void setup()
{
  pinMode(photores_yellow, INPUT);
  pinMode(photores_green, INPUT);
  Serial.begin(9600);
  pinMode(led_out_green,OUTPUT);
  pinMode(led_out_yellow,OUTPUT);
}

void loop()
{
  int photoval_read_yellow = analogRead(photores_yellow);
  int photoval_read_green = analogRead(photores_green);
 
  Serial.println(photoval_read_yellow);
 // delay(5);
  Serial.println(photoval_read_green);
  //delay(5);
  Serial.println("--------------------------------------\n\n");
  
  if(photoval_read_yellow < photoval_read_green){
    digitalWrite(led_out_green,HIGH);
    digitalWrite(led_out_yellow,LOW);
  }
  else{
    digitalWrite(led_out_green,LOW);
    digitalWrite(led_out_yellow,HIGH);
  }
  delay(500);
}
