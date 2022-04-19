int photores =A0;
int photoval;
int red=9;
int green=8;

int motor_first_pos=4 ;
int motor_first_neg=5 ;
int motor_second_pos=6 ;  
int motor_second_neg=7 ;

void setup()

{
  pinMode(photores, INPUT);
  
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);

  
  pinMode(motor_first_pos, OUTPUT);
  pinMode(motor_first_neg, OUTPUT);
  pinMode(motor_second_pos, OUTPUT);
  pinMode(motor_second_neg, OUTPUT);
}



 void Rotate(int direction)
 
 {
  
   if (direction = -1) 
   {
   
    digitalWrite(motor_first_pos,LOW);
    digitalWrite(motor_first_neg,HIGH);
    digitalWrite(motor_second_pos=6,LOW);
    digitalWrite(motor_second_neg=7,HIGH);
   }
   
  if (direction = 0)
  {
    digitalWrite(motor_first_pos,LOW);
    digitalWrite(motor_first_neg,LOW);
    digitalWrite(motor_second_pos=6,LOW);
    digitalWrite(motor_second_neg=7,LOW);

  }
  
  if (direction = +1) 
  {
    digitalWrite(motor_first_pos,HIGH);
    digitalWrite(motor_first_neg,LOW);
    digitalWrite(motor_second_pos=6,HIGH);
    digitalWrite(motor_second_neg=7,LOW);

  }

 
void loop()
{
  
 photoval = analogRead(photores);
  Serial.println(photoval);
  delay(500);
  
  if(photoval>350 && photoval=<1000)
  {
  
    Rotate(+1);
   
      
  }
  
  
  if(photoval<350) {

  
    
 
      Rotate (-1)
    
    }
  
  }


else {
  
    Rotate(0);
}
