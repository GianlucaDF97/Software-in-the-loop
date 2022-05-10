void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
Serial3.begin(115200);
uint8_t req_data[5] = {250, 01, 52, 00, 203};
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t req_data[5] = {250, 01, 52, 00, 203};
  for ( int i = 0; i<5; i++){
    Serial3.write(req_data[i]);
  }
  if (Serial3.available()){
    for ( int j = 0; j<41; j++){
        Serial.println(Serial3.read());
    }
  }
     
//  Serial2.println("sono stufo+");
//  Serial.println("A");
}
