#include <Servo.h>
#include <math.h>

Servo shoulderServo;
Servo elbowServo;

// Link Lengths (Maan lijiye dono robot links 10cm aur 8cm ke hain)
const float L1 = 10.0; 
const float L2 = 8.0;

void setup() {
  Serial.begin(9600);
  shoulderServo.attach(9);
  elbowServo.attach(10);
  Serial.println("--- Robotic Arm Kinematics Simulator Ready ---");
}

void loop() {
  // Knobs se values read karna (0 se 1023)
  int knob1 = analogRead(A0);
  int knob2 = analogRead(A1);

  // Unhe angles (degrees) mein badalna (0 to 180)
  float theta1_deg = map(knob1, 0, 1023, 0, 180);
  float theta2_deg = map(knob2, 0, 1023, 0, 180);

  // Motors ko ghumana (Case 2: Pure Rotation)
  shoulderServo.write(theta1_deg);
  elbowServo.write(theta2_deg);

  // Math calculation ke liye degrees ko Radians mein badalna
  float r1 = theta1_deg * M_PI / 180.0;
  float r2 = (theta1_deg + theta2_deg) * M_PI / 180.0; // Chain Rule Applied

  // Slide Math Formula: Coordinate Forward Kinematics
  float x = L1 * cos(r1) + L2 * cos(r2);
  float y = L1 * sin(r1) + L2 * sin(r2);

  // Wokwi ke Serial Monitor par live XY position print karna
  Serial.print("Angles: Link1=");
  Serial.print(theta1_deg);
  Serial.print("°, Link2=");
  Serial.print(theta2_deg);
  Serial.print("°  |  End-Effector Position: X = ");
  Serial.print(x);
  Serial.print(" cm, Y = ");
  Serial.print(y);
  Serial.println(" cm");

  delay(200); // 0.2 second ka wait taaki screen crash na ho
}