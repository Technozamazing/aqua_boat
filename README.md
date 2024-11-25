<h1>Obstacle Avoiding Aqua Boat</h1>
<p>
  This project implements an Arduino-based obstacle-avoiding aqua boat. The boat is equipped with ultrasonic sensors for obstacle detection, a single motor for propulsion, and a servo motor for directional control. The system intelligently navigates around obstacles while maintaining its course.
</p>
<br>
<br>

<h2>Features</h2>
<ul>
  <li>
    <strong>
      Obstacle Detection:
    </strong>
     Uses three HC-SR04 ultrasonic sensors to detect obstacles in front, left, and right directions.
  </li>
  <li>
    <strong>
      Autonomous Navigation:
    </strong>
     Avoids obstacles based on predefined conditions.
  </li>
  <li>
    <strong>
      Single Motor Propulsion:
    </strong>
     Controls the forward and backward movement of the boat.
  </li>
  <li>
    <strong>
      Directional Control:
    </strong>
     Uses a servo motor for turning left or right.
  </li>
  <li>
    <strong>
      Real-Time Distance Monitoring:
    </strong>
     Outputs sensor readings to the serial monitor for debugging.
  </li>
</ul>
<br>


<h2>Components Required</h2>
<ul>
  <li>
    <strong>
      Arduino Nano
    </strong>
     (or equivalent microcontroller)
  </li>
  <li>
    <strong>
      HC-SR04 Ultrasonic Sensors
    </strong>
     (3 units)
  </li>
  <li>
    <strong>
      DC Motor
    </strong>
     (for propulsion)
  </li>
  <li>
    <strong>
      Motor Driver Module
    </strong>
     (e.g., L298N or similar)
  </li>
  <li>
    <strong>
      Servo Motor
    </strong>
     (for directional control)
  </li>
  <li>
    <strong>
      Battery Pack
    </strong>
     (suitable for powering the Arduino and motors)
  </li>
  <li>
    <strong> Connecting Wires</strong>
  </li>
  <li>
    <strong>
      Boat Frame
    </strong>
     (aqua boat chassis)
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
      Front Sensor: Trig to pin <code>2</code>, Echo to pin <code>3</code>
    </li>
    <li>
      Left Sensor: Trig to pin <code>4</code>, Echo to pin <code>5</code>
    </li>
    <li>
      Right Sensor: Trig to pin <code>6</code>, Echo to pin <code>7</code>
    </li>
  </ul><br>
  <li>Motor Driver:</li>
  <ul><li>Motor control pins: <code>8</code> and <code>9</code></li></ul><br>
  <li>Servo Motor:</li>
  <ul><li>Control pin: <code>10</code></li></ul>  <br>
  <li>Power the components with an appropriate battery (e.g., 5V and 12V Li-ion).</li>
</ol>
<br>


<h2>Code Explanation</h2>
The program uses the following logic for navigation:

<h4>A. No Obstacles</h4>
If no obstacles are detected within a safe distance (30 cm):
<ul><li>The boat moves forward.</li></ul><br>

<h4>B. One-Sided Obstacle</h4>
<ol>
  <li>
    <strong>
      Front Obstacle:
    </strong>
     Turns left or right based on the availability of space.
  </li>
  <li>
    <strong>
      Left Obstacle:
    </strong>
     Moves forward or right.
  </li>
  <li>
    <strong>
      Right Obstacle:
    </strong>
     Moves forward or left.
  </li>
</ol><br>


<h4>C. Two-Sided Obstacles</h4>
<ol>
  <li>
    <strong>Front and Left Obstacle:</strong>
     Turns <b>right.</b>
  </li>
  <li>
    <strong>
    Front and Right Obstacle:
    </strong>Turns <b>left.</b>
  </li>
  <li>
    <strong>
    Left and Right Obstacle:
    </strong>Moves <b>forward.</b>
  </li>
</ol><br>



<h4>D. All-Sided Obstacles</h4>
If obstacles are detected in all three directions:
<ul><li>The boat stops.</li></ul><br>



<h2>How to Use</h2>
<ol>
  <li><strong>Assemble the Circuit:</strong></li>
  <ul><li>Follow the circuit diagram to connect the components.</li></ul>
  <br>
  <li><strong>Upload the Code:</strong></li>
  <ul>
    <li>Open the <code>.ino</code> file in the Arduino IDE.</li>
    <li>Select the correct board <code>(Arduino Nano)</code> and COM port.</li>
    <li>Upload the code to the Arduino Nano.</li>
  </ul><br>
  <li><strong>Power On:</strong></li>
  <ul><li>Power the Arduino and motor driver.</li></ul>
  <br>

  <li><strong>Observe and Test:</strong></li>
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
You can find the code in the file <a href="https://github.com/Technozamazing/aqua_boat/tree/main">aqua_boat</a>. 
Below are the key functions used:

<ul>
  <li>
    <strong><code>measureDistance()</code></strong>
    : Measures the distance using ultrasonic sensors.
  </li>
  <li>
    <b><code>moveForward()</code></b>
    : Moves the boat forward.
  </li>
  <li>
    <strong>
      <code>moveBackward()</code>
    </strong>
     : Moves the boat backward.
  </li>
  <li>
    <strong>
      <code>turnLeft()</code>
    </strong>
    : Turns the boat left by adjusting the servo motor.
  </li>
  <li>
    <strong>
      <code>turnRight()</code>
    </strong>
    : Turns the boat right by adjusting the servo motor.
  </li>
  <li>
    <strong>
      <code>stopBoat()</code>
    </strong>
    : Stops the boat's movement.
  </li>
</ul>
<br>


<h2>Future Improvements</h2>
<ul>
  <li>
    <strong>
      Enhanced Navigation Algorithms:
    </strong>
     Use advanced path-planning algorithms for smoother navigation.
  </li>
  <li>
    <strong>
      Additional Sensors:
    </strong>
     Integrate water-quality sensors or GPS for enhanced functionality.
  </li>
  <li>
    <strong>
      Speed Control:
    </strong>
     Add PWM control for the propulsion motor for smoother movement.
  </li>
</ul><br>


<h3>License</h3>
This project is open-source and licensed under the MIT License. You are free to use, modify, and distribute it <code>as long as proper credit is given</code>.
<br>

<h6>Feel free to modify or expand this file as per your project's needs!</h6>

<code>See more at <a href="https://www.romanstha.com.np">Projects</a></code>






