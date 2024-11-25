<h1>Obstacle-Avoiding Aqua Boat</h1>
<p>
  This project implements an Arduino-based obstacle-avoiding aqua boat. The boat is equipped with ultrasonic sensors for obstacle detection, a single motor for propulsion, and a servo motor for directional control. The system intelligently navigates around obstacles while maintaining its course.
</p>
<br>
<br>

<h2>Features</h2>
<ul>
  <li>
    Obstacle Detection: Uses three HC-SR04 ultrasonic sensors to detect obstacles in front, left, and right directions.
  </li>
  <li>
    Autonomous Navigation: Avoids obstacles based on predefined conditions.
  </li>
  <li>
    Single Motor Propulsion: Controls the forward and backward movement of the boat.
  </li>
  <li>
    Directional Control: Uses a servo motor for turning left or right.
  </li>
  <li>
    Real-Time Distance Monitoring: Outputs sensor readings to the serial monitor for debugging.
  </li>
</ul>
<br>


<h2>Components Required</h2>
<ul>
  <li>
    Arduino Nano (or equivalent microcontroller)
  </li>
  <li>
    HC-SR04 Ultrasonic Sensors (3 units)
  </li>
  <li>
    DC Motor (for propulsion)
  </li>
  <li>
    Motor Driver Module (e.g., L298N or similar)
  </li>
  <li>
    Servo Motor (for directional control)
  </li>
  <li>
    Battery Pack (suitable for powering the Arduino and motors)
  </li>
  <li>
    Connecting Wires
  </li>
  <li>
    Boat Frame (aqua boat chassis)
  </li>
</ul>
<br>


<h2>Circuit Diagram</h2>
<ol>
  <li>
    Ultrasonic Sensors:
  </li>
  <ul>
    <li>
      Front Sensor: Trig to pin 2, Echo to pin 3
    </li>
    <li>
      Left Sensor: Trig to pin 4, Echo to pin 5
    </li>
    <li>
      Right Sensor: Trig to pin 6, Echo to pin 7
    </li>
  </ul><br>
  <li>Motor Driver:</li>
  <ul><li>Motor control pins: 8 and 9</li></ul><br>
  <li>Servo Motor:</li>
  <ul><li>Control pin: 10</li></ul>  <br>
  <li>Power the components with an appropriate battery (e.g., 5V and 12V Li-ion).</li>
</ol>
<br>


<h2>Code Explanation</h2>
The program uses the following logic for navigation:

<h3>A. No Obstacles</h3>
If no obstacles are detected within a safe distance (30 cm):
<ul><li>The boat moves forward.</li></ul><br>

<h3>B. One-Sided Obstacle</h3>
<ol>
  <li>
    Front Obstacle: Turns left or right based on the availability of space.
  </li>
  <li>
    Left Obstacle: Moves forward or right.
  </li>
  <li>
    Right Obstacle: Moves forward or left.
  </li>
</ol><br>


<h3>C. Two-Sided Obstacles</h3>
<ol>
  <li>
    Front and Left Obstacle: Turns right.
  </li>
  <li>
    Front and Right Obstacle: Turns left.
  </li>
  <li>
    Left and Right Obstacle: Moves forward.
  </li>
</ol>



<h3>D. All-Sided Obstacles</h3>
If obstacles are detected in all three directions:
<ul><li>The boat stops.</li></ul><br>



<h2>How to Use</h2>
<ol>
  <li>Assemble the Circuit:</li>
  <ul><li>Follow the circuit diagram to connect the components.</li></ul>
  <br>
  <li>Upload the Code:</li>
  <ul>
    <li>Open the .ino file in the Arduino IDE.</li>
    <li>Select the correct board (Arduino Nano) and COM port.</li>
    <li>Upload the code to the Arduino Nano.</li>
  </ul><br>
  <li>Power On:</li>
  <ul><li>Power the Arduino and motor driver.</li></ul>
  <br>

  <li>Observe and Test:</li>
  <ul>
    <li>
      Place the boat in water and monitor its obstacle-avoiding behavior.
    </li>
    <li>
      Use the serial monitor for real-time distance readings.
    </li>
  </ul>
</ol>
<br>


<h2>Code</h2>
You can find the code in the file boat_control.ino. Below are the key functions used:

<ul>
  <li>measureDistance(): Measures the distance using ultrasonic sensors.</li>
  <li>moveForward(): Moves the boat forward.</li>
  <li>moveBackward(): Moves the boat backward.</li>
  <li>turnLeft(): Turns the boat left by adjusting the servo motor.</li>
  <li>turnRight(): Turns the boat right by adjusting the servo motor.</li>
  <li>stopBoat(): Stops the boat's movement.</li>
</ul>
<br>


<h2>Future Improvements</h2>
<ul>
  <li>
    Enhanced Navigation Algorithms: Use advanced path-planning algorithms for smoother navigation.
  </li>
  <li>
    Additional Sensors: Integrate water-quality sensors or GPS for enhanced functionality.
  </li>
  <li>
    Speed Control: Add PWM control for the propulsion motor for smoother movement.
  </li>
</ul><br>


<h3>License</h3>
This project is open-source and licensed under the MIT License. You are free to use, modify, and distribute it as long as proper credit is given.
<br>

<h6>Feel free to modify or expand this file as per your project's needs!</h6>






