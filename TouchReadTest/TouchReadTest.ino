// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
}

void loop()
{
  Serial.print(touchRead(T0));
  Serial.print(" | ");
  Serial.print(touchRead(T1));
  Serial.print(" | ");
  Serial.print(touchRead(T2));
  Serial.print(" | ");
  Serial.print(touchRead(T3));
  Serial.print(" | ");
  Serial.print(touchRead(T4));
  Serial.print(" | ");
  Serial.print(touchRead(T5));
  Serial.print(" | ");
  Serial.print(touchRead(T6));
  Serial.print(" | ");
  Serial.print(touchRead(T7));
  Serial.print(" | ");
  Serial.print(touchRead(T8));
  Serial.print(" | ");
  Serial.print(touchRead(T9));
  Serial.print(" | ");
  Serial.println(" ");
  delay(1000);
}
