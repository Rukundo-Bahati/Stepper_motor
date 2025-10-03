# Stepper Motor Serial Control

This Arduino project allows you to control a **stepper motor** via serial commands.
You can rotate the motor by specifying the desired angle (positive or negative) in degrees.

---

## Features

* Control a stepper motor through the Arduino Serial Monitor (or any serial terminal).
* Accepts commands like:

  ```
  rotate 180 degrees
  rotate -270 degrees
  ```
* Supports both clockwise and counter-clockwise rotation.
* Provides feedback in the serial monitor.

---

##  Hardware Requirements

* Arduino board (e.g., Uno, Nano, Mega)
* Stepper motor (e.g., 28BYJ-48 or NEMA 17)
* Stepper motor driver (ULN2003, L293D, or similar)
* Jumper wires and power supply

---

## Wiring

The pins used in the sketch are:

| Stepper Pin | Arduino Pin |
| ----------- | ----------- |
| IN1         | 8           |
| IN2         | 9           |
| IN3         | 10          |
| IN4         | 11          |

>  Adjust wiring to match your stepper motor driver. Update the `Stepper` object in code if using different pins.

---

## Software Setup

1. Install the Arduino IDE.
2. Connect your Arduino board via USB.
3. Open the sketch in the IDE.
4. Upload it to your board.

---

## Usage

1. Open the **Serial Monitor** (`Ctrl+Shift+M`) in the Arduino IDE.
2. Set baud rate to **9600**.
3. Type commands in the following format:

   ```
   rotate <angle> degrees
   ```

   * Positive angle → rotates **clockwise**
   * Negative angle → rotates **counter-clockwise**

### Example Commands

* `rotate 90 degrees` → rotate motor **90° clockwise**
* `rotate -180 degrees` → rotate motor **180° counter-clockwise**

---

##  Adjustments

* **Steps per Revolution**: Update

  ```cpp
  const int stepsPerRevolution = 200;
  ```

  to match your motor specification (e.g., 2048 for 28BYJ-48).

* **Pin Mapping**: Change

  ```cpp
  Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
  ```

  if your wiring is different.

---

## Notes

* Ensure your stepper motor is powered adequately. Some motors require an external power supply.
* Running the motor too fast may cause missed steps—experiment with delays or acceleration if needed.
* This code is a basic implementation. For smoother motion, consider libraries like **AccelStepper**.
