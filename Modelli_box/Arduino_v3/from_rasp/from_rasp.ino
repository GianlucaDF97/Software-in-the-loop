void setup() {
  // put your setup code here, to run once:
  
uint8_t var[1] = { 0 };
 uint8_t fail[1]= { 0 };
Serial1.begin(115200);
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  
if (Serial1.available()){
 
  uint8_t var = Serial1.read();
  Serial.write(var);
}
//
}
