const int trigPin = 11;
const int echoPin = 12;
const int motorLeft = 9;
const int motorRight = 10;
const int dirLeft1 = 7;
const int dirRight1 = 8;
const int dirLeft2 = 3;
const int dirRight2 = 4;

const int turnTime=0;
long duration;
int distance;

int get_distance();
int obstickle(int);
void move_turn_left();
void move_turn_right();

///////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
  pinMode(dirLeft1, OUTPUT);
  pinMode(dirRight1, OUTPUT);
  pinMode(dirLeft2, OUTPUT);
  pinMode(dirRight2, OUTPUT);
  digitalWrite(dirLeft1, 0);
  digitalWrite(dirRight1, 0);
  digitalWrite(dirLeft2, 1);
  digitalWrite(dirRight2, 1);
  Serial.begin(9600);
}

void loop() {
  
  distance = get_distance();

  int check = obstickle(distance);
  
  if (check == 1){
    move_turn_left(turnTime);
    delay(turnTime);
  }
  
  Serial.print("Distance: ");  
  Serial.println(distance);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
int get_distance(){
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  duration = pulseIn(echoPin, 1);
  int dist = duration*0.0343/2;
  return dist;
}

int obstickle(int dist){
  if(distance < 4){
    analogWrite(motorLeft, 0);
    analogWrite(motorRight,0);
    return 1;
  } else {
    analogWrite(motorLeft, 255);
    analogWrite(motorRight,255);
    return 0;
  }
  
  }


void move_turn_left(int t){
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
 
void move_turn_right(int t){
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