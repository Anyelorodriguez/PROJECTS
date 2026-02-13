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
int entrada=0;
int entrada1=0;
int entrada2=0;
int entrada3=0;
const int ledPin =  BLUE_LED;
int buttonState = 0; 
int bin=0;

//------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  Wire.begin();           // SCL(3) and SDA(3) by default in Tiva C.
  Wire.setModule(0);      // Changing to SCL(0)and SDA(0),(PB_2 and PB_3). 
  
  //analogWrite(GREEN_LED,25);        //led 10% on.

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(PB_5, INPUT);
  pinMode(PB_0, INPUT);
  pinMode(PB_1, INPUT_PULLUP);
  pinMode(PE_4, INPUT_PULLUP);
  pinMode(PE_5, INPUT_PULLUP);
  pinMode(PB_4, INPUT_PULLUP);
  pinMode(PA_5, INPUT_PULLUP);
  pinMode(PA_6, INPUT_PULLUP);
  
  
  
  
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
  //entrada-------------------------------------------------------------------
  if(digitalRead(PB_5)==0 and digitalRead(PB_0)==0){
    entrada=0;
    }
  if(digitalRead(PB_5)==1 and digitalRead(PB_0)==0){
    entrada=1;
    }
  if(digitalRead(PB_5)==0 and digitalRead(PB_0)==1){
    entrada=2;
    }
  if(digitalRead(PB_5)==1 and digitalRead(PB_0)==1){
    entrada=3;
    }
   //entrada1---------------------------------------------------------------------
  if(digitalRead(PB_1)==0 and digitalRead(PE_4)==0)
  {
    entrada1=0;
    }
  if(digitalRead(PB_1)==1 and digitalRead(PE_4)==0)
  {
    entrada1=1;
    }
  if(digitalRead(PB_1)==0 and digitalRead(PE_4)==1)
  {
    entrada1=2;
    }
  if(digitalRead(PB_1)==1 and digitalRead(PE_4)==1)
  {
    entrada1=3;
    }
   //entrada2-----------------------------------------------------------
   if(digitalRead(PE_5)==0 and digitalRead(PB_4)==0)
   {
    entrada2=0;
    }
   if(digitalRead(PE_5)==1 and digitalRead(PB_4)==0)
   {
    entrada2=1;
    }
   if(digitalRead(PE_5)==0 and digitalRead(PB_4)==1)
   {
    entrada2=2;
    }
   if(digitalRead(PE_5)==1 and digitalRead(PB_4)==1)
   {
    entrada2=3;
    }
   //entrada3-----------------------------------------------------------
    if (digitalRead(PA_5)==0 and digitalRead(PA_6)==0)
    {
      entrada3=0;
      }
    if (digitalRead(PA_5)==1 and digitalRead(PA_6)==0)
    {
      entrada3=1;
      }
     if (digitalRead(PA_5)==0 and digitalRead(PA_6)==1)
    {
      entrada3=2;
      }
      if (digitalRead(PA_5)==1 and digitalRead(PA_6)==1)
    {
      entrada3=3;
      }
  //--------------------------------------------------------------------------------------------------------------------salida0
  if (bin==0){
    if(entrada==0){
      for ( int i = 0 ; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission(); 
    }
    }
    if((entrada==1))
    {
      for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
      Wire.beginTransmission(MCP4725_ADDR);
      //Fast Mode Write Command.
      Wire.write( ch2[ i ] );        // the 4 most significant bits.
      Wire.write( cl2[ i ] );        // the 8 least significant bits.
      Wire.endTransmission();
      }
    }
    if (entrada==2){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch3[ i ] );        // the 4 most significant bits.
    Wire.write( cl3[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    }
    }
    
   if (entrada==3){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch4[ i ] );        // the 4 most significant bits.
    Wire.write( cl4[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
      }
    }
    bin=bin+1;   
}
//------------------------------------------------------------------------------------------------------------------saida 1
  if (bin==1){
    if(entrada1==0){
      for ( int i = 0 ; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission(); 
    }
    }
    if((entrada1==1))
    {
      for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
      Wire.beginTransmission(MCP4725_ADDR);
      //Fast Mode Write Command.
      Wire.write( ch2[ i ] );        // the 4 most significant bits.
      Wire.write( cl2[ i ] );        // the 8 least significant bits.
      Wire.endTransmission();
      }
    }
    if (entrada1==2){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch3[ i ] );        // the 4 most significant bits.
    Wire.write( cl3[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    }
    }
    
   if (entrada1==3){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch4[ i ] );        // the 4 most significant bits.
    Wire.write( cl4[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
      }
    }
    bin=bin+1;   
}
//----------------------------------------------------------------------------------------------------------------------------------------------------salida2
  if (bin==2){
    if(entrada2==0){
      for ( int i = 0 ; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission(); 
    }
    }
    if((entrada2==1))
    {
      for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
      Wire.beginTransmission(MCP4725_ADDR);
      //Fast Mode Write Command.
      Wire.write( ch2[ i ] );        // the 4 most significant bits.
      Wire.write( cl2[ i ] );        // the 8 least significant bits.
      Wire.endTransmission();
      }
    }
    if (entrada2==2){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch3[ i ] );        // the 4 most significant bits.
    Wire.write( cl3[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    }
    }
    
   if (entrada2==3){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch4[ i ] );        // the 4 most significant bits.
    Wire.write( cl4[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
      }
    }
    bin=bin+1;   
}
//----------------------------------------------------------------------------------------------------------------------------------------------------salida 3
  if (bin==3){
    if(entrada3==0){
      for ( int i = 0 ; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch[ i ] );        // the 4 most significant bits.
    Wire.write( cl[ i ] );        // the 8 least significant bits.
    Wire.endTransmission(); 
    }
    }
    if((entrada3==1))
    {
      for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
      Wire.beginTransmission(MCP4725_ADDR);
      //Fast Mode Write Command.
      Wire.write( ch2[ i ] );        // the 4 most significant bits.
      Wire.write( cl2[ i ] );        // the 8 least significant bits.
      Wire.endTransmission();
      }
    }
    if (entrada3==2){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch3[ i ] );        // the 4 most significant bits.
    Wire.write( cl3[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
    }
    }
    
   if (entrada3==3){
     for ( int i = 0; i < 360; i=i+3 ) {     //Only 120 points are used.
    Wire.beginTransmission(MCP4725_ADDR);
    //Fast Mode Write Command.
    Wire.write( ch4[ i ] );        // the 4 most significant bits.
    Wire.write( cl4[ i ] );        // the 8 least significant bits.
    Wire.endTransmission();
      }
    }
    bin=0;   
}
Serial.print(entrada);
Serial.print(entrada1);
Serial.print(entrada2);
Serial.println(entrada3);
 
}
