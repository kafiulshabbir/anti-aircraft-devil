int motor3=4 ;
int motor4=5 ;

void setup() {

  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop() {
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

}
