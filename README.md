<h1>Obstacle-Avoiding Aqua Boat</h1>

This project implements an Arduino-based obstacle-avoiding aqua boat. The boat is equipped with ultrasonic sensors for obstacle detection, a single motor for propulsion, and a servo motor for directional control. The system intelligently navigates around obstacles while maintaining its course.
<hr>

Features
Obstacle Detection: Uses three HC-SR04 ultrasonic sensors to detect obstacles in front, left, and right directions.
Autonomous Navigation: Avoids obstacles based on predefined conditions.
Single Motor Propulsion: Controls the forward and backward movement of the boat.
Directional Control: Uses a servo motor for turning left or right.
Real-Time Distance Monitoring: Outputs sensor readings to the serial monitor for debugging.


Components Required
Arduino Nano (or equivalent microcontroller)
HC-SR04 Ultrasonic Sensors (3 units)
DC Motor (for propulsion)
Motor Driver Module (e.g., L298N or similar)
Servo Motor (for directional control)
Battery Pack (suitable for powering the Arduino and motors)
Connecting Wires
Boat Frame (aqua boat chassis)


Circuit Diagram
Ultrasonic Sensors:
Front Sensor: Trig to pin 2, Echo to pin 3
Left Sensor: Trig to pin 4, Echo to pin 5
Right Sensor: Trig to pin 6, Echo to pin 7
Motor Driver:
Motor control pins: 8 and 9
Servo Motor:
Control pin: 10
Power the components with an appropriate battery (e.g., 7.4V Li-ion).


Code Explanation
The program uses the following logic for navigation:

A. No Obstacles
If no obstacles are detected within a safe distance (30 cm):
The boat moves forward.

B. One-Sided Obstacle
Front Obstacle: Turns left or right based on the availability of space.
Left Obstacle: Moves forward or right.
Right Obstacle: Moves forward or left.

C. Two-Sided Obstacles
Front and Left Obstacle: Turns right.
Front and Right Obstacle: Turns left.
Left and Right Obstacle: Moves forward.

D. All-Sided Obstacles
If obstacles are detected in all three directions:
The boat stops.



How to Use
Assemble the Circuit:
Follow the circuit diagram to connect the components.
Upload the Code:
Open the .ino file in the Arduino IDE.
Select the correct board (Arduino Nano) and COM port.
Upload the code to the Arduino Nano.
Power On:
Power the Arduino and motor driver.
Observe and Test:
Place the boat in water and monitor its obstacle-avoiding behavior.
Use the serial monitor for real-time distance readings.


You can find the code in the file boat_control.ino. Below are the key functions used:

measureDistance(): Measures the distance using ultrasonic sensors.
moveForward(): Moves the boat forward.
moveBackward(): Moves the boat backward.
turnLeft(): Turns the boat left by adjusting the servo motor.
turnRight(): Turns the boat right by adjusting the servo motor.
stopBoat(): Stops the boat's movement.



Future Improvements
Enhanced Navigation Algorithms: Use advanced path-planning algorithms for smoother navigation.
Additional Sensors: Integrate water-quality sensors or GPS for enhanced functionality.
Speed Control: Add PWM control for the propulsion motor for smoother movement.


License
This project is open-source and licensed under the MIT License. You are free to use, modify, and distribute it as long as proper credit is given.

Feel free to modify or expand this file as per your project's needs!






