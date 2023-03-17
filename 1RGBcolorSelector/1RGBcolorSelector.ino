/* This code is for controlling an RGB LED using PWM. 
The code sets the PWM values for the red, green, and blue pins to produce a specific color.
 */
 int ledR = 11;  // the PWM pin the red LED is attached to
int ledG = 10;  // the PWM pin the green LED is attached to
int ledB = 9;   // the PWM pin the blue LED is attached to

void setup() {
  // set the pins as output
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  // set the LED colors using analogWrite
  analogWrite(ledR, 155);  // set the red LED to a moderate brightness
  analogWrite(ledG, 6);    // set the green LED to a low brightness
  analogWrite(ledB, 125);  // set the blue LED to a moderate brightness
}