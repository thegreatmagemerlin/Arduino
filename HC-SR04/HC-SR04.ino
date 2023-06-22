const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);

  delayMicroseconds(10);
  digitalWrite(10);
  digitalWrite(trigPin, 0);

  duration = pulseIn(echoPin, 1);
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
}
