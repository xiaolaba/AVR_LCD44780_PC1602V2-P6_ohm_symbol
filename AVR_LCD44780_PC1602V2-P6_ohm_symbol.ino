// char ROM is different from HD44780 standard, ohm symbol at offdet 175 or 0xAF
// xiaolaba, 2010-OCT-01

// include the library code:
// LCM 1602, model PC1602V2-P6, brand name : powertip



// LCM 1602, model PC1602V2-P6, brand naes : powertip
// char ROM is different from HD44780 standard, ohm symbol at offdet 175 or 0xAF

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

// LCM1602 pin name vs ESP32 GPIO pin#
// do not uses 34,35,36,39, all those are input GPIO only

// LCM1602 pin name vs Arduino NANO GPIO pin#
//const int rs = 8, en = 7, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal   lcd(8,  7,  6 , 5,  4,  3 );

uint8_t char_pattern_index = 170; // HD44780 compatibe, charecter code index, from 0x00 ~ 0xFF, char pattern on LCD display
 
void setup() {
  Serial.begin(115200);
  Serial.println("LCD 1602, Brand nanme : Powertip, model: PC1602V2-P6, testing by xiaolaba");
  Serial.println("ohm symbole is found @ 175, 0xAF");
  
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("PC1602V2-P6,xiaolaba");
}
 
void loop() {
  lcd.setCursor(0, 1);  // line 1 will display the char pattern
  lcd.print( "char(" ); lcd.print(char_pattern_index, DEC); lcd.print( ")0x" );lcd.print(char_pattern_index, HEX);
  lcd.setCursor(13, 1); lcd.print( "= " );
  lcd.print(char(char_pattern_index));
  char_pattern_index++;
  if (char_pattern_index >180) {char_pattern_index=170;}     // 
  
   
  // Turn off the display:
  lcd.noDisplay();
  delay(300);
  
  // Turn on the display:
  lcd.display();
  delay(800);
}
