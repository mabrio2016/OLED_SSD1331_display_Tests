
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

//Use Board NodeMCU (esp12-module)
//Node-MCU ESP8266 GPIO pins and Pin lables
#define sclk 14 // D5
#define mosi 13 // D7
#define cs   15 // D8
#define rst  16 // D0
#define dc   2  // D4


//Use Arduino Nano Board
//GPIO pins
//#define sclk 13
//#define mosi 11
//#define cs   10
//#define rst  9
//#define dc   8

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

const unsigned char AppleBitmap [] PROGMEM = {
  // 'icons8-apple-logo-60, 30x30px
  0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x01, 0xf0, 0x00, 
  0x00, 0x01, 0xe0, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xf8, 0x7e, 0x00, 
  0x03, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0x80, 0x07, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xfe, 0x00, 
  0x0f, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xfc, 0x00, 
  0x0f, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x0f, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0x80, 
  0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x00, 
  0x01, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x30, 0x18, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
int x = 0;

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);

float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print("hello!");
  display.begin();

  Serial.println("init");
  uint16_t time = millis();
  display.fillScreen(BLACK);
  time = millis() - time;
  
  Serial.println(time, DEC);
  delay(500);

  display.fillScreen(BLACK);
  display.setCursor(0, 5);
  display.setTextColor(RED);  
  display.setTextSize(1.5);
  display.println("Marco Bandeira");
  delay(2000);
  lcdTestPattern(x);
  display.drawBitmap(10, 30, AppleBitmap, 30, 30, WHITE);  
  delay(2000);
}
  
void loop() {

//  display.drawBitmap(10, 30, AppleBitmap, 30, 30, WHITE);
//  delay(2000);    
    //To make the Log Blink
//  display.drawBitmap(10, 30, AppleBitmap, 30, 30, BLACK);
//  delay(2000);
     
delay(1000);
    if (x > 95 )
    {
       x = 0;
       lcdTestPattern(x);
       delay(1000); 
    }
    else 
    {
      x = x + 12;
      lcdTestPattern(x);      
      delay(100);
    }
    display.drawBitmap(10, 30, AppleBitmap, 30, 30, WHITE);    
}

/**************************************************************************/
/*! 
    @brief  Renders a simple test pattern on the LCD
*/
/**************************************************************************/
void lcdTestPattern(int x)
{
  uint8_t w,h;
  display.setAddrWindow(0, 0, 96, 64);
  
  for(h=0; h<64; h++)
  {
    for(w=0; w<96; w++)
    {
      if(w>83+x){display.writePixel(WHITE);}
      else if(w>71+x){display.writePixel(BLUE);}
      else if(w>59+x){display.writePixel(GREEN);}
      else if(w>47+x){display.writePixel(CYAN);}
      else if(w>35+x){display.writePixel(RED);}
      else if(w>23+x){display.writePixel(MAGENTA);}
      else if(w>11+x){display.writePixel(YELLOW);}
      else {display.writePixel(BLACK);}
    }
  }
  display.endWrite();
}

//void testdrawtext(char *text, uint16_t color) {
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(0,0);
//
//  for (uint8_t i=0; i < 168; i++) {
//    if (i == '\n') continue;
//    display.write(i);
//    if ((i > 0) && (i % 21 == 0))
//      display.println();
//  }    
//}
//
//void testfastlines(uint16_t color1, uint16_t color2) {
//   display.fillScreen(BLACK);
//   for (int16_t y=0; y < display.height()-1; y+=5) {
//     display.drawFastHLine(0, y, display.width()-1, color1);
//   }
//   for (int16_t x=0; x < display.width()-1; x+=5) {
//     display.drawFastVLine(x, 0, display.height()-1, color2);
//   }
//}
