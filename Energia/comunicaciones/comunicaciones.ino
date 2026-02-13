/*MCP4725_Sin_01.ino   Arduining 17 APR 2015

-Energia Sketch to be used with Tiva C Launchpad and the Adafruit's MCP4725.
-I2C Fast Mode Write Command is used.
-120 samples are producing a 3.62Hz sine wave  => 434 samples/second.

Based in the code at:
http://electronics.stackexchange.com/questions/29457/how-to-make-arduino-do-high-speed-i2c
 
*/
#include <tm4c123gh6pm.h>
#include <Wire.h>
#include <math.h>

//The MCP4725 from Adafruit:
//  I2C address is 0x62 ( by default A0 has a 10k pull-down resistor ).
//  I2C address is 0x63 if A0 is connected to VCC. 
#define MCP4725_ADDR 0x60           //I2c address..

int ch[ 360 ] , cl[ 360 ];          //Arrays to load the sine wave.
int ch2[ 360 ] , cl2[ 360 ]; 
int ch3[ 360 ] , cl3[ 360 ]; 
int ch4[ 360 ] , cl4[ 360 ];
const int buttonPin1 = PUSH1; 
const int buttonPin = PUSH2;     // the number of the pushbutton pin
const int ledPin =  BLUE_LED;
int buttonState = 0; 
int bin=0;

//------------------------------------------------------------------------
void setup() {
  
  Wire.begin();           // SCL(3) and SDA(3) by default in Tiva C.
  Wire.setModule(0);      // Changing to SCL(0)and SDA(0),(PB_2 and PB_3). 
  
  //analogWrite(GREEN_LED,25);        //led 10% on.

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  
  
// Create a sine table of 360 points:
  for ( int i = 45,j = 0; i <= 405; i++,j++ ) {
    int c = sin( i * 3.141592 / 180 ) * 2047 + 2048;
    ch[ j ] = int( c / 256 );      // the 4 most significant bits.
    cl[ j ] = c - ch[ i ] * 256;   // the 8 least significant bits.
  }
  for ( int i = 135,j = 0; i <= 495; i++,j++ ) {
    int c = sin( i * 3.141592 / 180 ) * 2047 + 2048;
    ch2[ j ] = int( c / 256 );      // the 4 most significant bits.
    cl2[ j ] = (c - ch[ i ] * 256);   // the 8 least significant bits.
  }
   for ( int i = 225,j = 0; i <= 585; i++,j++ ) {
    int c = sin( i * 3.141592 / 180 ) * 2047 + 2048;
    ch3[ j ] = int( c / 256 );      // the 4 most significant bits.
    cl3[ j ] = (c - ch[ i ] * 256);   // the 8 least significant bits.
  }
  for ( int i = 315,j = 0; i <= 675; i++,j++ ) {
    int c = sin( i * 3.141592 / 180 ) * 2047 + 2048;
    ch4[ j ] = int(c / 256 );      // the 4 most significant bits.
    cl4[ j ] = (c - ch[ i ] * 256);
  }
}

//------------------------------------------------------------------------
void loop() {
  if (bin==0){
     for ( int i = 0 ; i < 360; i=i+8 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission(); 
   }
   //bin=bin+1;
  }

 
  if (bin==1){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch2[ i ] );        // the 4 most significant bits.
    Wire.write( cl2[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    
  }
  // bin+=1;
   
  }
 
  if (bin==2){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch3[ i ] );        // the 4 most significant bits.
    Wire.write( cl3[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    
  }
 // bin+=1;
  
  }
  if (bin==3){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch4[ i ] );        // the 4 most significant bits.
    Wire.write( cl4[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    
  }
  bin=0;
  
  }
  analogWrite(RED_LED,25);
}
