/*
This code is meant to be an ohmmeter using an Arduino board and an LCD 
screen to display resistance values. 
The custom character is used to display the Omega symbol on the LCD screen. 
The LCD screen also displays the current value of the current flowing through the resistance.
*/
#include <LiquidCrystal.h>   // include the library code

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   // initialize pins for LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    // create LCD object

byte customChar [] = {    // create custom character to display ohm symbol
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B11011,
  B00000,
};

void setup() {
  lcd.begin(16, 2);      // set up LCD screen dimensions
  lcd.createChar(0, customChar);   // load custom character into LCD memory
  analogRead(A0);        // initialize analog input
  Serial.begin(9600);    // initialize Serial Monitor with baud rate of 9600
}

void loop() {
  float val = analogRead(A0);   // read analog value
  float x = (val/1023.0)*5.0;   // convert analog reading to voltage
  float Ia = (5.0-x/0.989);     // calculate current flowing through resistor
  float Ib = Ia;                // assign value of Ia to Ib
  float Vb = x;                 // assign value of x to Vb
  float Rb = (Vb/Ib);           // calculate value of unknown resistor

  delay(1000);       // wait for a second
  lcd.setCursor(0,0);  // set cursor position for LCD
  lcd.print("Rb=");    // print label for unknown resistor
  lcd.print(Rb);       // display unknown resistor value
  lcd.print("k");      // print unit for kilo-ohms
  lcd.write((byte)0);  // display ohm symbol

  // display bit, voltage, current, and unknown resistor value on Serial Monitor
  Serial.print("bVal=");   
  Serial.print(val);       
  Serial.print("\t");      
  Serial.print("vVal=");   
  Serial.print(x);         
  Serial.print("\t");      
  Serial.print("Ia=");     
  Serial.print(Ia);        
  Serial.print("\t");      
  Serial.print("Rb=");     
  Serial.println(Rb);      
}