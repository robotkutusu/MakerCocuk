#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
#define buzzer 9


int buzzerState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
long interval = 1000;           // interval at which to blink (milliseconds)


void setup() {
  Serial.begin       (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;


 interval = distance*25;           
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (buzzerState == LOW) {
      buzzerState = HIGH;
    } else {
      buzzerState = LOW;
    }

    // set the LED with the ledState of the variable:
    if(distance>40){
      buzzerState=LOW;
      }
      else if(distance<4){
        
        buzzerState=HIGH;
        }
    digitalWrite(buzzer, buzzerState);
}
      
    Serial.print(distance);
    Serial.println(" cm");


}
