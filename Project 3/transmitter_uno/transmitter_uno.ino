#define echoPin 7
#define trigPin 6
void setup()
{
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}


int historyVal = 0;
void loop()
{
  int val = distance();
  if (historyVal == val ) {
  } else {
    historyVal = val;
    Serial.print(val);
  }
  delay(200);
}


int distance() {
  long duration; // variable for the duration of sound wave travel
  int distance; // variable for the distance measurement



  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  //  Serial.print("Distance: ");
  //  Serial.print(distance);
  //  Serial.println(" cm");

  return distance;
}
