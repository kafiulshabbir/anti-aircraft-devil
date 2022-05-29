const int PHOTORES1 = A10;//left
const int PHOTORES2 = A9;//right
const int SPEEDMOTOR1 = 2;// motor one has the purple wire
const int SPEEDMOTOR2 = 7;
const int MOTOR2_DIREC_FIRST = 5;
const int MOTOR2_DIREC_SECOND = 6 ;
const int MOTOR1_DIREC_FIRST = 3;//we need to calibrate left and right
const int MOTOR1_DIREC_SECOND = 4;

const int MOTOR_NUMBER_RIGHT=2;
const int MOTOR_NUMBER_LEFT=1;
const int FORWARD = 1;
const int BACKWARD = -1;
const int STAYWARD = 0;
const int LEFT_TURN = 1;
const int RIGHT_TURN = -1;
const int NO_TURN =0;
const int POTENT_PIN =A8;

struct motorprop
{
  int speed_pin;
  int direc_first_pin;
  int direc_second_pin;
  
};

motorprop which_motor(int motor_n)
{
  motorprop motor;
  if(motor_n ==MOTOR_NUMBER_LEFT)
  {
    motor.speed_pin=SPEEDMOTOR1;
    motor.direc_first_pin=MOTOR1_DIREC_FIRST;
    motor.direc_second_pin=MOTOR1_DIREC_SECOND;
    
  }
  else if (motor_n==MOTOR_NUMBER_RIGHT)
  {
    motor.speed_pin=SPEEDMOTOR2;
    motor.direc_first_pin=MOTOR2_DIREC_FIRST;
    motor.direc_second_pin=MOTOR2_DIREC_SECOND;
  }
  return motor;
}

void motor_rotate(int motor_n,int direc,int speed)
{
  motorprop motor=which_motor(motor_n);
  if(direc==FORWARD)
  {
    digitalWrite(motor.direc_first_pin,HIGH);
    digitalWrite(motor.direc_second_pin,LOW);
    analogWrite(motor.speed_pin,speed);
  }
  else if(direc==STAYWARD)
  {
    digitalWrite(motor.direc_first_pin,LOW);
    digitalWrite(motor.direc_second_pin,LOW);
    analogWrite(motor.speed_pin,0);
  }
  else if(direc==BACKWARD)
  {
    digitalWrite(motor.direc_first_pin,LOW);
    digitalWrite(motor.direc_second_pin,HIGH);
    analogWrite(motor.speed_pin,speed);
  }
}

int photocalib(int left,int right, int tolerance)
{
  if(left-right > tolerance )
  {
    return RIGHT_TURN;
  }
  if(right-left> tolerance)
   {
    return LEFT_TURN;
   }
   return NO_TURN;
}
  
 
void setup()
{
  pinMode(PHOTORES1, INPUT);
  pinMode(PHOTORES2, INPUT);
  pinMode(SPEEDMOTOR1 , OUTPUT);
  pinMode(SPEEDMOTOR2 , OUTPUT);
  pinMode(MOTOR1_DIREC_FIRST , OUTPUT); 
  pinMode(MOTOR1_DIREC_SECOND , OUTPUT);
  pinMode(MOTOR2_DIREC_FIRST , OUTPUT); 
  pinMode(MOTOR2_DIREC_SECOND , OUTPUT);
  pinMode(POTENT_PIN,INPUT);
  
  Serial.begin(9600);
 
}

void loop()
{
  
 /* digitalWrite(MOTOR1_DIREC_FIRST,HIGH);
  digitalWrite(MOTOR1_DIREC_SECOND,LOW);


  delay(3000);

  digitalWrite(MOTOR1_DIREC_FIRST,LOW);
  digitalWrite(MOTOR1_DIREC_SECOND,HIGH);

  delay(3000);
  
 digitalWrite(MOTOR1_DIREC_FIRST,LOW);
  digitalWrite(MOTOR1_DIREC_SECOND,LOW);
  delay(3000); 
  */

  
  const int photo_val_left = analogRead(PHOTORES1);
  const int photo_val_right = analogRead(PHOTORES2);
    // 1: turn left/anticlockwise
    // -1:turn right/clockwise
    // 0: no turn/all motors off
   int tolerance = analogRead(POTENT_PIN)/2;
    
   // Serial.println(tolerance);
    int turn_direc=photocalib(photo_val_left,photo_val_right,tolerance);
    
  if(turn_direc == LEFT_TURN)//shadow  on the left in more =>object is on the left => we will turn left 
  {
    //right motor forward and left motor backward 
    motor_rotate(MOTOR_NUMBER_RIGHT,FORWARD, 120);
    motor_rotate(MOTOR_NUMBER_LEFT,BACKWARD,120);
  }
  else if (turn_direc == RIGHT_TURN)
  {
     motor_rotate(MOTOR_NUMBER_RIGHT,BACKWARD,120);
    motor_rotate(MOTOR_NUMBER_LEFT,FORWARD,120);
  }
  else if (turn_direc == NO_TURN)
  {
     motor_rotate(MOTOR_NUMBER_RIGHT,STAYWARD,0);
    motor_rotate(MOTOR_NUMBER_LEFT,STAYWARD,0);
  }
  delay(100);
 /*
  Serial.println(photo_val_left);
  delay(500);
  Serial.println(photo_val_right);
  delay(500);
  Serial.println("--------------------------------------\n\n");
  */
  
  
}
