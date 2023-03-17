/*
This code blinks an LED at a specified interval using the millis() function 
and toggles another LED based on the state of a pushbutton. 
The button is read using digitalRead() and the LED is controlled with digitalWrite(). 
The serial communication is also used to output the state of the pushbutton.
*/
const int ledPin = 13;       // the pin that the LED is attached to
const int ledPin2 = 11;      // the pin that the other LED is attached to
const int buttonPin = 6;     // the pin that the button is attached to
int buttonState = 0;         // variable to store the button state
int ledState = LOW;          // variable used to store the current LED state

unsigned long previousMillis = 0;  // stores the time of the last LED blink
const long interval = 1000;        // interval at which to blink the LED in milliseconds

void setup() {
  Serial.begin(9600);           // initialize serial communication
  pinMode(ledPin, OUTPUT);      // set the LED pin as an output
  pinMode(ledPin2, OUTPUT);     // set the other LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP);   // Assign buttonPin as an INPUT_PULLUP or internal pull up
}

void loop() {
  unsigned long currentMillis = millis();

  // check if it's time to blink the LED again
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);  // set the LED with the ledState of the variable
  }

  // read the state of the button
  buttonState = digitalRead(buttonPin);

  // turn on/off the other LED based on the button state
  if (buttonState == HIGH) {        // button is not pressed
    digitalWrite(ledPin2, HIGH);    // turn the other LED on
  } else {                          // button is pressed
    digitalWrite(ledPin2, LOW);     // turn the other LED off
  }

  // print the button state to the serial monitor
  Serial.print("Button state: ");
  Serial.println(buttonState);
}
