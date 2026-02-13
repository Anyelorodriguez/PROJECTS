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

//------------------------------------------------------------------------
void setup() {

  Wire.begin();           // SCL(3) and SDA(3) by default in Tiva C.
  Wire.setModule(0);      // Changing to SCL(0)and SDA(0),(PB_2 and PB_3). 

 // analogWrite(GREEN_LED,25);        //led 10% on.
  
// Create a sine table of 360 points:
  for ( int i = 0; i <= 360; i++ ) {
    int c = sin( i * 3.141592 / 180 ) * 2047 + 2048;
    ch[ i ] = int( c / 256 );      // the 4 most significant bits.
    cl[ i ] = c - ch[ i ] * 256;   // the 8 least significant bits.
  }
}

//------------------------------------------------------------------------
void loop() {
  for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
  }
}
