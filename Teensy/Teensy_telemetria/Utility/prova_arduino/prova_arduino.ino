#include <stdint.h>

#include <Wire.h>

//#include <LIDARLite_v3HP.h>

//LIDARLite_v3HP myLidar; //for I2C comm

#define FAST_I2C

int analogPin_pitot = A5; //A15 era quello che ci stava prima
double offset = 0;
double offset_size = 500;

void setup() {

  Serial1.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
  //Wire.begin(0x02);
  //lidar
  //#ifdef FAST_I2C
  //#if ARDUINO >= 157
  //Wire.setClock(400000UL); // Set I2C frequency to 400kHz (for Arduino Due)
  //#else
  //TWBR = ((F_CPU / 400000UL) - 16) / 2; // Set I2C frequency to 400kHz
  //#endif
  //#endif

  //pitot

  for (int ii = 0; ii < offset_size; ii++) {
    offset += analogRead(analogPin_pitot) - 512;
  }
  offset /= offset_size;

  //lidar
//  myLidar.configure(2);
  /*
     configuration:  Default 0.
      0: Default mode, balanced performance.
      1: Short range, high speed. Uses 0x1d maximum acquisition count.
      2: Default range, higher speed short range. Turns on quick termination
          detection for faster measurements at short range (with decreased
          accuracy)
      3: Maximum range. Uses 0xff maximum acquisition count.
      4: High sensitivity detection. Overrides default valid measurement detection
          algorithm, and uses a threshold value for high sensitivity and noise.
      5: Low sensitivity detection. Overrides default valid measurement detection
          algorithm, and uses a threshold value for low sensitivity and noise.
    lidarliteAddress: Default 0x62. Fill in new address here if changed. See
      operating manual for instructions.
  */
}

void loop() {
 
//int val = 0;
int32_t dP = 0;

//pitot
double V_0 = 5.0; // supply voltage to the pressure sensor
double rho = 1.204; // density of air  
double Pmin = -1244.2;
double Pmax = 1244.2;
double costante = (Pmax - Pmin) / (0.8*V_0); //+ Pmin; //introdotta per fare meno calcoli nelle formule


double adc_avg = 0;
double dp = 0;
double veloc_mean_size = 1000.0;
  //lidar

  uint16_t distance;
  uint8_t newDistance = 0;
  uint8_t Hdist = 0;
  uint8_t Ldist = 0;
  uint8_t HHP = 0; //servono per spacchettare la pressione per poterla inviare
  uint8_t HhP = 0;
  uint8_t LlP = 0;
  uint8_t LLP = 0;

  // pitot
  double velocity = 0;
  uint16_t VELOCITY=0;
  uint8_t Lvelocity = 0; //servono per spacchettare la velocità per poterla inviare
  uint8_t Hvelocity = 0;
int onebyte=0;
  
  // Continuous loop
  

        
   while (1) {

    //pitot
    // average a few ADC readings for stability

    for (int ii = 0; ii < veloc_mean_size; ii++) {
      adc_avg += analogRead(analogPin_pitot) - offset;
    }
    adc_avg /= veloc_mean_size;
    dp=((((5*adc_avg/1024)-0.5)*costante)+Pmin);
    if (adc_avg >= 512) {
      velocity = sqrt(2 * dp / rho);
    } else {
      velocity = -sqrt(-2 * dp / rho);
    }
    
    VELOCITY=(uint16_t)(velocity*100);
    Hvelocity = (uint8_t)(VELOCITY >> 8); // ho due byte con questo shifto tutto a destra e cosi prendo il secondo byte
    Lvelocity = (uint8_t)(VELOCITY & 0x00ff); // è un filtro che corrisponde a 0000 0000 1111 1111 gli zeri rendono 0 il corrispettivo bit gli 1 fanno si che il corrispettivo biut si mantenga,
                                              // cosi riesco ad ottenere solo il primo byte perche gli zeri annullano il secondo (sto legendo i byte da destra a sinistra

    dP = (uint32_t)(dp*100);
    
    HHP = (uint8_t)(dP >> 24);
    HhP = (uint8_t)(dP >> 16);
    LlP = (uint8_t)(dP >> 8);
    LLP = (uint8_t)(dP & 0xff);

Serial.println(Serial1.available());
        if(Serial1.available()>0){
        int onebyte=Serial1.read();
        Serial.print("onebyte:");
        Serial.println(onebyte);
        if (onebyte==104){
        
            Serial1.write(254);
            Serial1.write(255);
            Serial1.write(Hvelocity);
            Serial1.write(Lvelocity);
            Serial1.write(Hdist);
            Serial1.write(Ldist);
            Serial1.write(HHP);
            Serial1.write(HhP);
            Serial1.write(LlP);
            Serial1.write(LLP);
       
   
   
  Serial.print("dp:");
    Serial.println(dp);
   Serial.print("velocity:");
    Serial.println(velocity);
    Serial.println(VELOCITY, BIN);
    Serial.println(254, BIN);
    Serial.println(255, BIN);
    Serial.print("Hvelocity:");
    Serial.println(Hvelocity, BIN);
    Serial.print("Lvelocity:");
    Serial.println(Lvelocity, BIN);
    Serial.print("Hdist:");
    Serial.println(Hdist, BIN);
    Serial.print("Ldist:");
    Serial.println(Ldist, BIN);
    Serial.print("HHP:");
    Serial.println(HHP, BIN);
    Serial.print("HhP:");
    Serial.println(HhP, BIN);
    Serial.print("LlP:");
    Serial.println(LlP, BIN);
    Serial.print("LLP:");
    Serial.println(LLP, BIN);
    Serial.println(" ");
   }
   }
   }
   }
          
    //lidar
    //val = analogRead(analogPin_pitot);
    //dP = (int32_t)((((((5*(double)(val))/1024)-0.5)*((1245.445*2)/(0.8*5)))-1245.445)*100);

    //newDistance = distanceSingle( & distance);
    
 
