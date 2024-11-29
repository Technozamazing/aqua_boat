//instead of two motors, a single motor for propulsion, and a servo motor for directional control

#include <Servo.h>

// Pin definitions
#define trigPinFront 2
#define echoPinFront 3

#define trigPinLeft 4
#define echoPinLeft 5

#define trigPinRight 6
#define echoPinRight 7

#define motorPin1 8  
#define motorPin2 9  

#define servoPin 10  // Servo motor pin

#define SAFE_DISTANCE 30  

Servo radarServo;  // Servo motor for turning    //variable


// Function to measure distance from the ultrasonic sensor
long measureDistance(int trigPin, int echoPin) 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034) / 2;
  return distance;
}



// Function to move the boat forward
void moveForward()
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}



// Function to move the boat backward
void moveBackward() 
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}



// Function to stop the boat
void stopBoat() 
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}



// Function to turn the boat left
void turnLeft() 
{
  radarServo.write(120);  // Set servo angle to turn left
}



// Function to turn the boat right
void turnRight() 
{
  radarServo.write(60);  // Set servo angle to turn right
}



// Function to center the servo
void centerDirection() 
{
  radarServo.write(90);  // Set servo to neutral (center) position
}



void setup() 
{
  // Initialize ultrasonic sensor pins
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);

  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  // Initialize motor pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Attach servo motor
  radarServo.attach(servoPin);
  centerDirection();

  Serial.begin(9600);
}

void loop() 
{
  // Measure distances
  long distanceFront = measureDistance(trigPinFront, echoPinFront);
  long distanceLeft = measureDistance(trigPinLeft, echoPinLeft);
  long distanceRight = measureDistance(trigPinRight, echoPinRight);

  // Display distances on Serial Monitor
  Serial.print("Front: ");
  Serial.print(distanceFront);
  Serial.print(" cm, Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm, Right: ");
  Serial.print(distanceRight);
  Serial.println(" cm");



  // Conditions for Boat Operations
  if (distanceFront > SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
     // A: NO OBSTACLES
     centerDirection();
     moveForward();
  } 



  //FRONT OBSTACLE
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
      if (distanceLeft > distanceRight) 
      {
         turnLeft();
      } 
      else 
      {
         turnRight();
      }
      moveForward();
  } 



  //LEFT OBSTACLE
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
     if (distanceFront > distanceRight) 
    {
     centerDirection();
    } 
    else 
    {
      turnRight();
    }
     moveForward();
  } 



  //RIGHT OBSTACLE
  else if (distanceFront > SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
     if (distanceFront > distanceLeft) 
    {
     centerDirection();
    } 
    else 
    {
      turnLeft();
    }
     moveForward();
  } 



  //FRONT AND LEFT OBSTACLES
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
     turnRight();
     moveForward();
  } 
  
  
  
  //FRONT AND RIGHT OBSTACLES
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
     turnLeft();
     moveForward();
  } 
  
  
  
  //LEFT AND RIGHT OBSTACLES
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
     centerDirection();
     moveForward();
  } 
  
  
  
  //FRONT, LEFT, AND RIGHT OBSTACLES
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
     stopBoat();
  }


  delay(100); // Small delay for stability
}
