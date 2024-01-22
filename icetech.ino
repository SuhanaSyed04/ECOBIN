#include <Servo.h>

Servo myservo;  // Create a servo object
const int trigPin1 = 6;  // Define the trigger pin
const int echoPin1 = 7; // Define the echo pin
long duration1;
int distance1;

// Define the pins for the ultrasonic sensor
const int trigPin = 5;
const int echoPin = 4;

// Define the pins for the LEDs
const int redLEDPin = 2;
const int greenLEDPin = 3;

// Define the maximum distance for the sensor (in centimeters)
const int maxDistance = 10;


void setup() {
  myservo.attach(8); // Attaches the servo on pin 11
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

 // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // Initialize the LED pins
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
 
  // Turn off both LEDs initially
  digitalWrite(redLEDPin, LOW);
  digitalWrite(greenLEDPin, LOW);
 
  Serial.begin(9600);
}

void loop() {

// Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Measure the time it takes for the pulse to return
  long duration = pulseIn(echoPin, HIGH);
 
  // Calculate the distance in centimeters
  int distance = duration / 58;  // Speed of sound is 343 m/s, so 1 cm is 58 microseconds
 
  // Print the distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
  // Check if the distance is less than 5 cm
  if (distance < maxDistance) {
    // Turn on the red LED
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
  } else {
    // Turn on the green LED
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
  }

 
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the echo pulse duration
  duration1 = pulseIn(echoPin1, HIGH);
 
  // Calculate the distance in centimeters
  distance1 = duration1 * 0.034 / 2;
 
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");
 
  // Check if the distance is less than 10 cm
  if (distance1 < 15) {
    // Rotate the servo 90 degrees
 
    myservo.write(90);
   
    // Wait for 5 seconds
    delay(10000);
   
    // Return the servo to 0 degrees
    myservo.write(0);
  }
 
  // Add a delay before the next reading
  delay(500);

}
