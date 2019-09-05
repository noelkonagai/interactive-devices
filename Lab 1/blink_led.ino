void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("high \n");
  delay(30);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("low \n");
  delay(30);

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("high \n");
  delay(30);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("low \n");
  delay(30);

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("high \n");
  delay(30);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("low \n");
  delay(500);
}
