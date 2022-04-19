int photores =A0;
int photoval;
int red=9;
int green=8;

int motor4=4 ;
int motor5=5 ;
int motor6=6 ;  
int motor7=7 ;

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
  
  if(photoval>350 && photoval=<1000){
    
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    
    digitalWrite(motor4,HIGH);
    digitalWrite(motor5,HIGH);
    digitalWrite(motor6,LOW);
    digitalWrite(motor7,LOW);
    
  }
  // i have used 350 as a example value for the analog value we recieve frome the photoresistor the actually value should be experimentally found 
  
  if(photoval<350) {

    while ( photoval=<1000) {
    
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);

    digitalWrite(motor4,LOW);
    digitalWrite(motor5,LOW);
    digitalWrite(motor6,HIGH);
    digitalWrite(motor7,HIGH);

   }
  
  }
}

else {
  
    digitalWrite(motor4,LOW);
    digitalWrite(motor5,LOW);
    digitalWrite(motor6,LOW);
    digitalWrite(motor7,LOW);
}
