void setup()
{
  Serial.begin (9600);
  pinMode (A0, INPUT);
  // put your setup code here, to run once:

}

void loop() 
{
  int valor=digitalRead(A0);
  Serial.println(valor);
  delay(200);
  // put your main code here, to run repeatedly:

}
