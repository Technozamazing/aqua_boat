// Pin definitions
#define trigPinFront 2
#define echoPinFront 3

#define trigPinLeft 4
#define echoPinLeft 5

#define trigPinRight 6
#define echoPinRight 7


#define motor1Pin1 8
#define motor1Pin2 9

#define motor2Pin1 10
#define motor2Pin2 11


// Constants
#define SAFE_DISTANCE 30  // Minimum distance in cm to consider safe



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
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("MOVE FORWARD");
}



// Function to turn the boat left
void turnLeft() 
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("MOVE LEFT");
}



// Function to turn the boat right
void turnRight() 
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  Serial.println("MOVE RIGHT");
}



// Function to stop the boat
void stopBoat() 
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  Serial.println("!!!STOP!!!");
}



void setup() 
{
  // Initializing sensors pins
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

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
    moveForward();
  } 



  //front obstacle
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
  } 



  //left obstacle
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
    if (distanceFront > distanceRight) 
    {
      moveForward();
    } 
    else 
    {
      turnRight();
    }
  } 




  //right obstacle
  else if (distanceFront > SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
    if (distanceFront > distanceLeft) 
    {
      moveForward();
    } 
    else 
    {
      turnLeft();
    }
  } 




  //front and left obstacles
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight > SAFE_DISTANCE) 
  {
    turnRight();
  } 


  //front and right obstacles
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft > SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
    turnLeft();
  } 


  //left and right obstacles
  else if (distanceFront > SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
    moveForward();
  } 


  //all three sided obstacles
  else if (distanceFront <= SAFE_DISTANCE && distanceLeft <= SAFE_DISTANCE && distanceRight <= SAFE_DISTANCE) 
  {
    stopBoat();
  }

  delay(1000); // Small delay for stability
  Serial.println("");
}
