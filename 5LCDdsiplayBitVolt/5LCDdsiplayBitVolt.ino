/*
This code reads the voltage value from a potentiometer connected to an Arduino board and displays it on an LCD screen
and the code reads the voltage value from that pin using the analogRead function. 
The voltage value is then displayed on the LCD screen using the LiquidCrystal library.
*/
#include <LiquidCrystal.h>

// Define the analog input pin for the potentiometer
const int PM = A0;

float x;

// Initialize the LiquidCrystal library with the pins connected to the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(PM, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows
}

void loop() {
  int potValue = analogRead(PM);  // Read the value from the potentiometer
  x = (5.0 / 1023.0);  // Convert ADC reading to voltage

  // Print the potentiometer value and voltage on the serial monitor
  Serial.print("potValue = ");
  Serial.print(potValue);
  Serial.print("  VoltageValue = ");
  Serial.println(potValue * x);

  // Display the potentiometer value and voltage on the LCD
  lcd.print("potVal= ");
  lcd.print(potValue);
  lcd.print("   ");
  lcd.setCursor(0, 0);
  lcd.print("VoltVal= ");
  lcd.print(potValue * x);
  lcd.print("   ");
  lcd.setCursor(0, 1);
}
