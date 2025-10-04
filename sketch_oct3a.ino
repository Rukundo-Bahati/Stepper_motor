#include <Stepper.h>

// 28BYJ-48 has 2048 steps per revolution (64 steps × 32:1 gear ratio)
const int stepsPerRevolution = 2048;  // Corrected for 28BYJ-48

// Create stepper object - typical pin configuration for ULN2003 driver
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // IN1, IN3, IN2, IN4

String inputString = "";

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(10); // RPM - important for 28BYJ-48 (5-15 RPM recommended)
  Serial.println("28BYJ-48 Stepper Motor Control Ready!");
  Serial.println("Type commands like: rotate 180 degrees or rotate -90 degrees");
}

void loop() {
  if (Serial.available()) {
    inputString = Serial.readStringUntil('\n');
    inputString.trim();

    if (inputString.startsWith("rotate")) {
      // Extract angle value
      int firstSpace = inputString.indexOf(' ');
      int secondSpace = inputString.indexOf(' ', firstSpace + 1);
      
      // Handle case where there's no "degrees" word
      if (secondSpace == -1) {
        secondSpace = inputString.length();
      }
      
      String angleStr = inputString.substring(firstSpace + 1, secondSpace);
      int angle = angleStr.toInt();

      // Convert angle to steps
      long stepsToMove = (long)angle * stepsPerRevolution / 360;

      Serial.print("Rotating ");
      Serial.print(angle);
      Serial.println(" degrees...");

      // Rotate motor
      myStepper.step(stepsToMove);

      Serial.println("Done.");
    }
    else {
      Serial.println("Invalid command. Use: rotate <angle>");
    }
  }
}
