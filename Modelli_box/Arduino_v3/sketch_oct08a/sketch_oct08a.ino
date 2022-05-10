int messaggio[32] = {0} ;
void setup() {
  // put your setup code here, to run once:
Serial1.begin(9600);
Serial.begin(9600);
//int messaggio[32] = {0} ;
}

void loop() {
  // put your main code here, to run repeatedly:

for ( int i = 0; i<32; i++){
  int messaggio[i] = Serial1.read();
  Serial.write(messaggio[i]);
}
}
