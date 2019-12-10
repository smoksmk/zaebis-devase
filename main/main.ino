
// include the library code:
#include <LiquidCrystal.h>

byte bukva_B[8]   = {B11110,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Б"
byte bukva_G[8]   = {B11111,B10001,B10000,B10000,B10000,B10000,B10000,B00000,}; // Буква "Г"
byte bukva_D[8]   = {B01111,B00101,B00101,B01001,B10001,B11111,B10001,B00000,}; // Буква "Д"
byte bukva_ZH[8]  = {B10101,B10101,B10101,B11111,B10101,B10101,B10101,B00000,}; // Буква "Ж"
byte bukva_Z[8]   = {B01110,B10001,B00001,B00010,B00001,B10001,B01110,B00000,}; // Буква "З"
byte bukva_I[8]   = {B10001,B10011,B10011,B10101,B11001,B11001,B10001,B00000,}; // Буква "И"
byte bukva_IY[8]  = {B01110,B00000,B10001,B10011,B10101,B11001,B10001,B00000,}; // Буква "Й"
byte bukva_L[8]   = {B00011,B00111,B00101,B00101,B01101,B01001,B11001,B00000,}; // Буква "Л"
byte bukva_P[8]   = {B11111,B10001,B10001,B10001,B10001,B10001,B10001,B00000,}; // Буква "П"
byte bukva_Y[8]   = {B10001,B10001,B10001,B01010,B00100,B01000,B10000,B00000,}; // Буква "У"
byte bukva_F[8]   = {B00100,B11111,B10101,B10101,B11111,B00100,B00100,B00000,}; // Буква "Ф"
byte bukva_TS[8]  = {B10010,B10010,B10010,B10010,B10010,B10010,B11111,B00001,}; // Буква "Ц"
byte bukva_CH[8]  = {B10001,B10001,B10001,B01111,B00001,B00001,B00001,B00000,}; // Буква "Ч"
byte bukva_Sh[8]  = {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00000,}; // Буква "Ш"
byte bukva_Shch[8]= {B10101,B10101,B10101,B10101,B10101,B10101,B11111,B00001,}; // Буква "Щ"
byte bukva_Mz[8]  = {B10000,B10000,B10000,B11110,B10001,B10001,B11110,B00000,}; // Буква "Ь"
byte bukva_IYI[8] = {B10001,B10001,B10001,B11001,B10101,B10101,B11001,B00000,}; // Буква "Ы"
byte bukva_Yu[8]  = {B10010,B10101,B10101,B11101,B10101,B10101,B10010,B00000,}; // Буква "Ю"
byte bukva_Ya[8]  = {B01111,B10001,B10001,B01111,B00101,B01001,B10001,B00000,}; // Буква "Я"
 

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonPin = 6;
int buttonState = 0;


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.createChar(1, bukva_D);      // Создаем символ под номером 1 
  lcd.createChar(2, bukva_L);      // Создаем символ под номером 2
  lcd.createChar(3, bukva_Mz);      // Создаем символ под номером 3
  lcd.createChar(4, bukva_Z);      // Создаем символ под номером 4
  lcd.createChar(5, bukva_B);      // Создаем символ под номером 5
  lcd.createChar(6, bukva_I);      // Создаем символ под номером 6
  lcd.createChar(7, bukva_Ya);      // Создаем символ под номером 7
  // lcd.createChar(8, bukva_L);      // Создаем символ под номером 8
  pinMode(buttonPin, INPUT);

}


void print_phrase_1(){
 lcd.setCursor(0, 0);             // Устанавливаем курсор на 1 строку ячейку 3
 lcd.print("C\1E\2AT\3 \4AE\5\6C\3?");    //Сделать заебись?             
 
}


void print_phrase_2(){
 lcd.setCursor(0, 0);             // Устанавливаем курсор на 1 строку ячейку 3
 lcd.print("\4AE\5\6C\3 \1E\2AETC\7");                 //Заебись делается
  
}


void print_phrase_3(){
 lcd.setCursor(0, 0);             // Устанавливаем курсор на 1 строку ячейку 3
 lcd.print("\4AE\5\6C\3 C\1E\2AHO!");          // Заебись сделано! 
}


void print_load(){
  for (int i=0; i<=16; i++){
    lcd.setCursor(i, 2);
    lcd.print("\xFF");  
    delay(1000);
  } 
  lcd.clear();
}


void loop() {
  buttonState = digitalRead(buttonPin);
  print_phrase_1();
  if (buttonState == LOW) {
   print_phrase_2();
   print_load();
   print_phrase_3();
   delay(10000);
  } 
  

}
