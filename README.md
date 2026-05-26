# 2-Axis Robotic Arm Forward Kinematics Simulator

An interactive, web-based hardware simulation of a 2-Axis Robotic Arm. This project demonstrates the real-life application of robotics kinematics transformation principles (Pure Rotation and the Multi-Frame Chain Rule) using an Arduino Uno, servo motors, and potentiometers.



---

## 🚀 Project Overview

In robotics, determining the exact position of a robot's end-effector (the tip of the hand) based on its joint angles is known as **Forward Kinematics**. This project translates abstract mathematical matrices into a functional hardware model where rotating physical dials (potentiometers) dynamically alters the robot's physical configuration and calculates its position in Cartesian space $(X, Y)$ in real-time.

---

## 🛠️ Hardware & Components Used

* **Microcontroller:** Arduino Uno (The processing core)
* **Actuators:** 2x SG90 Servo Motors (Representing the Shoulder and Elbow rotary joints)
* **Inputs:** 2x Manual Potentiometers (Acting as the control knobs for the angles)
* **Connections:** Virtual PWM and Analog Signal interfaces

---

## 📐 Mathematical Formulation (The Kinematics Model)

The project mathematically proves the matrix operations for **Case 2: Pure Rotation** and the **Multi-Frame Chain Rule**:

1. **Frame Transformations:** The base frame is fixed at the shoulder joint $\{A\}$. The intermediate frame is at the elbow joint $\{B\}$, and the target frame is the tip of the hand $\{C\}$.
2. **Trigonometric Matrix Resolution:** Using the individual link lengths ($L_1 = 10\text{ cm}$ and $L_2 = 8\text{ cm}$), the forward kinematic equations used in the embedded C++ loop are:

$$X = L_1 \cdot \cos(\theta_1) + L_2 \cdot \cos(\theta_1 + \theta_2)$$
$$Y = L_1 \cdot \sin(\theta_1) + L_2 \cdot \sin(\theta_1 + \theta_2)$$

Where:
* $\theta_1$ = Angle of Link 1 controlled by Potentiometer 1
* $\theta_2$ = Angle of Link 2 controlled by Potentiometer 2

---

## 🔌 Circuit Schematic & Wiring Details

The connections are cleanly mapped out to prevent signal degradation and cross-shorting:

### 1. Potentiometers (Inputs)
* **Potentiometer 1 (Shoulder Control):** `GND` ➡️ Arduino GND | `VCC` ➡️ Arduino 5V | `SIG` ➡️ Arduino Analog **A0**
* **Potentiometer 2 (Elbow Control):** `GND` ➡️ Arduino GND | `VCC` ➡️ Arduino 5V | `SIG` ➡️ Arduino Analog **A1**

### 2. Servo Motors (Outputs)
* **Servo 1 (Link 1 - Shoulder):** Ground (Black) ➡️ GND | Power (Red) ➡️ 5V | PWM Signal (Orange) ➡️ Digital **Pin 9**
* **Servo 2 (Link 2 - Elbow):** Ground (Black) ➡️ GND | Power (Red) ➡️ 5V | PWM Signal (Orange) ➡️ Digital **Pin 10**

---

## 💻 How to Run the Simulation

1. Open the repository files (`sketch.ino` for the program logic and `diagram.json` for the Wokwi workspace config).
2. Upload or launch the project environment inside the Wokwi Simulator.
3. Click the **Start Simulation** (Green Play) button.
4. Interact with the dials using your cursor to adjust the joint angles.
5. Open the **Serial Monitor** terminal at the bottom to view the live calculation logs tracking the exact $(X, Y)$ position coordinates.

---

## 📈 Learning Highlights
* Successfully diagnosed and resolved initial physical power short-circuits (`VCC`/`GND` pin overlap issues).
* Gained hands-on experience in embedding raw trigonometric kinematics formulas inside an active microcontroller environment.
* Implemented industry-standard documentation practices by syncing simulation schemas with Git version control.
