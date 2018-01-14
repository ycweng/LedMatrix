//We always have to include the library
#include "LedControl.h"
#include "SoftwareSerial.h"
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  Serial.begin(9600);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a1[8]={B01100000,B01100000,B00110000,B00101000,B11010100,B00101000,B01000100,B10000010};
  byte a2[8]={B01100000,B01100000,B00110000,B00101000,B01011000,B00110000,B01001000,B01000100};
  byte a3[8]={B01100000,B01100000,B00110000,B00100000,B01010000,B00110000,B00100000,B00110000};
  byte clean[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte a[8]={B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
  byte b[8]={B00000000,B01111100,B01100110,B01100110,B01111100,B01100110,B01100110,B01111100};
  byte c[8]={B00000000,B00111100,B01100110,B01100000,B01100000,B01100000,B01100110,B00111100};
  byte d[8]={B00000000,B01111100,B01100110,B01100110,B01100110,B01100110,B01100110,B01111100};
  byte e[8]={B00000000,B01111110,B01100000,B01100000,B01111100,B01100000,B01100000,B01111110};
  byte f[8]={B00000000,B01111110,B01100000,B01100000,B01111100,B01100000,B01100000,B01100000};
  byte g[8]={B00000000,B00111100,B01100110,B01100000,B01100000,B01101110,B01100110,B00111100};
  byte h[8]={B00000000,B01100110,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
  byte i[8]={B00000000,B00111100,B00011000,B00011000,B00011000,B00011000,B00011000,B00111100};
  byte j[8]={B00000000,B00011110,B00001100,B00001100,B00001100,B01101100,B01101100,B00111000};
  byte k[8]={B00000000,B01100110,B01101100,B01111000,B01110000,B01111000,B01101100,B01100110};
  byte l[8]={B00000000,B01100000,B01100000,B01100000,B01100000,B01100000,B01100000,B01111110};
  byte m[8]={B00000000,B01100011,B01110111,B01111111,B01101011,B01100011,B01100011,B01100011};
  byte n[8]={B00000000,B01100011,B01110011,B01111011,B01101111,B01100111,B01100011,B01100011};
  byte o[8]={B00000000,B00111100,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100};
  byte p[8]={B00000000,B01111100,B01100110,B01100110,B01100110,B01111100,B01100000,B01100000};
  byte q[8]={B00000000,B00111100,B01100110,B01100110,B01100110,B01101110,B00111100,B00000110};
  byte r[8]={B00000000,B01111100,B01100110,B01100110,B01111100,B01111000,B01101100,B01100110};
  byte s[8]={B00000000,B00111100,B01100110,B01100000,B00111100,B00000110,B01100110,B00111100};
  byte t[8]={B00000000,B01111110,B01011010,B00011000,B00011000,B00011000,B00011000,B00011000};
  byte u[8]={B00000000,B01100110,B01100110,B01100110,B01100110,B01100110,B01100110,B00111110};
  byte v[8]={B00000000,B01100110,B01100110,B01100110,B01100110,B01100110,B00111100,B00011000};
  byte w[8]={B00000000,B01100011,B01100011,B01100011,B01101011,B01111111,B01110111,B01100011};
  byte x[8]={B00000000,B01100011,B01100011,B00110110,B00011100,B00110110,B01100011,B01100011};
  byte y[8]={B00000000,B01100110,B01100110,B01100110,B00111100,B00011000,B00011000,B00011000};
  byte z[8]={B00000000,B01111110,B00000110,B00001100,B00011000,B00110000,B01100000,B01111110};
  
  int row= 0;

//listen to 9600port 
int insize;
char cmmd[20];
if((insize=Serial.available()>0))
{
  for(int j =0;j<insize; j++)
    cmmd[j] = Serial.read();
  switch(cmmd[0])
  {
    case 'a':
        for(row = 0;row<8;row++)
        {
        lc.setRow(0,row,a1[row]);
        }
        delay(delaytime);
        for(row = 0;row<8;row++)
        {
        lc.setRow(0,row,a2[row]);
        }
      break;
    case 'b':
        for(row = 0;row<8;row++)
        {
         
        lc.setRow(0,row,x[row]);
        }
      break;
    case 's':
        for(row = 0;row<8;row++)
        {
        lc.setRow(0,row,clean[row]);
        }
      break;
  
  }
}
  
  /*
  for(row = 0;row<8;row++)
  {
  lc.setRow(0,row,a1[row]);
  Serial.println("test");
  }
  delay(delaytime);
  
  for(row = 0;row<8;row++)
  {
  lc.setRow(0,row,a2[row]);
  }
  delay(delaytime); */
}



void loop() { 
  writeArduinoOnMatrix();
 
}
