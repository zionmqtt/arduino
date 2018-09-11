#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 20,4);

// caratteri pacman: personaggi e cibo

byte pacmanopenrightChar[8] = {
  B00000,
  B01110,
  B11101,
  B11111,
  B11000,
  B11111,
  B01110,
  B00000
};


byte pacmanopenleftChar[8] = {
  B00000,
  B01110,
  B10111,
  B11111,
  B00011,
  B11111,
  B01110,
  B00000
};

byte ghostChar[8] = {
  B00000,
  B01110,
  B10101,
  B11111,
  B11111,
  B11111,
  B10101,
  B00000
};

byte ghostfearChar[] = {
  B00000,
  B01110,
  B10101,
  B11111,
  B10001,
  B11111,
  B10101,
  B00000
};

byte eatsmallChar[8] = {
  B00000,
  B00000,
  B00000,
  B00110,
  B00110,
  B00000,
  B00000,
  B00000
};

byte eatbigChar[8] = {
  B00000,
  B00000,
  B01111,
  B01111,
  B01111,
  B01111,
  B00000,
  B00000
};

// percorso

byte horizontalChar[] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte verticalrightChar[] = {
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B11111
};

byte verticalleftChar[] = {
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11111
};

void setup() {

  lcd.init();

  lcd.setCursor(5,0);
  lcd.write("PACMAN demo");
  lcd.setCursor(0,1);
  lcd.write("www.michelepisani.it");
  for (int i=0; i<20; i++) {
    lcd.setCursor(i,2);
    lcd.write(byte(5));
  }  
  lcd.setCursor(7,3);
  lcd.write(byte(0));
  lcd.setCursor(8,3);
  lcd.write(byte(3));
  lcd.setCursor(9,3);
  lcd.write(byte(3));
  lcd.setCursor(10,3);
  lcd.write(byte(3));
  lcd.setCursor(11,3);
  lcd.write(byte(3));
  lcd.setCursor(12,3);
  lcd.write(byte(2));

  // creazione caratteri speciali
  lcd.createChar(0, pacmanopenrightChar);
  lcd.createChar(1, pacmanopenleftChar);
  lcd.createChar(2, ghostChar);
  lcd.createChar(3, eatsmallChar);
  lcd.createChar(4, eatbigChar);
  lcd.createChar(5, horizontalChar);
  lcd.createChar(6, verticalrightChar);
  lcd.createChar(7, verticalleftChar);  
  
}

void loop() {

  delay(4000);

  // scenario
  for (int i=0; i<20; i++) {
    lcd.setCursor(i,0);
    lcd.write(byte(3));
    lcd.setCursor(i,1);
    lcd.write(byte(5));
    lcd.setCursor(i,2);
    lcd.write(byte(3));
    lcd.setCursor(i,3);
    lcd.write(byte(5));
  }

  lcd.setCursor(12,3);
  lcd.write(byte(6));
  lcd.setCursor(13,3);
  lcd.write(3);
  lcd.setCursor(14,3);
  lcd.write(byte(7));

  lcd.setCursor(10,1);
  lcd.write(byte(6));
  lcd.setCursor(11,1);
  lcd.write(3);
  lcd.setCursor(12,1);
  lcd.write(byte(7));

  lcd.setCursor(6,1);
  lcd.write(byte(6));
  lcd.setCursor(7,1);
  lcd.write(3);
  lcd.setCursor(8,1);
  lcd.write(byte(7));   

  // cibo speciale
  lcd.setCursor(0,0);
  lcd.write(byte(4));
  lcd.setCursor(19,2);
  lcd.write(byte(4));   

  // pacman
  lcd.setCursor(4,0);
  lcd.write(byte(0));

  // fantasma
  lcd.setCursor(8,0);
  lcd.write(byte(2));

  lcd.setCursor(2,2);
  lcd.write(byte(2));

  lcd.setCursor(15,2);
  lcd.write(byte(2));
  
  delay(500);
  // step 1
  lcd.setCursor(5,0);
  lcd.write(byte(0));
  lcd.setCursor(4,0);
  lcd.write(" ");
  lcd.setCursor(7,0);
  lcd.write(byte(2));
  lcd.setCursor(8,0);
  lcd.write(byte(3));

  lcd.setCursor(3,2);
  lcd.write(byte(2));
  lcd.setCursor(2,2);
  lcd.write(byte(3)); 

  lcd.setCursor(14,2);
  lcd.write(byte(2));
  lcd.setCursor(15,2);
  lcd.write(byte(3)); 

  delay(500);
  // step 2
  lcd.setCursor(4,0);
  lcd.write(byte(1));
  lcd.setCursor(5,0);
  lcd.write(" ");
  lcd.setCursor(6,0);
  lcd.write(byte(2));
  lcd.setCursor(7,0);
  lcd.write(byte(3));

  lcd.setCursor(4,2);
  lcd.write(byte(2));
  lcd.setCursor(3,2);
  lcd.write(byte(3));

  lcd.setCursor(13,2);
  lcd.write(byte(2));
  lcd.setCursor(14,2);
  lcd.write(byte(3)); 

  delay(500);
  // step 3
  lcd.setCursor(3,0);
  lcd.write(byte(1));
  lcd.setCursor(4,0);
  lcd.write(" ");
  lcd.setCursor(5,0);
  lcd.write(byte(2));
  lcd.setCursor(6,0);
  lcd.write(byte(3));

  lcd.setCursor(5,2);
  lcd.write(byte(2));
  lcd.setCursor(4,2);
  lcd.write(byte(3));

  lcd.setCursor(12,2);
  lcd.write(byte(2));
  lcd.setCursor(13,2);
  lcd.write(byte(3));   
 
  delay(500);
  // step 4
  lcd.setCursor(2,0);
  lcd.write(byte(1));
  lcd.setCursor(3,0);
  lcd.write(" ");
  lcd.setCursor(4,0);
  lcd.write(byte(2));
  lcd.setCursor(5,0);
  lcd.write(" ");

  lcd.setCursor(6,2);
  lcd.write(byte(2));
  lcd.setCursor(5,2);
  lcd.write(byte(3));

  lcd.setCursor(11,2);
  lcd.write(byte(2));
  lcd.setCursor(12,2);
  lcd.write(byte(3)); 

  delay(500);
  // step 5
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(" ");
  lcd.setCursor(3,0);
  lcd.write(byte(2));
  lcd.setCursor(4,0);
  lcd.write(" ");

  lcd.setCursor(7,2);
  lcd.write(byte(2));
  lcd.setCursor(6,2);
  lcd.write(byte(3));

  lcd.setCursor(11,1);
  lcd.write(byte(2));
  lcd.setCursor(11,2);
  lcd.write(byte(3));   

  delay(500);
  // step 6
  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.setCursor(1,0);
  lcd.write(" ");
  lcd.setCursor(2,0);
  lcd.write(byte(2));
  lcd.setCursor(3,0);
  lcd.write(" ");

  lcd.setCursor(7,1);
  lcd.write(byte(2));
  lcd.setCursor(7,2);
  lcd.write(byte(3));

  lcd.setCursor(11,0);
  lcd.write(byte(2));
  lcd.setCursor(11,1);
  lcd.write(byte(3)); 

  delay(250);
  lcd.noBacklight();
  lcd.createChar(2, ghostfearChar);
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();    

  delay(500);
  // step 7
  lcd.setCursor(1,0);
  lcd.write(byte(0));
  lcd.setCursor(0,0);
  lcd.write(" ");

  delay(500);
  // step 8
  lcd.setCursor(2,0);
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(" ");
  lcd.setCursor(3,0);
  lcd.write(byte(2));

  lcd.setCursor(7,2);
  lcd.write(byte(2));
  lcd.setCursor(7,1);
  lcd.write(byte(3));

  lcd.setCursor(12,0);
  lcd.write(byte(2));
  lcd.setCursor(11,0);
  lcd.write(byte(3));    

  delay(500);
  // step 9
  lcd.setCursor(3,0);
  lcd.write(byte(0));
  lcd.setCursor(2,0);
  lcd.write(" ");

  delay(500);
  // step 10
  lcd.setCursor(4,0);
  lcd.write(byte(0));
  lcd.setCursor(3,0);
  lcd.write(" ");

  delay(500);
  // step 11
  lcd.setCursor(5,0);
  lcd.write(byte(0));
  lcd.setCursor(4,0);
  lcd.write(" "); 
 
  delay(500);
  // step 12
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.write(" ");

  lcd.setCursor(6,2);
  lcd.write(byte(2));
  lcd.setCursor(7,2);
  lcd.write(byte(3));

  lcd.setCursor(13,0);
  lcd.write(byte(2));
  lcd.setCursor(12,0);
  lcd.write(byte(3));

  delay(500);
  // step 13
  lcd.setCursor(7,0);
  lcd.write(byte(0));
  lcd.setCursor(6,0);
  lcd.write(" ");  

  delay(500);
  // step 14
  lcd.setCursor(8,0);
  lcd.write(byte(0));
  lcd.setCursor(7,0);
  lcd.write(" ");

  delay(500);
  // step 15
  lcd.setCursor(9,0);
  lcd.write(byte(0));
  lcd.setCursor(8,0);
  lcd.write(" ");

  delay(500);
  // step 16
  lcd.setCursor(10,0);
  lcd.write(byte(0));
  lcd.setCursor(9,0);
  lcd.write(" ");  

  delay(250);
  lcd.noBacklight();
  lcd.createChar(2, ghostChar);
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();  

  delay(500);
  // step 17
  lcd.setCursor(9,0);
  lcd.write(byte(1));
  lcd.setCursor(10,0);
  lcd.write(" ");

  lcd.setCursor(7,2);
  lcd.write(byte(2));
  lcd.setCursor(6,2);
  lcd.write(byte(3));

  lcd.setCursor(12,0);
  lcd.write(byte(2));
  lcd.setCursor(13,0);
  lcd.write(byte(3));

  delay(500);
  // step 18
  lcd.backlight();
  lcd.setCursor(8,0);
  lcd.write(byte(1));
  lcd.setCursor(9,0);
  lcd.write(" ");

  lcd.setCursor(7,1);
  lcd.write(byte(2));
  lcd.setCursor(7,2);
  lcd.write(byte(3));

  lcd.setCursor(11,0);
  lcd.write(byte(2));
  lcd.setCursor(12,0);
  lcd.write(byte(3));

  delay(500);
  // step 19
  lcd.setCursor(7,0);
  lcd.write(byte(2));
  lcd.setCursor(8,0);
  lcd.write(" ");

  lcd.setCursor(7,1);
  lcd.write(byte(3));

  lcd.setCursor(10,0);
  lcd.write(byte(2));
  lcd.setCursor(11,0);
  lcd.write(byte(3));

  lcd.setCursor(5,2);
  lcd.write("GAME OVER");

  delay(1000);
}
