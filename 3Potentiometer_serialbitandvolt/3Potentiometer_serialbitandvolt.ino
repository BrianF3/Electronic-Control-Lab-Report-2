/*
The code reads the analog value of a sensor connected to pin A0, 
calculates the corresponding voltage value, and displays it on 
the Serial Monitor every 500 milliseconds
*/
// Define the analog input pin
const float PM = A0;

// Declare a variable to hold the voltage value
float x;

// Setup function runs once at the beginning of the program
void setup() {
  // Set the pin mode to input
  pinMode(PM, INPUT);
  // Initialize the Serial Monitor with a baud rate of 9600
  Serial.begin(9600);
}

// Loop function runs repeatedly while the program is running
void loop() {
  // Read the value from the analog input pin
  float sensorValue = analogRead(A0);
  // Calculate the voltage value from the analog input reading
  x = (5.0 / 1023.0);
  // Display the sensor value on the Serial Monitor
  Serial.print("sensorValue = ");
  Serial.println(sensorValue);
  // Display the voltage value on the Serial Monitor
  Serial.print("VoltageValue = ");
  Serial.println(sensorValue * x);
  // Wait for a short period of time
  delay(500);
}