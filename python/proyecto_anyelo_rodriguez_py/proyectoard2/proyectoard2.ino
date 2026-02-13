String dataString = "";
bool dataComplete = false;
int data = 0;
int led = 12;

void setup() {
 pinMode(led, OUTPUT);
 Serial.begin(9600);
}
void loop() {
  Serial.println("hola");
  if (dataComplete) {
    data = dataString.toInt();

    task();

    dataString = "";
    dataComplete = false;
  }
}

 void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    dataString += inChar;
    if (inChar == '\n') {
      dataComplete = true;
    }
  }
}

void task(){
  if(data==30){
    digitalWrite(led,HIGH); 
    delay(5000);
    
    
    digitalWrite(led,LOW); 

  
  }else{
    digitalWrite(led,LOW); 
  }
  
}
