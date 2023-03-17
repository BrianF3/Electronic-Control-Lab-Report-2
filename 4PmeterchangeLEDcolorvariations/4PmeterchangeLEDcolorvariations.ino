/*
This code reads the analog value of a potentiometer connected to pin A1 and adjusts the brightness of 
an RGB LED based on the potentiometer reading. The LED changes color from black to white through 
different color variations depending on the value of the potentiometer. 
The code also prints the sensor value and voltage value to the Serial Monitor.
*/
// Define PWM pins for RGB LED
int ledR = 9;
int ledG = 10;
int ledB = 11;

// Define pin for the potentiometer
const int POTENTIOMETER_PIN = A0;

// Declare variables for brightness levels
int brightnessR = 0;
int brightnessG = 0;
int brightnessB = 0;

void setup() {
  // Initialize pin modes for RGB LED
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Read value from the potentiometer
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  Serial.println(potentiometerValue); // Debugging line to monitor potentiometer value

  // Map potentiometer value to RGB color
  if (potentiometerValue >= 0 && potentiometerValue < 204) {
    // Black
    brightnessR = 0;
    brightnessG = 0;
    brightnessB = 0;
  } else if (potentiometerValue >= 204 && potentiometerValue < 409) {
    // Light orange
    brightnessR = 255;
    brightnessG = 128;
    brightnessB = 0;
  } else if (potentiometerValue >= 409 && potentiometerValue < 614) {
    // Light purple
    brightnessR = 128;
    brightnessG = 0;
    brightnessB = 255;
  } else if (potentiometerValue >= 614 && potentiometerValue < 819) {
    // Cyan
    brightnessR = 0;
    brightnessG = 255;
    brightnessB = 255;
  } else {
    // White
    brightnessR = 255;
    brightnessG = 255;
    brightnessB = 255;
  }

  // Set RGB LED to selected color
  analogWrite(ledR, brightnessR);
  analogWrite(ledG, brightnessG);
  analogWrite(ledB, brightnessB);

  // Wait for a short period of time before looping again
  delay(100);
}
