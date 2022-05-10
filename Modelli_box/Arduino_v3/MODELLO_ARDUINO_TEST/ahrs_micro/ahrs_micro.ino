uint8_t go_to_meas[5] = {250, 255, 16, 00, 241};
uint8_t sms_header[4] = {250, 255, 50, 49};

uint8_t tmp_buff[4] = {0,0,0,0};
uint8_t k = 0;
uint32_t headers_count = 0;
uint32_t bytes_received = 0;
uint32_t header_pos_old = 0;
char str_temp[20];

/*
uint32_t package_len = 54*50;      // 54 bytes * 50 Hz

unsigned long start_time = 0;
float elapsed_time = 0;
*/

void setup() {
  Serial.begin(38400);
  Serial1.begin(38400);
  Serial.print("Attendo 2 secondi...");
  delay(2000);
  Serial.println("[ OK ]");

  while (Serial1.available()<=0) {
    Serial.print("Richiedo le misure all'AHRS ... ");
    Serial1.write(go_to_meas,5);
    Serial.println("[ OK ]");
    delay(1000);
  }

  Serial.println("Entro nella void loop()");
  //start_time = micros();
}

void loop() {
  riceviSMS();
  //valutaFrequenza();
}


void riceviSMS() {

  if ( Serial1.available() > 0 ) {

    tmp_buff[k-3] = Serial1.read();
    bytes_received++;
    
    if (tmp_buff[k-3]==sms_header[0] && tmp_buff[k-2]==sms_header[1] && tmp_buff[k-1]==sms_header[2] && tmp_buff[k-0]==sms_header[3]){
        sprintf(str_temp,"%lu", headers_count);
        Serial.print(str_temp);
        Serial.print('-');
        sprintf(str_temp,"%lu", bytes_received-header_pos_old);
        Serial.println(str_temp);
        header_pos_old=bytes_received;
        
        headers_count++;
    }

    tmp_buff[k-3]==tmp_buff[k-2];
    tmp_buff[k-2]==tmp_buff[k-1];
    tmp_buff[k-1]==tmp_buff[k-0];
      
    if (k == 3){
      k = 0;
    } else {
      k++;
    }

  }  
}

/*
void valutaFrequenza() {
  
  //Serial.println(Serial3.read());
  
  if ( Serial1.available() > 0 ) {
    
    if (bytes_received==package_len) {
      
      elapsed_time = (int)((micros() - start_time) * 1e-6);
      //sprintf(str_temp,"T:%lu", elapsed_time);
      //Serial.print(str_temp);
      Serial.print(elapsed_time);
      Serial.print("s-f:");
      //dtostrf(1/elapsed_time, 7, 3, str_temp);
      //Serial.print(str_temp);
      Serial.print((int)(1/elapsed_time));
      Serial.println("Hz");
      start_time = micros();
      bytes_received==0;
            
    }
    
    bytes_received++;
  }
  
}
*/
