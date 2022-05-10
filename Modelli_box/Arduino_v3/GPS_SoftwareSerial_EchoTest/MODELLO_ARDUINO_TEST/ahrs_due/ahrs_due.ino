#define SERIAL_BAUDRATE 38400    // baudrate della porta seriale
#define SERIAL_OPEN_DELAY 1000    // pausa di attesa dopo l'apertura delle comunicazioni seriali

uint8_t go_to_meas[5] = {250, 255, 16, 00, 241};
uint8_t sms_header[4] = {250, 255, 50, 49};
uint8_t tmp_buff[4] = {0,0,0,0};

unsigned long headers_count = 0;
unsigned long bytes_received = 0;
unsigned long header_pos_old = 0;
char str_temp[20];

unsigned long package_len = 54*50;      // 54 bytes * 50 Hz

unsigned long start_time = 0;
unsigned long elapsed_time = 0;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  delay(SERIAL_OPEN_DELAY);

  Serial3.begin(SERIAL_BAUDRATE);
  delay(SERIAL_OPEN_DELAY);
  
  Serial.print("Attendo 2 secondi...");
  delay(2000);
  Serial.println("[ OK ]");

  while (Serial3.available()<=0) {
    Serial.print("Richiedo le misure all'AHRS ... ");
    Serial3.write(go_to_meas,5);
    Serial.println("[ OK ]");
    delay(1000);
  }

  Serial.println("Entro nella void loop()");
  start_time = millis();
}

void loop() {
  //riceviSMS();            // permette di verificare la ricezione dei messaggi
  valutaMsec();         // permette di valutare quanti millisecondi impiega un pacchetto di dimensioni package_len per essere ricevuto
}


void riceviSMS() {
  
  //Serial.println(Serial3.read());

  if ( Serial3.available() > 0 ) {

    tmp_buff[3] = Serial3.read();
    bytes_received++;
    
    if (tmp_buff[0]==sms_header[0] && tmp_buff[1]==sms_header[1] && tmp_buff[2]==sms_header[2] && tmp_buff[3]==sms_header[3]){
        sprintf(str_temp,"%lu", headers_count);
        Serial.print(str_temp);
        Serial.print('-');
        sprintf(str_temp,"%lu", bytes_received-header_pos_old);
        Serial.println(str_temp);
        header_pos_old=bytes_received;
        
        headers_count++;
    }

    // shiftiamo i valori nell'array
    tmp_buff[0]=tmp_buff[1];
    tmp_buff[1]=tmp_buff[2];
    tmp_buff[2]=tmp_buff[3];
  } 

  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  // IMPORTANTE!!! -> SE SI COMMENTA IL DELAY NON SI RICEVONO DATI. SE SI UTILIZZA IL DELAY DI 1 msec SI RICEVONO I MESSAGGI MA DI 20 BYTES CIRCA DI LUNGHEZZA. CON UN DELAY DI 0 msec SI OTTENGONO 54 BYTES
  delay(0);
}

void valutaMsec() {
    
  if ( Serial3.available() > 0 ) {
    
    tmp_buff[0] = Serial3.read();  
    bytes_received++;
    
    if (bytes_received>=package_len) {
      
      elapsed_time = ((millis() - start_time));
      sprintf(str_temp,"T:%lu", elapsed_time);
      Serial.print(str_temp);
      Serial.println(" msec");
      bytes_received=0;
      start_time = millis();
    }
  }
  
}
