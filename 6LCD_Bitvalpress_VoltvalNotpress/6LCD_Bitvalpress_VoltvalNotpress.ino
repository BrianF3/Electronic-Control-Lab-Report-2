/*
This code uses a potentiometer and a pushbutton with an Arduino board to display the 
voltage and bit value on an LCD screen and the serial monitor. 
The potentiometer value is converted into a voltage value, which is then displayed on the LCD screen. 
The pushbutton is used to switch between displaying the bit value and voltage value on the LCD screen.
*/
// Include the LiquidCrystal library
#include <LiquidCrystal.h>

// Initialize the LCD display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Declare variables for the potentiometer and voltage value
float pM = A0;
float x;

// Declare variables for the pushbutton and its state
int pB = 6;
int buttonState;

void setup() {
// Initialize the LCD and Serial Monitor
lcd.begin(16, 2);
pinMode(pB, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
// Read the value of the potentiometer and calculate the voltage value
pM = analogRead(A0);
x = (pM/1023.0)*5.0;

// Read the state of the pushbutton
buttonState = digitalRead(pB);

// Display the bit value on the LCD screen if the button is not pressed
if(buttonState==HIGH){
lcd.setCursor(0, 0);
lcd.print("bVal=");
lcd.print(pM);
lcd.print(" ");
}
// Display the voltage value on the LCD screen if the button is pressed
else {
lcd.setCursor(0, 0);
lcd.print("vVal=");
lcd.print(x);
lcd.print(" ");
}

// Display voltage, bit value, and button state on the Serial Monitor
Serial.print("bVal=");
Serial.print(pM);
Serial.print("\t");
Serial.print("vVal=");
Serial.print(x);
Serial.print("\t");
Serial.print("pB=");
Serial.println(buttonState);
}