// constants won't change. They're used here to set pin numbers:
const int bot_dere = 2;     // the number of the pushbutton pin
const int bot_izqu = 3;
const int giro_dere =  13;      // the number of the LED pin
const int giro_izq =  12; 

// variables will change:
int buttonState = 0;   // variable for reading the pushbutton status
int buttonState1 = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(giro_dere, OUTPUT);
  pinMode(giro_izq, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(bot_dere, INPUT);
  pinMode(bot_izqu, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(bot_dere);
  buttonState1 = digitalRead(bot_izqu);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH and buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(giro_dere, HIGH);
    while(1)
      {
       buttonState1 = digitalRead(bot_izqu);
       buttonState = digitalRead(bot_dere);
      if (buttonState1 == HIGH and buttonState == LOW)
      {
        digitalWrite(giro_dere, LOW);
        digitalWrite(giro_izq, LOW);
        delay(10000);
        break;
        }
        else if (buttonState == HIGH and buttonState1 == HIGH)
       {
        digitalWrite(giro_izq, LOW);
        digitalWrite(giro_dere, LOW);
        delay(10000);
        break;
        }
      }
    
  }
  else if (buttonState1 == HIGH and buttonState == LOW)
  {
     // turn LED on:
    digitalWrite(giro_izq, HIGH);
    while(1)
      {
       buttonState1 = digitalRead(bot_izqu);
       buttonState = digitalRead(bot_dere);
      if (buttonState == HIGH and buttonState1 == LOW)
      {
        digitalWrite(giro_izq, LOW);
        digitalWrite(giro_dere, LOW);
        delay(10000);
        break;
        }
       else if (buttonState == HIGH and buttonState1 == HIGH)
       {
        digitalWrite(giro_izq, LOW);
        digitalWrite(giro_dere, LOW);
        delay(10000);
        break;
        }
      }
  }
  else if (buttonState == HIGH and buttonState1 == HIGH)
       {
        digitalWrite(giro_izq, LOW);
        digitalWrite(giro_dere, LOW);
        delay(10000);
        }
}
