//I said void Rotate(int direction): if direction = {-1, some direction; 0, no rotation - motor off; +1 rotate other way. void Rotate() will use other functions, make them as you like and {add, commit, push} 
int motor3=4 ;
int motor4=5 ;

// USE BETTER NAMES FOR THE 4 PINS WE NEED TO USE
const int di_a=-1;
const int di_b=0;
const int di_c=1;

void setup() {

	//aDD A CIRCUIT DRAGRAM - I THINK WE NEED 4 PINS
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}


// YOU NEED TO MAKE A FUNCTION BEFORE LOOP - LOOP SHOULD BE EMPTY


void Rotate(int direction)
{
	if direction = -1
		negative direction;
		
	if diretion = 0
		no rotation - motor off;
	if direction = +1	
		rotate positive direction
		
}


void loop() {

digitalWrite(motor3,HIGH);
digitalWrite(motor4,LOW);

  if ("..."=dia_a) 
   {
   // we are going to turn on both wheels!!
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);

   }

  if ("..."=dia_b) 
  {
     digitalWrite(motor3,LOW);
     digitalWrite(motor4,LOW);
  }

  if ("..."=dia_c)
  {
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
  }

 
