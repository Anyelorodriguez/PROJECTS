int VALOR;    
int BUZZER = 13;

void setup(){
  Serial.begin(9600);   
}

void loop(){
  VALOR = analogRead(A0); 
  if (VALOR > 400);
  digitalWrite(BUZZER, LOW);
  digitalWrite(BUZZER, HIGH);
  Serial.println(VALOR);  
  delay(500);     
}
