void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial2.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.write(Serial2.read());

}
