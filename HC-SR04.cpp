const int trigPin = 11;
const int echoPin = 12;


long duration;
int distance;


int get_distance();

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  distance = get_distance();
  Serial.print("Distance: ");  
  Serial.println(distance);


}


int get_distance(){
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  duration = pulseIn(echoPin, 1);
  int dist = duration*0.0343/2;
  return dist;
}