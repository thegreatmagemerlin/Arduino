const int motorLeft = 9;
const int motorRight = 10;
const int dirLeft1 = 7;
const int dirRight1 = 8;
const int dirLeft2 = 3;
const int dirRight2 = 4;

const turnTime=0;

void turn_left();
void turn_right();

///////////////////////////////////////////////////////

void setup() {
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
  pinMode(dirLeft1, OUTPUT);
  pinMode(dirRight1, OUTPUT);
  pinMode(dirLeft2, OUTPUT);
  pinMode(dirRight2, OUTPUT);
  digitalWrite(dirLeft1, 0);
  digitalWrite(dirLeft2, 1);
  digitalWrite(dirRight1, 0);
  digitalWrite(dirRight2, 1);
}

void loop() {

    turn_left();
    delay(5000);
    turn_right();

}

///////////////////////////////////////////////////////

void turn_left(int t){
  analogWrite(motorLeft, 255);
  digitalWrite(dirLeft1, 1);
  digitalWrite(dirLeft2, 0);
  analogWrite(motorRight,255);
  digitalWrite(dirRight1, 0);
  digitalWrite(dirRight2, 1);
  delay(t);
  digitalWrite(dirLeft1, 0);
  digitalWrite(dirLeft2, 1);
  digitalWrite(dirRight1, 0);
  digitalWrite(dirRight2, 1);
 }
 
void turn_right(int t){
  analogWrite(motorLeft, 255);
  digitalWrite(dirLeft1, 0);
  digitalWrite(dirLeft2, 1);
  analogWrite(motorRight,255);
  digitalWrite(dirRight1, 1);
  digitalWrite(dirRight2, 0);
  delay(t)
  digitalWrite(dirLeft1, 0);
  digitalWrite(dirLeft2, 1);
  digitalWrite(dirRight1, 0);
  digitalWrite(dirRight2, 1);
 }  